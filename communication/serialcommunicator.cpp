#include "serialcommunicator.h"

SerialCommunicator::SerialCommunicator() : io(), serial(io)
{

}

SerialCommunicator::SerialCommunicator(std::string _device, int _baud_rate, int _buffer_size) :
    io(), serial(io), device(_device), baud_rate(_baud_rate), buffer_size(_buffer_size), w_mutexes(buffer_size), buffer(buffer_size)
{

}

bool SerialCommunicator::set_options()
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

bool SerialCommunicator::open()
{
    close();
    try {
        serial.open(device);
        return set_options();
    } catch (boost::system::system_error error) {
        std::cout << "Communicator Error: " << error.what() << std::endl;
    }
    return false;
}

void SerialCommunicator::close()
{
    if (serial.is_open())
        serial.close();
}

void SerialCommunicator::start()
{
    if (!open()) return;
    fill(sent_messages.begin(), sent_messages.end(), true);
    running = true;
}

void SerialCommunicator::stop()
{
    running = false;
}

void SerialCommunicator::addMessage(SerialMessage *message)
{
    buffer[message->getId()] = message;
}

void SerialCommunicator::write(SerialMessage &message)
{
    lock_guard<mutex> lock(w_mutexes[message.getId()]);
    buffer[message.getId()] = &message;
    sent_messages[message.getId()] = false;
}

int SerialCommunicator::send(vector<unsigned char> encoded_message)
{
    return serial.write_some(boost::asio::buffer(encoded_message, encoded_message.size()));
}

void SerialCommunicator::operator ()()
{
    unique_lock<mutex> start_lock(cv_run_mutex);
    cout << "COMMUNICATOR WAIT...";
    cv_run.wait(start_lock, [this](){ return running; });
    cout << "COMMUNICATOR RUNNING!" << endl;
    while (running) {
        for (int i = 0; i < buffer_size; i++) {
            w_mutexes[i].lock();
            if (!sent_messages[i]) {
                send(buffer[i]->serialize());
                sent_messages[i] = true;
            }
            w_mutexes[i].unlock();
        }
    }
}

ostream &operator <<(ostream &stream, SerialCommunicator const &communicator) {
    stream << "SerialCommunicator{ " << endl;
    stream << "\tdevice: " << communicator.device << endl;
    stream << "\tbaud_rate: " << communicator.baud_rate << endl;
    stream << "};";
    return stream;
}
