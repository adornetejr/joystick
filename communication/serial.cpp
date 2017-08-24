#include "serial.h"


Serial::Serial() : io(),serial(io){
    //Para abrir a conexão posso usar a porta ou o dispositivo! Como na IA só tem um radio, se usa o dispositivo, mas aqui, usaremos a propria porta
    dispositivo= "/dev/ttyUSB0";
}

void Serial::atualizaDados(int _id, unsigned int _baudrate, int _port, string _pariedade, int _bitParada, int _bitData){
    id=_id;
    baud_rate=_baudrate;
    port=_port;
    pariedade=_pariedade;
    bitParada=_bitParada;
    bitData=_bitData;
    porta="USB" + boost::lexical_cast<string>(port);
    dispositivo="/dev/tty"+porta;
}

Serial::~Serial(){
    close();
}

bool Serial::open()
{
    close();
    try{
        //chamado no abrir da manualwindow
        serial.open(dispositivo);
        //configura e ja retorna se deu certo ou não
        return configurar();
    }catch(boost::system::system_error error){
        cout<< "Erro Open||| "<<error.what()<<endl;
        return false;
    }
}

//implementar pariedade e bit de parada

bool Serial::configurar(){
    try{
        serial.set_option(serial_port_base::baud_rate(baud_rate));
        //achar um jeito de usar os valores selecionados pelo usuario, a classe tem um enum type com umas coisas estanhas, analisar como setar a pariedade e o stopbit
        // none por default
        //serial.set_option(serial_port_base::parity::none);
        // one por default
        //serial.set_option(serial_port_base::stop_bits::value(one));
        serial.set_option(serial_port_base::character_size(bitData));
        return true;

    }catch(boost::system::system_error error){
        cout<< "Erro Config"<<endl;
        return false;
    }
}

void Serial::close(){
    if(serial.is_open()) serial.close();
}

bool Serial::write(const ProtocoloSerial & pacote){
    vector <unsigned char> buf(8,0);
    pacote.serializa(buf);
    serial.write_some(buffer(buf,buf.size()));
    return true;
}

