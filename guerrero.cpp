#include "guerrero.h"

Guerrero::Guerrero()
{

}


int Guerrero::getId() const
{
    return Id;
}

void Guerrero::setId(int value)
{
    Id = value;
}

int Guerrero::getSalud() const
{
    return Salud;
}

void Guerrero::setSalud(int value)
{
    Salud = value;
}

int Guerrero::getFuerza() const
{
    return Fuerza;
}

void Guerrero::setFuerza(int value)
{
    Fuerza = value;
}

int Guerrero::getEscudo() const
{
    return Escudo;
}

void Guerrero::setEscudo(int value)
{
    Escudo = value;
}

std::string Guerrero::getTipo() const
{
    return Tipo;
}

void Guerrero::setTipo(const std::string &value)
{
    Tipo = value;
}
