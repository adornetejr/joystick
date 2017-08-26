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

template<typename T>
class SerialCommunicator
{
    static_assert(is_base_of<SerialMessage, T>::value, "Template argument must implement SerialMessage!");
private:
    boost::asio::io_service io;
    boost::asio::serial_port serial;
    bool running;
    mutex cv_run_mutex;
    condition_variable cv_run;
    string device;
    int baud_rate;
    int buffer_size;
    vector<mutex> w_mutexes;
    vector<T> buffer;
    vector<bool> sent_messages;
    bool set_options();
public:
    SerialCommunicator();
    SerialCommunicator(string, int, int);
    bool open();
    void close();
    void start();
    void stop();
    void addMessage(SerialMessage *);
    void write(SerialMessage &);
    int send(vector<unsigned char>);
    void operator()();
    friend ostream &operator <<(ostream &, SerialCommunicator const &);
};

#endif // SERIALCOMMUNICATOR_H
