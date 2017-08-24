#include "protocoloserial.h"

/*
 *Todos os dados de velocidade e forca sao percentuais, os quais variam de 0 a 100 (provavel que o embarcado que resolva esse problema transformando em pwm
 * */

ProtocoloSerial::ProtocoloSerial()
{   unsigned i;
    for(i=0;i<4;i++)
    {   velocidadeRodas.push_back(0);
        direcaoRodas.push_back(HORARIO);
    }
    enableChute=0;
    nivelChute=0;
    tipoChute=SEM_CHUTE;
    velocidadeDriblador=0;
    direcaoDriblador=ANTI_HORARIO;
    id=128;
    enableDrible=false;
}

void ProtocoloSerial::setId(unsigned char _id){
    id=int(_id)+128;
    //cout<<id<<endl;
}

void ProtocoloSerial::limpaPacote(){
    fill(velocidadeRodas.begin(),velocidadeRodas.end(),0);
    velocidadeDriblador=0;
    tipoChute=SEM_CHUTE;
    nivelChute=0;
}

void ProtocoloSerial::setVelocidadeRodas(vector<unsigned char> _vel){
    //velocidadeRodas=_vel;
    unsigned i;
    for(i=0;i<4;i++)
        velocidadeRodas[i]=_vel[i];
}

void ProtocoloSerial::setDirecaoRodas(vector<Direcao> _dir){
    //direcaoRodas=_dir;
    unsigned i;
    for(i=0;i<4;i++)
        direcaoRodas[i]=_dir[i];
}

void ProtocoloSerial::setVelocidadeDriblador(unsigned char _vel){
    velocidadeDriblador=_vel;
}

void ProtocoloSerial::setDirecaoDriblador(Direcao _dir){
    direcaoDriblador=_dir;
}

void ProtocoloSerial::setTipoChute(TipoChute _tipochute){
    tipoChute=_tipochute;
}

void ProtocoloSerial::setNivelChute(unsigned char _nivelChute){
    nivelChute=(unsigned char)(_nivelChute*15/100);
}

void ProtocoloSerial::setEnableDrible(bool _enable)
{
    enableDrible = _enable;
}

void ProtocoloSerial::setEnableChute(bool _enable){
    if(_enable){
        enableChute = 1;
    }
    else{
        enableChute = 0;
    }
}
/*
 * Buffer eh passado por referencia e eh modificado dentro do metodo
 * O Buffer contem os dados do robo que, nesse caso, serão alterados pelo controle
 * São 8 posições que contém os dados

1 | ID
0 | Velocidade Motor 1
0 | Velocidade Motor 2
0 | Velocidade Motor 3
0 | Velocidade Motor 4
0 | Velocidade Driblador
0 | X | X | DirDR | Dir4 | Dir3 | Dir2 | Dir1
0 | X | Enable | Modo | Força

*/

void ProtocoloSerial::serializa(vector<unsigned char> &buffer) const{
    /*cout<<"=========================PACOTE====================================\n"<<endl;
    printf("%u\n",id);
    printf("%u\n",velocidadeRodas[0]);
    printf("%u\n",velocidadeRodas[1]);
    printf("%u\n",velocidadeRodas[2]);
    printf("%u\n",velocidadeRodas[3]);
    printf("%u\n",velocidadeDriblador);
    printf("%u | %u | %u | %u | %u\n",direcaoDriblador,direcaoRodas[0],direcaoRodas[1],direcaoRodas[2],direcaoRodas[3]);
    printf("%d | %d | %u\n\n",enableChute==false?0:1,tipoChute,nivelChute);
    printf("%s\n",enableDrible==true?"Enabled":"Nao");*/
    fill(buffer.begin(), buffer.begin(), 0);

    buffer[0]=id;

    for(int i=1;i<5;i++){
        buffer[i]=velocidadeRodas[i-1];
    }

    if(enableDrible && !enableChute){
        buffer[5]=70;
    }
    else{
        buffer[5]=0;
    }

    buffer[6]=0;
    buffer[6] = direcaoDriblador << 4 | direcaoRodas[3] << 3 | direcaoRodas[2] << 2 | direcaoRodas[1] << 1 | direcaoRodas[0];

    unsigned char bitsChute;
    if(tipoChute==SEM_CHUTE){
        bitsChute = 0;
    }else if(tipoChute==CHUTE_BAIXO){
        bitsChute =  2;
    }else if(tipoChute==CHUTE_ALTO){
        bitsChute = 3;
    }
    bitsChute = bitsChute | enableChute << 2 ;
    buffer[7] = bitsChute << 4 | nivelChute;
}


