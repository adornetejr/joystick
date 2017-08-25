#include "serialmessage.h"

SerialMessage::SerialMessage()
{

}

unsigned char SerialMessage::getId()
{
    return id;
}

void SerialMessage::setId(unsigned char _id)
{
    id = _id;
}
