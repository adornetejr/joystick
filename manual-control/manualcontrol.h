#ifndef MANUALCONTROL_H
#define MANUALCONTROL_H
#include <iostream>
#include <string>
#include <vector>

#include <QThread>

#include <opencv/cv.h>

#include "joystick.hh"

#define MIN_AXIS_VALUE 5000
#define MAX_AXIS_VALUE 32767

using namespace std;
using namespace cv;

enum Direction{
    CLOCKWISE, COUNTERCLOCKWISE
};

enum KickType{
    LOW, HIGH
};

class ManualControl: public QThread
{
private:
    int id;

    int device_n;
    Joystick *joystick;
    JoystickEvent *event;

    int max_velocity;
    Mat_<float> velocity;
    Mat_<float> M;
    Mat_<float> velocity_wheels;
    Mat_<Direction> direction_wheels;

    Mat_<int> axis;

    void initKinematicModel();
    void calculateVelocity();
    void calculateWheelsVelocity();

    bool readEventButton(JoystickEvent _event);
    void readEventAxis(JoystickEvent _event);
    bool verifyAxis();

public:
    ManualControl();
    ManualControl(int _id, int _device_n, int _velocity);

    void run();

    void setMaxVelocity(int _velocity);
};

#endif // MANUALCONTROL_H
