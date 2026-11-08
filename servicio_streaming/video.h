#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
using std::string;
using std::ostream;

class Video
{
    protected: 
    string id;
    string nombre;
    int duracion;
    double calificacion;
    string fechaEstreno;
    public:
    Video();
    Video(string id, string nombre, int duracion, double calificacion, string fechaEstreno);
    virtual ~Video();
    string getNombre();
    double getCalificacion();
    void setCalificacion(double nuevaCalif);
    bool operator>(const Video& otro) const;
    friend ostream& operator<<(ostream& os, const Video& v);
};

#endif