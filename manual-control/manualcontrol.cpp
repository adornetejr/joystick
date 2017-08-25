#include "manualcontrol.h"

ManualControl::ManualControl(int _device_n):
    id(0),
    device_n(_device_n),
    max_velocity(0),
    done(false),
    rotating(false)
{
    joystick = new Joystick(_device_n);

    velocity = Mat_<float>(3, 1);
    velocity_wheels = Mat_<float>(4, 1);
    axis = vector<short>(2, 0);
    initKinematicModel();
}

void ManualControl::start(){
    done = false;
    t = thread(&ManualControl::run, this);
}
void ManualControl::stop(){
    done = true;
    if(t.joinable()) t.join();
}
void ManualControl::run()
{
    message.setId(id);
    bool button_send = false;
    bool axis_send = false;
    if(!joystick->isFound()){
        cout<<"Falha ao abrir o controle."<<endl;
    }
    int k = 0;
    while(!done){
        cout<<k++<<endl;
        if(joystick->sample(&event)){
            if(event.isButton()){
                button_send = readEventButton();
            }

            if(event.isAxis()){
                readEventAxis();
            }
        }

        if(axis_send = verifyAxis()) calculateVelocity();
        else {
            velocity[0][0] = 0.0;
            velocity[1][0] = 0.0;
        }

        calculateWheelsVelocity();
        if(axis_send || button_send || rotating){
            calculateWheelsVelocity();
        }
    }
}

//Setters
void ManualControl::setMaxVelocity(int _velocity)
{
    max_velocity = _velocity;
}
void ManualControl::setId(int _id)
{
    id = _id;
}

//Métodos do controle
bool ManualControl::readEventButton()
{
    switch(event.number){
    case 0:
        if(event.value){
            message.setKick(true, LOW, 100);
        }
        else{
            message.setKick(false, LOW, 0);
        }
        //low kick
    break;
    case 1:
        if(event.value){
            message.setKick(true, HIGH, 100);
        }
        else{
            message.setKick(false, LOW, 0);
        }
        //high kick
    break;
    case 2:
        if(event.value){
            message.setKick(true, LOW, 100);
        }
        else{
            message.setKick(false, LOW, 0);
        }
        //low kick
    break;
    case 3:
        if(event.value){
            message.setKick(true, LOW, 100);
        }
        else{
            message.setKick(false, LOW, 0);
        }
        //low kick
    break;
    case 4:
        if(event.value){
            message.setDribbler(true, 60, CLOCKWISE);
        }
        else{
            message.setDribbler(false, 0, CLOCKWISE);
        }
        rotating = event.value;
        //drible h
    break;
    case 5:
        if(event.value){
            message.setDribbler(true, 60, COUNTERCLOCKWISE);
        }
        else{
            message.setDribbler(false, 0, CLOCKWISE);
        }
        rotating = event.value;
        //drible a-h
    break;
    case 6:
        if(event.value){
            velocity[2][0] = -(max_velocity/100.0);
        }
        else{
            velocity[2][0] = 0.0;
        }
        rotating = event.value;
        //gira h
    break;
    case 7:
        if(event.value){
            velocity[2][0] = (max_velocity/100.0);
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

    return true;
}
void ManualControl::readEventAxis()
{
    if(event.number == 0) axis[event.number] = event.value;
    else if(event.number == 1) axis[event.number] = -(event.value);
}
bool ManualControl::verifyAxis()
{
    for(int i = 0 ; i<2 ; i++)
        if(axis[i]>=MIN_AXIS || axis[i]<=-(MIN_AXIS)) return true;
    return false;
}

//Métodos físicos
void ManualControl::initKinematicModel()
{
    //! Estas medidas estão em metros.

    /// O raio da roda é utilizado para determinar as velocidades das rodas e o raio do robo
    /// para se obter a velocidade angular do robo
    float radius_wheels = 0.0275;
    float radius_robot = 0.0825;


    //--------MODELO CINEMÁTICO DO ROBO-----------
    float alpha1, alpha2;

    //angulos de ataque das rodas
    alpha1 = 45.0*M_PI/180.0;   //45°
    alpha2 = 37.0*M_PI/180.0;   //37°

    //inicializa a matriz M
    /// Aqui é quando inicializamos a matriz M especificado utilizando os valores do robo
    M = cv::Mat_<float>(4,3);
    M[0][0] = -cos(alpha1);     M[0][1] = sin(alpha1);     M[0][2] = -radius_robot;
    M[1][0] = -cos(alpha2);     M[1][1] = -sin(alpha2);    M[1][2] = -radius_robot;
    M[2][0] =  cos(alpha2);     M[2][1] = -sin(alpha2);    M[2][2] = -radius_robot;
    M[3][0] =  cos(alpha1);     M[3][1] = sin(alpha1);     M[3][2] = -radius_robot;

    M = (1.0/radius_wheels) * M;
}
void ManualControl::calculateVelocity()
{
    for(int i = 0 ; i<2 ; i++){
        velocity[i][0] = ((float)axis[i]/MAX_AXIS)*(max_velocity/100.0);
    }
}
void ManualControl::calculateWheelsVelocity()
{
    velocity_wheels = M*velocity;

    //Considerando 100 como a velocidade maxima, o percentual é o proprio valor passado para uchar
    unsigned char percentual_velocity;
    Direction direction;
    for(int i = 0 ; i<4 ; i++){
        percentual_velocity = (unsigned char)velocity_wheels[i][0];
        cout<<i<<": "<<percentual_velocity<<endl;
        direction = percentual_velocity>0 ? COUNTERCLOCKWISE : CLOCKWISE;
        message.setWheel(i, percentual_velocity, direction);
    }
}
