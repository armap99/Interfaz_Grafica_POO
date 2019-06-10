#ifndef GUERRERO_H
#define GUERRERO_H
#include <iostream>

class Guerrero
{
private:
    int Id;
    int Salud;
    int Fuerza;
    int Escudo;
    std::string Tipo;
public:
    Guerrero();
    int getId() const;
    void setId(int value);
    int getSalud() const;
    void setSalud(int value);
    int getFuerza() const;
    void setFuerza(int value);
    int getEscudo() const;
    void setEscudo(int value);
    std::string getTipo() const;
    void setTipo(const std::string &value);
};

#endif // GUERRERO_H
