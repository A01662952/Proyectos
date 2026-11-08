#include "serie.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

Serie::Serie() : id(""), nombre(""), genero("")
{
    
}

Serie::Serie(string id, string nombre, string genero)
{
    this->id = id;
    this->nombre = nombre;
    this->genero = genero;
}

Serie::~Serie()
{
    for (int i = 0; i < (int)episodios.size(); i++)
        delete episodios[i];
}

void Serie::agregarEpisodio(Episodio* ep)
{
    episodios.push_back(ep);
}

string Serie::getId() { return id; }
string Serie::getNombre() { return nombre; }

void Serie::mostrarVideos(string generoFiltro)
{
    string token;
    bool encontrado = false;
    for (int i = 0; i <= (int)genero.size(); i++)
    {
        if (i == (int)genero.size() || genero[i] == ';')
        {
            string limpio;
            for (int j = 0; j < (int)token.size(); j++)
                if (token[j] != ' ') limpio += token[j];
            if (limpio == generoFiltro)
                encontrado = true;
            token = "";
        }
        else
            token += genero[i];
    }
    if (encontrado)
        cout << *this << endl;
}

void Serie::mostrarVideosC(double umbral)
{
    for (int i = 0; i < (int)episodios.size(); i++)
    {
        if (episodios[i]->getCalificacion() > umbral)
        {
            cout << "[SERIE] " << nombre << " | ";
            cout << *episodios[i] << endl;
        }
    }
}

void Serie::mostrarEpisodio(string nombreSerie)
{
    if (nombre == nombreSerie)
    {
        cout << "[SERIE] " << nombre << endl;
        for (int i = 0; i < (int)episodios.size(); i++)
            cout << *episodios[i] << endl;
    }
}

void Serie::calificarVideo(string nombreEp, double nuevaCalif)
{
    for (int i = 0; i < (int)episodios.size(); i++)
    {
        if (episodios[i]->getNombre() == nombreEp)
        {
            episodios[i]->setCalificacion(nuevaCalif);
            cout << "Episodio \"" << episodios[i]->getNombre() << "\" calificado con " << nuevaCalif << endl;
            return;
        }
    }
}

bool Serie::operator>(const Serie& otra) const
{
    return episodios.size() > otra.episodios.size();
}

ostream& operator<<(ostream& os, const Serie& s)
{
    os << "[SERIE] [" << s.id << "] " << s.nombre
       << " | Genero: " << s.genero
       << " | Episodios: " << s.episodios.size();
    return os;
}