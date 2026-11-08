#ifndef SERIE_H
#define SERIE_H

#include "interfaz.h"
#include "episodio.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

class Serie : public Interfaz
{
    private:
    string id;
    string nombre;
    string genero;
    vector<Episodio*> episodios;
    public:
    Serie();
    Serie(string id, string nombre, string genero);
    ~Serie();
    void agregarEpisodio(Episodio* ep);
    string getId();
    string getNombre();
    void mostrarVideos(string genero);
    void mostrarVideosC(double calificacion);
    void mostrarEpisodio(string nombre);
    void calificarVideo(string nombre, double calificacion);
    bool operator>(const Serie& otra) const;
    friend std::ostream& operator<<(std::ostream& os, const Serie& s);
};

#endif