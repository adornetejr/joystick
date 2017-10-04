#include "manualcontrol.h"
ManualControl::ManualControl(): device_n(-1), max_velocity(0), max_ang_velocity(0), running(false), rotating(false), dribbling(false),
    kicking(0), serial(), bonus_velocity(0)
{
    velocity = Mat_<float>(3, 1);
    velocity_wheels = Mat_<float>(4, 1);
    axis = vector<short>(2, 0);
    robot_angle = M_PI/2.0;
    initKinematicModel();
}
ManualControl::ManualControl(int _device_n, SerialCommunicator<Ai2RobotMessage> *_serial): device_n(_device_n),
    max_velocity(0), max_ang_velocity(0), running(false), rotating(false), dribbling(false), kicking(0), serial(_serial), bonus_velocity(0)
{
    joystick = new Joystick(_device_n);

    velocity = Mat_<float>(3, 1);
    velocity_wheels = Mat_<float>(4, 1);
    axis = vector<short>(2, 0);
    robot_angle = M_PI/2.0;
    initKinematicModel();
}

ManualControl::~ManualControl()
{
    this->stop();
}

void ManualControl::start(){
    running = true;
    td = thread(&ManualControl::run, this);
}
void ManualControl::stop(){
    {
        lock_guard<mutex> lock(mu);
        running = false;
    }
    td.join();
}
void ManualControl::run()
{
    bool button_send = false;
    bool axis_send = false;
    if(!joystick->isFound()){
        cout<<"Falha ao abrir o controle."<<endl;
    }

    while(running){
        if(joystick->sample(&event)){
            if(event.isButton()){
                button_send = readEventButton();
            }
            else button_send = false;

            if(event.isAxis()){
                readEventAxis();
            }
        }
        else{
            button_send = false;
        }

        axis_send = verifyVelocityAxis();

        if(kicking>=KICK_TIMES){
            kicking = 0;
            message.setKick(false, LOW, 0);
            button_send = true; //manda mais um dado setando o chute para 0 (bug no código arduino do robô)
        }

        if(axis_send) calculateVelocity();
        else {
            velocity[0][0] = 0.0;
            velocity[1][0] = 0.0;
        }

        if(axis_send || rotating || button_send || dribbling || kicking){
            cout<<"Mensagem adcionada: "<<endl;
            cout<<message<<endl;
            calculateWheelsVelocity();
            serial->write(message);
        }

        if(kicking) ++kicking;
    }
    message.clear();
}

//Setters
void ManualControl::setMaxVelocity(float _velocity)
{
    max_velocity = _velocity;
}
void ManualControl::setMaxAngularVelocity(float _velocity)
{
    max_ang_velocity = _velocity;
}
void ManualControl::setId(int _id)
{
    message.setId(_id);
}
void ManualControl::setDribblerVelocity(int _velocity)
{
    dribbler_velocity = _velocity;
}
void ManualControl::setKickPower(int _power)
{
    kick_power = _power;
}
void ManualControl::setPassPower(int _power)
{
    pass_power = _power;
}

//Métodos do controle
bool ManualControl::readEventButton()
{
    switch(event.number){
    case 0:
        if(event.value){
            message.setKick(true, LOW, pass_power);
            kicking = 1;
        }
        //low kick
    break;
    case 1:
        if(event.value){
            message.setKick(true, HIGH, kick_power);
            kicking = 1;
        }
        //high kick
    break;
    case 2:
        if(event.value){
            message.setKick(true, LOW, kick_power);
            kicking = 1;
        }
        //low kick
    break;
    case 3:
        if(event.value){
            message.setKick(true, LOW, kick_power);
            kicking = 1;
        }
        //low kick
    break;
    case 4:
        if(event.value){
            message.setDribbler(true, dribbler_velocity, COUNTERCLOCKWISE);
        }
        else{
            message.setDribbler(false, 0, COUNTERCLOCKWISE);
        }
        dribbling = event.value;
        //drible h
    break;
    case 5:
        if(event.value){
            bonus_velocity =  1.0;
        }
        else{
            bonus_velocity = 0;
        }
        //drible a-h
    break;
    case 6:
        if(event.value){
            velocity[2][0] = max_ang_velocity;
        }
        else{
            velocity[2][0] = 0.0;
        }
        rotating = event.value;
        //gira h
    break;
    case 7:
        if(event.value){
            velocity[2][0] = -max_ang_velocity;
        }
        else{
            velocity[2][0] = 0.0;
        }
        rotating = event.value;
        //gira a-h
    break;
    default:
        return false;
    }

    return event.value;
}
void ManualControl::readEventAxis()
{
    if(event.number<axis.size()) axis[event.number] = event.value;
}
bool ManualControl::verifyVelocityAxis()
{
    for(int i = 0 ; i<2 ; i++)
        if(abs(axis[i]) >= MIN_AXIS) return true;
    return false;
}

//Métodos físicos
void ManualControl::initKinematicModel()
{
    /*O raio da roda é utilizado para determinar as velocidades das rodas e o raio do robo
      para se obter a velocidade angular do robo*/
    float radius_wheels = 0.0275;
    float radius_robot = 0.0825;

    ///--------MODELO CINEMÁTICO DO ROBO-----------
    float alpha1, alpha2;

    alpha1 = 45.0*M_PI/180.0; //45°
    alpha2 = 37.0*M_PI/180.0; //37°

    R = Mat_<float>::eye(3,3);
    /// Aqui é quando inicializamos a matriz M especificado utilizando os valores do robo
    M = Mat_<float>(4,3);
    M[0][0] = -cos(alpha1);     M[0][1] = sin(alpha1);     M[0][2] = -radius_robot;
    M[1][0] = -cos(alpha2);     M[1][1] = -sin(alpha2);    M[1][2] = -radius_robot;
    M[2][0] =  cos(alpha2);     M[2][1] = -sin(alpha2);    M[2][2] = -radius_robot;
    M[3][0] =  cos(alpha1);     M[3][1] = sin(alpha1);     M[3][2] = -radius_robot;

    M = (1.0/radius_wheels) * M;
}
void ManualControl::calculateVelocity()
{
    velocity[0][0] = ((float)axis[0]/MAX_AXIS)*(max_velocity + bonus_velocity);
    velocity[1][0] = ((float)-axis[1]/MAX_AXIS)*(max_velocity + bonus_velocity); //leitura do analogico y é invertida
}
void ManualControl::calculateWheelsVelocity()
{
    /*Rotação para o modelo cinemático, porque ele é feito considerando o (x, y) do campo
      e não do robô, onde a frente seria o y(+)*/
    R[0][0] = cos(robot_angle);  R[0][1] = sin(robot_angle);
    R[1][0] = -sin(robot_angle); R[1][1] = cos(robot_angle);

    velocity_wheels = M*R*velocity;

    unsigned char percentual_velocity;
    Direction direction;
    for(int i = 0 ; i<4 ; i++){
        percentual_velocity = (unsigned char)fabs(velocity_wheels[i][0]);
        percentual_velocity = percentual_velocity>127 ? 127 : percentual_velocity;
        direction = velocity_wheels[i][0]>0 ? COUNTERCLOCKWISE : CLOCKWISE;
        message.setWheel(i, percentual_velocity, direction);
    }
}
