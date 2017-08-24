#include "manualcontrol.h"

bool rotating;

ManualControl::ManualControl(int _device_n):
    id(0),
    device_n(_device_n),
    max_velocity(0)
{
    joystick = new Joystick(_device_n);

    velocity = Mat_<float>(3, 1);
    velocity_wheels = Mat_<float>(4, 1);
    axis = vector<short>(2, 0);
    initKinematicModel();
}

void ManualControl::run()
{
    bool button_send = false;
    bool axis_send = false;
    if(!joystick->isFound()){
        cout<<"Falha ao abrir o controle."<<endl;
    }
    while(1){
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
    for(int i = 0 ; i<2 ; i++){
        velocity[i][0] = ((float)axis[i]/MAX_AXIS)*(max_velocity/100.0);
    }
}
void ManualControl::calculateWheelsVelocity()
{
    velocity_wheels = M*velocity;
    cout<<"1: "<<velocity_wheels[0][0]<<endl;
    cout<<"2: "<<velocity_wheels[1][0]<<endl;
    cout<<"3: "<<velocity_wheels[2][0]<<endl;
    cout<<"4: "<<velocity_wheels[3][0]<<endl;


}
