#ifndef TEAMPROTOCOL_H
#define TEAMPROTOCOL_H

#include <iostream>
#include <algorithm>
#include "serialmessage.h"
using namespace std;

enum Direction{
    CLOCKWISE, COUNTERCLOCKWISE
};

enum KickType{
    LOW, HIGH
};

class Ai2RobotMessage : public SerialMessage
{
private:
    struct velocity
    {
        unsigned char value;
        Direction direction;
    };
    unsigned char id;
    vector<velocity> wheels_velocity;
    bool enable_dribbler;
    velocity dribbler_velocity;
    bool enable_kick;
    KickType kick_type;
    unsigned char kick_level;
public:
    Ai2RobotMessage();
    void setId(unsigned char);
    void clear();
    /**
    \brief Função para serializar os dados para envio serial

        0 | ID
        1 | Velocidade Motor 1
        2 | Velocidade Motor 2
        3 | Velocidade Motor 3
        4 | Velocidade Motor 4
        5 | Velocidade Driblador
        6 | X | Enable | Mode | DirDR | Dir4 | Dir3 | Dir2 | Dir1
        7 | Força

    \return Dados serializados em um vector de char(byte).
    */
    vector<unsigned char> serialize();
    friend ostream &operator <<(std::ostream &, Ai2RobotMessage const &);
    void setWheelVelocity(int, unsigned char);
    void setWheelDirection(int, Direction);
    void setWheel(int, unsigned char, Direction);
    void setEnableDribbler(bool);
    void setDribblerVelocity(unsigned char);
    void setDribblerDirection(Direction);
    void setDribbler(bool, unsigned char, Direction);
    void setEnableKick(bool);
    void setKickType(KickType);
    void setKickLevel(unsigned char);
    void setKick(bool, KickType, unsigned char);
};

#endif // TEAMPROTOCOL_H
