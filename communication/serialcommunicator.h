#ifndef SERIALCOMMUNICATOR_H
#define SERIALCOMMUNICATOR_H

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
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
    string device;
    int baud_rate;

    bool running;
    thread run_thread;
    mutex run_mutex;

    int buffer_size;
    vector<mutex> buffer_mutex;
    vector<T> buffer;
    vector<bool> sent_messages;

    bool set_options()
    {
        try {
            serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
            serial.set_option(boost::asio::serial_port_base::character_size(8));
            return true;
        } catch (boost::system::system_error error) {
            std::cout << "Comunicator Error: " << error.what() << std::endl;
        }
        return false;
    }

public:
    SerialCommunicator(): io(), serial(io)
    {
    }
    SerialCommunicator(string _device, int _baud_rate, int _buffer_size): io(), serial(io), device(_device), baud_rate(_baud_rate),
        buffer_size(_buffer_size), buffer(buffer_size), buffer_mutex(buffer_size), sent_messages(buffer_size)
    {
    }

    bool open()
    {
        close();
        try {
            serial.open(device);
            return set_options();
        } catch (boost::system::system_error error) {
            std::cout << "Erro de comunicação: " << error.what() << std::endl;
        }
        return false;
    }

    void close()
    {
        if (serial.is_open())
            serial.close();
    }

    bool start()
    {
        if (!open()) return false;
        fill(sent_messages.begin(), sent_messages.end(), true);
        running = true;
        run_thread = thread(&SerialCommunicator::run, this);
        return true;
    }

    void stop()
    {
        {
            lock_guard<mutex> lock(run_mutex);
            running = false;
        }
        run_thread.join();
    }

    void write(T message)
    {
        lock_guard<mutex> lock(buffer_mutex[message.getId()]);
        buffer[message.getId()] = message;
        sent_messages[message.getId()] = false;
    }

    int send(vector<unsigned char> encoded_message)
    {
        return serial.write_some(boost::asio::buffer(encoded_message, encoded_message.size()));
    }

    void run()
    {
        while (running) {
            for (int i = 0; i < buffer_size; i++) {
                if (!sent_messages[i]) {
                    send(buffer[i].serialize());
                    cout<<"Mensagem enviada, ID: "<<i<<endl;
                    sent_messages[i] = true;
                }
            }
        }
    }

    friend ostream &operator <<(ostream &stream, SerialCommunicator const &communicator)
    {
       stream << "SerialCommunicator{ " << endl;
       stream << "\tdevice: " << communicator.device << endl;
       stream << "\tbaud_rate: " << communicator.baud_rate << endl;
       stream << "};";
       return stream;
   }
};

#endif // SERIALCOMMUNICATOR_H
