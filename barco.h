#ifndef BARCO_H
#define BARCO_H
#include <iostream>
#include <stack>
#include "guerrero.h"

class Barco
{
private:
    int Idb;
    int Combustible;
    int Velocidad;
    int Armadura;
public:
    std::stack<Guerrero> Tripulantes;
    Barco();
    int getIdb() const;
    void setIdb(int value);
    int getCombustible() const;
    void setCombustible(int value);
    int getVelocidad() const;
    void setVelocidad(int value);
    int getArmadura() const;
    void setArmadura(int value);
    void PushG(const Guerrero& );
    Guerrero PopG();
    Guerrero TopG();
    size_t CantTrip();
    struct comparador{
        bool operator()(Barco*b1,Barco*b2){
            return b1->getVelocidad() < b2->getVelocidad();
        }
    };
};

#endif // BARCO_H
