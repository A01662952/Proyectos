#ifndef PELICULA_H
#define PELICULA_H

#include "video.h"
#include "interfaz.h"
#include <string>
using std::string;
 
class Pelicula : public Video, public Interfaz
{
    private:
    string genero;
    public:
    Pelicula();
    Pelicula(string id, string nombre, int duracion, double calificacion, string fechaEstreno, string genero);
    ~Pelicula();
    void mostrarVideos(string genero);
    void mostrarVideosC(double calificacion);
    void mostrarPelicula(double calificacion);
    void calificarVideo(string nombre, double calificacion);
    friend std::ostream& operator<<(std::ostream& os, const Pelicula& p);
};

#endif