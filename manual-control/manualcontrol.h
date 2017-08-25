#ifndef MANUALCONTROL_H
#define MANUALCONTROL_H
#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include <opencv/cv.h>

#include "joystick.hh"

#include "ai2robotmessage.h"

#define MIN_AXIS 5000
#define MAX_AXIS 32767

using namespace std;
using namespace cv;

class ManualControl
{
private:
    thread t;
    bool done;

    int id;

    int device_n;
    Joystick *joystick;
    JoystickEvent event;

    int max_velocity;
    Mat_<float> velocity;
    Mat_<float> M;
    Mat_<float> velocity_wheels;
    Mat_<Direction> direction_wheels;
    bool rotating;

    vector<short> axis;

    Ai2RobotMessage message;

    void initKinematicModel();
    void calculateVelocity();
    void calculateWheelsVelocity();

    bool readEventButton();
    void readEventAxis();
    bool verifyAxis();

    void run();

public:
    ManualControl(int _device_n);

    void start();
    void stop();

    void setId(int _id);
    void setMaxVelocity(int _velocity);
};

#endif // MANUALCONTROL_H
