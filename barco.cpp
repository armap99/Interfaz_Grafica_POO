#include "barco.h"

Barco::Barco()
{
    Velocidad = 0;
    Armadura = 100;
}

int Barco::getIdb() const
{
    return Idb;
}

void Barco::setIdb(int value)
{
    Idb = value;
}

int Barco::getCombustible() const
{
    return Combustible;
}

void Barco::setCombustible(int value)
{
    Combustible = value;
}

int Barco::getVelocidad() const
{
    return Velocidad;
}

void Barco::setVelocidad(int value)
{
    Velocidad = value;
}

int Barco::getArmadura() const
{
    return Armadura;
}

void Barco::setArmadura(int value)
{
    Armadura = value;
}

void Barco::PushG(const Guerrero &men)
{
    Tripulantes.push(men);
}

Guerrero Barco::PopG()
{
    Guerrero aux(Tripulantes.top());
    Tripulantes.pop();
    return aux;
}

Guerrero Barco::TopG()
{
    return Tripulantes.top();
}

size_t Barco::CantTrip()
{
    return Tripulantes.size();
}




