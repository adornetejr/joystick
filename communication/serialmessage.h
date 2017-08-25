#ifndef SERIALMESSAGE_H
#define SERIALMESSAGE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SerialMessage
{
private:
    unsigned char id;
public:
    SerialMessage();
    unsigned char getId();
    void setId(unsigned char _id);
    virtual void clear() = 0;
    virtual vector<unsigned char> serialize() = 0;
    friend ostream &operator <<(ostream &, SerialMessage const &);
};

#endif // SERIALMESSAGE_H
