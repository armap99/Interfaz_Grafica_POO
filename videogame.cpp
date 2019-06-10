#include "videogame.h"

VideoGame::VideoGame()
{

}

std::string VideoGame::getUsuario()
{
    return Usuario;
}

void VideoGame::setUsuario(const string &value)
{
    Usuario = value;
}

void VideoGame::Agregar(const Civilizacion &a)
{
    Aldeas.push_back(a);
}

void VideoGame::Insertar(const Civilizacion &a, const size_t &n)
{
    auto it = Aldeas.begin();
    Aldeas.insert(it+n,a);
}

size_t VideoGame::size()
{
    return Aldeas.size();
}

void VideoGame::Inicializa(const size_t &n, const Civilizacion &a)
{
    Aldeas = vector<Civilizacion>(n,a);
}

Civilizacion VideoGame::primera()
{
    return Aldeas.front();
}

Civilizacion VideoGame::ultima()
{
    return  Aldeas.back();
}

void VideoGame::Ordenar()
{
    sort(Aldeas.begin(),Aldeas.end());
}

void VideoGame::EliminarN(const string &nombre)
{
    for(size_t i(0);i < size();i++){
        if(Aldeas[i].getNombre() == nombre){
            auto it = Aldeas.begin();
            Aldeas.erase(it+i);
            break;
        }
    }
}

void VideoGame::respaldar(const string &ubicacion,vector<Civilizacion> &civilizaciones)
{
    ofstream archivo(ubicacion, ios::out);

    for (int i = 0; i < civilizaciones.size(); ++i) {
        Civilizacion &c = civilizaciones[i];
        archivo << c.getNombre() << endl;
        archivo << c.getUbicacionX() << endl;
        archivo << c.getUbicacionY() << endl;
        ofstream habitantes("C:/Users/Armando Prado/Desktop/"+civilizaciones[i].getNombre() + ".txt", ios::out);

        for (auto it = civilizaciones[i].habitantes.begin(); it != civilizaciones[i].habitantes.end(); ++it) {
            Aldeanos &aldeano = *it;
            habitantes << aldeano.getNombre() << endl;
            habitantes << aldeano.getEdad() << endl;
            habitantes << aldeano.getGenero() << endl;
            habitantes << aldeano.getSalud() << endl;
        }
        habitantes.close();
    }
    archivo.close();

}

void VideoGame::recuperar(const std::string &ubicacion)
{
    ifstream archivo(ubicacion);

    if (archivo.is_open()) {
        while (!archivo.eof()) {
            string linea;
            Civilizacion a;

            getline(archivo, linea);
            if (archivo.eof()) {
                break;
            }
            a.setNombre(linea);
            getline(archivo, linea);
            a.setUbicacionX(stoi(linea));
            getline(archivo, linea);
            a.setUbicacionY(stoi(linea));

            ifstream archivo2("C:/Users/Armando Prado/Desktop/"+a.getNombre() + ".txt",ios_base::in);
            if(archivo2.is_open()){
                while (!archivo2.eof()) {
                    string aux;
                    Aldeanos armando;
                    getline(archivo2, aux);
                    if(archivo2.eof()){
                        break;
                    }
                    armando.setNombre(aux);
                    getline(archivo2, aux);
                    armando.setEdad(stoi(aux));
                    getline(archivo2, aux);
                    armando.setGenero(aux);
                    getline(archivo2,aux);
                    armando.setSalud(stoi(aux));
                    a.AgregarFinal(armando);
                }
            }
            Agregar(a);
        }
    }
}

