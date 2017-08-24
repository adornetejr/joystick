#ifndef MANUALCONTROL_H
#define MANUALCONTROL_H
#include <iostream>
#include <string>
#include <vector>

#include <QThread>

#include <opencv/cv.h>

#include "joystick.hh"

#define MIN_AXIS 5000
#define MAX_AXIS 32767

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
    JoystickEvent event;

    int max_velocity;
    Mat_<float> velocity;
    Mat_<float> M;
    Mat_<float> velocity_wheels;
    Mat_<Direction> direction_wheels;

    vector<short> axis;

    void initKinematicModel();
    void calculateVelocity();
    void calculateWheelsVelocity();

    bool readEventButton();
    void readEventAxis();
    bool verifyAxis();

public:
    ManualControl(int _device_n);

    void run();

    void setId(int _id);
    void setMaxVelocity(int _velocity);
};

#endif // MANUALCONTROL_H
