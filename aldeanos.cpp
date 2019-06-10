#include "aldeanos.h"

Aldeanos::Aldeanos()
{

}


std::string Aldeanos::getNombre() const
{
    return Nombre;
}

void Aldeanos::setNombre(const std::string &value)
{
    Nombre = value;
}

int Aldeanos::getEdad() const
{
    return Edad;
}

void Aldeanos::setEdad(int value)
{
    Edad = value;
}

std::string Aldeanos::getGenero() const
{
    return Genero;
}

void Aldeanos::setGenero(const std::string &value)
{
    Genero = value;
}

int Aldeanos::getSalud() const
{
    return salud;
}

void Aldeanos::setSalud(int value)
{
    salud = value;
}
