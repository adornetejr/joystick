#ifndef SERIALCOMMUNICATOR_H
#define SERIALCOMMUNICATOR_H

#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include "serialmessage.h"
using namespace std;

class SerialCommunicator
{
private:
    mutex cv_on_mutex;
    condition_variable cv_on;
    boost::asio::io_service io;
    boost::asio::serial_port serial;
    string device;
    int baud_rate;
    int buffer_size;
    vector<mutex> w_mutexes;
    vector<SerialMessage> buffer;
    bool set_options();
public:
    SerialCommunicator();
    SerialCommunicator(string, int, int);
    bool open();
    void close();
    int write(SerialMessage &);
    int send(vector<unsigned char>);
    void operator()();
    friend ostream &operator <<(ostream &, SerialCommunicator const &);
};

#endif // SERIALCOMMUNICATOR_H
