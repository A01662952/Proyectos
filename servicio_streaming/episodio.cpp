#include "episodio.h"
#include <iostream>
using std::ostream;

Episodio::Episodio() : Video(), numEpisodio(0), temporada(0)
{

}

Episodio::Episodio(string id, string nombre, int duracion, double calificacion, string fechaEstreno, int numEpisodio, int temporada) : Video(id, nombre, duracion, calificacion, fechaEstreno)
{
    this->numEpisodio = numEpisodio;
    this->temporada = temporada;
}

Episodio::~Episodio() 
{

}

ostream& operator<<(ostream& os, const Episodio& e)
{
    os << "  T" << e.temporada << "E" << e.numEpisodio
       << " - " << e.nombre
       << " | Calificacion: " << e.calificacion;
    return os;
}