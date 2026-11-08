#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
using std::string;

class Interfaz
{
    public:
    virtual void mostrarVideos(string genero) = 0;
    virtual void mostrarVideosC(double calificacion) = 0;
    virtual void calificarVideo(string nombre, double calificacion) = 0;
    virtual ~Interfaz() {}
};

#endif