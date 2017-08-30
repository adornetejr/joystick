#ifndef MANUALCONTROL_H
#define MANUALCONTROL_H
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <cstdio>

#include <opencv/cv.h>

#include "joystick.hh"

#include "ai2robotmessage.h"
#include "serialcommunicator.h"

#define MIN_AXIS 10000
#define MAX_AXIS 32767
#define KICK_TIMES 10

using namespace std;
using namespace cv;

class ManualControl
{
private:
    bool running;
    thread td;
    mutex mu;

    int device_n;
    Joystick *joystick;
    JoystickEvent event;
    vector<short> axis;

    float max_velocity;
    float max_ang_velocity;
    int dribbler_velocity;
    int kick_power;
    int pass_power;
    Mat_<float> velocity;
    Mat_<float> M;
    Mat_<float> R;
    float robot_angle;
    Mat_<float> velocity_wheels;
    Mat_<Direction> direction_wheels;
    bool rotating;
    bool dribbling;
    int kicking;

    Ai2RobotMessage message;
    SerialCommunicator<Ai2RobotMessage> *serial;

    void initKinematicModel();
    void calculateVelocity();
    void calculateWheelsVelocity();

    bool readEventButton();
    void readEventAxis();
    bool verifyAxis();

    void run();

public:
    ManualControl();
    ManualControl(int _device_n, SerialCommunicator<Ai2RobotMessage> *_serial);

    ~ManualControl();

    void start();
    void stop();

    void setId(int _id);
    void setMaxVelocity(float _velocity);
    void setMaxAngularVelocity(float _velocity);
    void setDribblerVelocity(int _velocity);
    void setKickPower(int _power);
    void setPassPower(int _power);
};

#endif // MANUALCONTROL_H
