#include "serialcommunicator.h"

SerialCommunicator::SerialCommunicator() : io(), serial(io)
{

}

SerialCommunicator::SerialCommunicator(std::string _device, int _baud_rate, int _buffer_size) :
    io(), serial(io), device(_device), baud_rate(_baud_rate), buffer_size(_buffer_size), w_mutexes(buffer_size), buffer(buffer_size)
{

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

int SerialCommunicator::write(SerialMessage &message)
{
    lock_guard<mutex> lock(w_mutexes[message.getId()]);
    buffer[message.getId()] = message;
}

int SerialCommunicator::send(vector<unsigned char> encoded_message)
{
    return serial.write_some(boost::asio::buffer(encoded_message, encoded_message.size()));
}

void SerialCommunicator::operator ()()
{
   if (!open()) return;
   lock_guard<mutex> lock(cv_on_mutex);
   //cv_on.wait(lock, [](){ return running; });
}

ostream &operator <<(ostream &stream, SerialCommunicator const &communicator) {
    stream << "SerialCommunicator{ " << endl;
    stream << "\tdevice: " << communicator.device << endl;
    stream << "\tbaud_rate: " << communicator.baud_rate << endl;
    stream << "};";
    return stream;
}
