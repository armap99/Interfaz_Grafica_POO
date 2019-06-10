#include "civilizacion.h"

Civilizacion::Civilizacion()
{

}

void Civilizacion::setNombre(const std::string &n)
{
    nombre = n;
}

std::string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setUbicacionX(const size_t &x)
{
    ubicacionX = x;
}

size_t Civilizacion::getUbicacionX()
{
    return ubicacionX;
}

void Civilizacion::setUbicacionY(const size_t &y)
{
    ubicacionY = y;
}

size_t Civilizacion::getUbicacionY()
{
    return ubicacionY;
}

bool Civilizacion::operator == (Civilizacion &a)
{
    return (ubicacionX == a.getUbicacionX()) and (ubicacionY == a.getUbicacionY());
}

bool Civilizacion::operator < (Civilizacion &a)
{
    return ubicacionX < a.getUbicacionX();
}

bool Civilizacion::operator <= (Civilizacion &a)
{
    return ubicacionX <= a.getUbicacionX();
}

bool Civilizacion::operator > (Civilizacion &a)
{
    return ubicacionX > a.getUbicacionX();
}

bool Civilizacion::operator >= (Civilizacion &a)
{
    return ubicacionX >= a.getUbicacionX();
}

bool Civilizacion::operator != (Civilizacion &a)
{
    return (ubicacionX != a.getUbicacionX()) and (ubicacionY != a.getUbicacionY());
}

void Civilizacion::AgregarInicio(const Aldeanos &j)
{
    habitantes.push_front(j);
}

void Civilizacion::AgregarFinal(const Aldeanos &j)
{
    habitantes.push_back(j);
}

void Civilizacion::OrdenarNombre()
{
    habitantes.sort();
}

void Civilizacion::OrdenarEdad()
{
    habitantes.sort([](const Aldeanos&j1, const Aldeanos&j2){return j1.getEdad() > j2.getEdad();});
}

void Civilizacion::OrdenarSalud()
{
    habitantes.sort([](const Aldeanos&j1, const Aldeanos&j2){return j1.getSalud() > j2.getSalud();});
}

void Civilizacion::EliminarNombre(const std::string &nombre)
{
    for (auto it = habitantes.begin(); it != habitantes.end(); ++it) {
        Aldeanos &j = *it;
        if(nombre == j.getNombre()){
            habitantes.erase(it);
            break;
        }
    }
}

bool compardorEdad(const Aldeanos &j){
    return j.getEdad() >= 60;
}

void Civilizacion::EliminarSalud(const int &g)
{
    habitantes.remove_if([g](const Aldeanos &a){return a.getSalud() <= g;});
}

void Civilizacion::EliminarEdad()
{
    habitantes.remove_if(compardorEdad);
}

int Civilizacion::size()
{
    return habitantes.size();
}

void Civilizacion::AgregarBarco(const Barco &b)
{
    Barco *ptr = new Barco(b);
    puerto.push_back(ptr);
}

Barco *Civilizacion::BuscarBarco(const int &id)
{
    for (auto it = puerto.begin();it != puerto.end();++it) {
        Barco aux = **it;
        Barco* auxDos = *it;
        if(aux.getIdb() == id){
            return auxDos;
        }
    }
}

void Civilizacion::EliminarBarcoId(const int &id)
{
    for (auto it = puerto.begin();it != puerto.end();++it) {
        Barco* auxDos = *it;
        if(auxDos->getIdb() == id){
            puerto.remove(auxDos);
            delete auxDos;
            break;
        }
    }
}

void Civilizacion::EliminarBarcoCantida(const int &x)
{
    for (auto it = puerto.begin();it != puerto.end();++it) {
        Barco* auxDos = *it;
        if(auxDos->getCombustible() < x){
            puerto.remove(auxDos);
            delete auxDos;
        }
    }
}

int Civilizacion::BarcosEnPuerto()
{
    return puerto.size();
}

void Civilizacion::AgregarBatalla(Barco *&b)
{
    batalla.push(b);
}

void Civilizacion::EliminarBarcoIdSBorrar(const int &id)
{
    for (auto it = puerto.begin();it != puerto.end();++it) {
        Barco* auxDos = *it;
        if(auxDos->getIdb() == id){
            puerto.remove(auxDos);
            break;
        }
    }
}
