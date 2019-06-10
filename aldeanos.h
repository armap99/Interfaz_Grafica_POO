#ifndef ALDEANOS_H
#define ALDEANOS_H
#include <iostream>


class Aldeanos
{
public:
    std::string Nombre;
    int Edad;
    std::string Genero;
    int salud;
public:
    Aldeanos();
    std::string getNombre() const;
    void setNombre(const std::string &value);
    int getEdad() const;
    void setEdad(int value);
    std::string getGenero() const;
    void setGenero(const std::string &value);
    int getSalud() const;
    void setSalud(int value);

    bool operator <(const Aldeanos &j){
        return Nombre < j.getNombre();
    }
};

#endif // ALDEANOS_H
