#ifndef PROTOCOLOSERIAL_H
#define PROTOCOLOSERIAL_H
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

enum Direcao{
    HORARIO =0, ANTI_HORARIO=1
};

enum TipoChute{
    CHUTE_BAIXO =0,
    CHUTE_ALTO =1,
    SEM_CHUTE =2
};

class ProtocoloSerial
{
private:
    unsigned char id;
    vector <unsigned char> velocidadeRodas;
    unsigned char velocidadeDriblador;
    vector <Direcao> direcaoRodas;
    Direcao direcaoDriblador;
    TipoChute tipoChute;
    unsigned char nivelChute;
    unsigned char enableChute;
    bool enableDrible;

public:
    ProtocoloSerial();
    void setId(unsigned char _id);
    void limpaPacote();

    /*
     *Para as direções com defasagem de 90 graus a velocidade de todas as rodas eh a mesma, portanto, só existe metodo para setar as velocidades com um vetor inteiro
     *Caso seja implementado um metodo discreto de 45 graus, se deve criar metodos para setar as velocidades e direcao uma a uma
     * */

    void setVelocidadeRodas(vector <unsigned char> _vel);
    void setDirecaoRodas(vector <Direcao> _dir);

    void setVelocidadeDriblador(unsigned char _vel);
    void setDirecaoDriblador(Direcao _dir);
    void setEnableDrible(bool _enable);

    void setTipoChute(TipoChute _tipochute);
    void setNivelChute(unsigned char _nivelChute);
    void setEnableChute(bool _enable);

    void serializa(vector <unsigned char> & buffer) const;

};

#endif // PROTOCOLOSERIAL_H
