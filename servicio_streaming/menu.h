#ifndef MENU_H
#define MENU_H

#include "interfaz.h"
#include "pelicula.h"
#include "serie.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Menu
{
    private:
    vector<Interfaz*> videos; // Pelicula* y Serie* (polimorfismo)
    public:
    Menu();
    ~Menu();
    void cargarArchivo(string ruta);
    void mostrarVideos(string genero);
    void mostrarVideosC(double calificacion);
    void mostrarEpisodios(string nombreSerie);
    void mostrarPeliculas(double calificacion);
    void calificarVideo(string nombre, double calificacion);
};

#endif