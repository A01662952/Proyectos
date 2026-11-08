#include "pelicula.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

Pelicula::Pelicula() : Video(), genero("") 
{
    
}

Pelicula::Pelicula(string id, string nombre, int duracion, double calificacion, string fechaEstreno, string genero) : Video(id, nombre, duracion, calificacion, fechaEstreno)
{
    this->genero = genero;
}

Pelicula::~Pelicula() {}

void Pelicula::mostrarVideos(string generoFiltro)
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

void Pelicula::mostrarVideosC(double umbral)
{
    if (calificacion > umbral)
        cout << *this << endl;
}

void Pelicula::mostrarPelicula(double umbral)
{
    mostrarVideosC(umbral);
}

void Pelicula::calificarVideo(string nombreBuscado, double nuevaCalif)
{
    if (nombre == nombreBuscado)
    {
        setCalificacion(nuevaCalif);
        cout << "Pelicula \"" << nombre << "\" calificada con " << nuevaCalif << endl;
    }
}

ostream& operator<<(ostream& os, const Pelicula& p)
{
    os << "[PELICULA] [" << p.id << "] " << p.nombre
       << " | Genero: " << p.genero
       << " | Calificacion: " << p.calificacion;
    return os;
}