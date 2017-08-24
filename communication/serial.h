#ifndef SERIAL_H
#define SERIAL_H
#include <iostream>
#include <protocoloserial.h>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost::asio;

class Serial
{
public:
    Serial();
    ~Serial();
    bool open();
    void close();
    void atualizaDados(int id, unsigned int _baudrate, int _port, string _pariedade, int _bitParada, int _bitData);
    bool write(const ProtocoloSerial & pacote);
    string transPariedade();
private:
    int id;
    bool configurar();
    io_service io;
    serial_port serial;
    string pariedade;
    string dispositivo;
    int bitParada;
    int bitData;
    int port;
    vector<unsigned char> buf;
    string porta;
    unsigned int baud_rate;
};

#endif // SERIAL_H
