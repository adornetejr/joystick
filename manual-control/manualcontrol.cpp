#include "manualcontrol.h"

ManualControl::ManualControl()
{

}
ManualControl::ManualControl(int _id, string _device, int _velocity):
    id(_id),
    device(_device),
    max_velocity(_velocity)
{
    velocity = Mat_<float>(3, 1);
    velocity_wheels = Mat_<float>(4, 1);
    axis = Mat_<float>(4, 1);
    initKinematicModel();
}

void ManualControl::run()
{
    joystick = new Joystick(device);
    if(!joystick->isFound()){
        cout<<"Falha ao abrir o controle."<<endl;
    }

    while(1){

        if(joystick->sample(&event)){

        }
    }
}

void ManualControl::setMaxVelocity(int _velocity)
{
    max_velocity = _velocity;
}


void ManualControl::initKinematicModel(){
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
