#include "manualcontrol.h"

ManualControl::ManualControl():
    id(0),
    device_n(0),
    max_velocity(0)
{
}
ManualControl::ManualControl(int _id, int _device_n, int _velocity):
    id(_id),
    device_n(_device_n),
    max_velocity(_velocity)
{
    velocity = Mat_<float>(3, 1);
    velocity_wheels = Mat_<float>(4, 1);
    axis = Mat_<int>(2, 0);
    initKinematicModel();
}

void ManualControl::run()
{
    joystick = new Joystick(device_n);
    bool button_send = false;
    bool axis_send = false;
    if(!joystick->isFound()){
        cout<<"Falha ao abrir o controle."<<endl;
    }

    while(1){
        if(joystick->sample(event)){
            if(event->isButton()){
                button_send = readEventButton(*event);
            }

            if(event->isAxis()){
                readEventAxis(*event);
            }
        }

        if(axis_send = verifyAxis()) calculateVelocity();
        else {
            velocity[0][0] = 0.0;
            velocity[1][0] = 0.0;
        }

        if(axis_send || button_send){
            calculateWheelsVelocity();
            //manda o dado
        }

        sleep(20);
    }
}

void ManualControl::setMaxVelocity(int _velocity)
{
    max_velocity = _velocity;
}

//Métodos do controle
bool ManualControl::readEventButton(JoystickEvent _event)
{
    switch(_event.number){
    case 0:
        //low kick
    break;
    case 1:
        //high kick
    break;
    case 2:
        //low kick
    break;
    case 3:
        //low kick
    break;
    case 4:
        //drible h
    break;
    case 5:
        //drible a-h
    break;
    case 6:
        //gira h
    break;
    case 7:
        //gira a-h
    break;
    default:
        return false;
    }

    return true;
}
void ManualControl::readEventAxis(JoystickEvent _event)
{
    if(_event.number<2)
        axis[_event.number][0] = _event.value;
}
bool ManualControl::verifyAxis()
{
    for(int i = 0 ; i<2 ; i++)
        if(axis[i][0]>=MIN_AXIS_VALUE || axis[i][0]<=-(MIN_AXIS_VALUE)) return true;
    return false;
}

//Métodos cinemáticos
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
    axis[1][0] = -axis[1][0];

    for(int i = 0 ; i<2 ; i++)
        velocity[i][0] = ((float)axis[i][0]/MAX_AXIS_VALUE)*max_velocity;
}
void ManualControl::calculateWheelsVelocity()
{
    velocity_wheels = M*velocity;
}
