#include "ai2robotmessage.h"

Ai2RobotMessage::Ai2RobotMessage() : id(-1), wheels_velocity(4, velocity{0, CLOCKWISE}), dribbler_velocity(velocity{0, CLOCKWISE})
{

}

void Ai2RobotMessage::setId(unsigned char _id)
{
    id  = 128 + _id;
}

void Ai2RobotMessage::clear()
{
    id = 0;
    fill(wheels_velocity.begin(), wheels_velocity.end(), velocity{0, CLOCKWISE});
    dribbler_velocity = velocity{0, CLOCKWISE};
}

std::vector<unsigned char> Ai2RobotMessage::serialize()
{
    std::vector<unsigned char> buffer(8, 0);
    buffer[0] = id;
    for (int i = 1; i < wheels_velocity.size(); ++i)
        buffer[i] = wheels_velocity[i-1].value;
    buffer[5] = (enable_dribbler) ? dribbler_velocity.value : 0;
    buffer[6] = enable_kick << 6 |
        kick_type << 5 | dribbler_velocity.direction << 4 |
        wheels_velocity[3].direction << 3 | wheels_velocity[2].direction << 2 |
        wheels_velocity[1].direction << 1 | wheels_velocity[0].direction;
    buffer[7] = kick_level;
    return buffer;
}

ostream &operator << (ostream &stream, Ai2RobotMessage const &message)
{
    stream << "TeamProcolMessage{ " << endl;
    stream << "\tid: " << static_cast<int>(message.id) << endl;
    stream << "\twheels_velocity: [ ";
    for (Ai2RobotMessage::velocity v : message.wheels_velocity) stream << "{" << static_cast<int>(v.value) << ", " << static_cast<int>(v.direction) << "} ";
    stream << "]" << endl;
    stream << "\tenable_dribbler: " << static_cast<int>(message.enable_dribbler) << endl;
    stream << "\tdribbler_velocity: {" << static_cast<int>(message.dribbler_velocity.value) << ", " << static_cast<int>(message.dribbler_velocity.direction) << "}" << endl;
    stream << "\tenable_kick: " << static_cast<int>(message.enable_kick) << endl;
    stream << "\tkick_type: " << static_cast<int>(message.kick_type) << endl;
    stream << "\tkick_level: " << static_cast<int>(message.kick_level) << endl;
    stream << "};";
    return stream;
}

void Ai2RobotMessage::setWheelVelocity(int n, unsigned char value)
{
    wheels_velocity[n].value = value;
}

void Ai2RobotMessage::setWheelDirection(int n, Direction direction)
{
    wheels_velocity[n].direction = direction;
}

void Ai2RobotMessage::setWheel(int n, unsigned char value, Direction direction)
{
    wheels_velocity[n].value = value;
    wheels_velocity[n].direction = direction;
}

void Ai2RobotMessage::setEnableDribbler(bool enable)
{
    enable_dribbler = enable;
}

void Ai2RobotMessage::setDribblerVelocity(unsigned char value)
{
    dribbler_velocity.value = value;
}

void Ai2RobotMessage::setDribblerDirection(Direction direction)
{
    dribbler_velocity.direction = direction;
}

void Ai2RobotMessage::setDribbler(bool enable, unsigned char value, Direction direction)
{
    enable_dribbler = enable;
    dribbler_velocity.value = value;
    dribbler_velocity.direction = direction;
}

void Ai2RobotMessage::setEnableKick(bool enable)
{
    enable_kick = enable;
}

void Ai2RobotMessage::setKickType(KickType type)
{
    kick_type = type;
}

void Ai2RobotMessage::setKickLevel(unsigned char level)
{
    kick_level = level;
}

void Ai2RobotMessage::setKick(bool enable, KickType type, unsigned char level)
{
    enable_kick = enable;
    kick_type = type;
    kick_level = level;
}
