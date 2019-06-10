#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <fstream>//para archivos
#include <vector>//vector
#include <algorithm>//para ordenamientos
#include "civilizacion.h"

using namespace std;

class VideoGame
{
private:
    std::string Usuario;

public:
    std::vector <Civilizacion> Aldeas;
    VideoGame();
    string getUsuario();
    void setUsuario(const string &);
    void Agregar(const Civilizacion&);//agregar civilizacion en primera pos
    void Insertar(const Civilizacion&, const size_t&);//agregar civilizacion en primera pos
    size_t size();
    void Inicializa(const size_t&, const Civilizacion&);//crear civilizaciones
    Civilizacion primera();
    Civilizacion ultima();
    void Ordenar();//ordenar por x
    void EliminarN(const string&);

    Civilizacion& operator[](unsigned int pos)
    {
        return Aldeas[pos];
    }

    void respaldar(const string&, vector<Civilizacion> &);
    void recuperar(const string&);

};

#endif // VIDEOGAME_H
