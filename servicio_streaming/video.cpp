#include "video.h"
#include <string>
using std::string;

Video::Video()
{
    id = "";
    nombre = "";
    duracion = 0;
    calificacion = 0.0;
    fechaEstreno = "";
}

Video::Video(string id, string nombre, int duracion, double calificacion, string fechaEstreno)
{
    this -> id = id;
    this -> nombre = nombre;
    this -> duracion = duracion;
    this -> calificacion = calificacion;
    this -> fechaEstreno = fechaEstreno;
}

Video::~Video()
{

}

string Video::getNombre() 
{
    return nombre;
}

double Video::getCalificacion()
{
    return calificacion; 
}

void Video::setCalificacion(double nuevaCalif)
{
    calificacion = nuevaCalif;
}
 
bool Video::operator>(const Video& otro) const
{
    return calificacion > otro.calificacion;
}
 
ostream& operator<<(ostream& os, const Video& v)
{
    os << "[" << v.id << "] " << v.nombre
       << " | Duracion: " << v.duracion << " min"
       << " | Calificacion: " << v.calificacion
       << " | Estreno: " << v.fechaEstreno;
    return os;
}