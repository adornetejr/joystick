#ifndef MANUALCONTROL_H
#define MANUALCONTROL_H
#include <iostream>
#include <string>

#include <QThread>

#include <opencv/cv.h>

#include "joystick.hh"
using namespace std;
using namespace cv;

class ManualControl: public QThread
{
private:
    int id;

    string device;
    Joystick *joystick;
    JoystickEvent event;

    int max_velocity;
    Mat_<float> velocity;
    Mat_<float> M;
    Mat_<float> velocity_wheels;

    Mat_<int> axis;

    void initKinematicModel();
    void calculateVelocity();
    void calculateWheelsVelocity();

public:
    ManualControl();
    ManualControl(int _id, string _device, int _velocity);

    void run();

    void setMaxVelocity(int _velocity);
};

#endif // MANUALCONTROL_H
