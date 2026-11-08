#ifndef EPISODIO_H
#define EPISODIO_H

#include "video.h"
#include <string>
using std::string;

class Episodio : public Video
{
    protected:
    int numEpisodio;
    int temporada;
    public:
    Episodio();
    Episodio(string id, string nombre, int duracion, double calificacion, string fechaEstreno, int numEpisodio, int temporada);
    ~Episodio();
    friend ostream& operator<<(ostream& os, const Episodio& e);
};

#endif