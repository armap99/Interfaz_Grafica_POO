#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include "aldeanos.h"
#include "barco.h"

class Civilizacion
{
private:
    std::string nombre;
    size_t ubicacionX;
    size_t ubicacionY;

public:
    std::priority_queue <Barco*,std::vector<Barco*>,Barco::comparador> batalla;
    std::list<Aldeanos> habitantes;
    std::list<Barco*> puerto;
    Civilizacion();
    void setNombre(const std::string&);
    std::string getNombre();

    void setUbicacionX(const size_t&);
    size_t getUbicacionX();

    void setUbicacionY(const size_t&);
    size_t getUbicacionY();

    bool operator == (Civilizacion &);
    bool operator < (Civilizacion &);
    bool operator <= (Civilizacion &);
    bool operator > (Civilizacion &);
    bool operator >= (Civilizacion &);
    bool operator != (Civilizacion &);

    void AgregarInicio(const Aldeanos&j);
    void AgregarFinal(const Aldeanos&j);


    void OrdenarNombre();
    void OrdenarEdad();
    void OrdenarSalud();

    void EliminarNombre(const std::string &nombre);
    void EliminarSalud(const int &g);
    void EliminarEdad();

    int size();
    //Puerto
    void AgregarBarco(const Barco& b);
    Barco* BuscarBarco(const int& );
    void EliminarBarcoId(const int&);
    void EliminarBarcoCantida(const int&);
    int BarcosEnPuerto();
    //batalla
    void AgregarBatalla(Barco* &);
    void EliminarBarcoIdSBorrar(const int&);
};

#endif // CIVILIZACION_H
