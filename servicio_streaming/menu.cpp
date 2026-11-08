#include "menu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::map;
using std::runtime_error;
using std::vector;

Menu::Menu()
{

}

Menu::~Menu()
{
    for (int i = 0; i < (int)videos.size(); i++)
        delete videos[i];
}
 
void Menu::cargarArchivo(string ruta)
{
    ifstream archivo(ruta);
 
    if (!archivo.is_open())
        throw runtime_error("No se pudo abrir el archivo: " + ruta);
 
    auto parsearLinea = [](const string& linea) -> vector<string>
    {
        vector<string> campos;
        string campo;
        for (int i = 0; i < (int)linea.size(); i++)
        {
            if (linea[i] == ',')
            {
                campos.push_back(campo);
                campo = "";
            }
            else
                campo += linea[i];
        }
        campos.push_back(campo);
        return campos;
    };
 
    string linea;
    getline(archivo, linea); // saltar encabezado
 
    // Vector paralelo para buscar series
    vector<string> seriesIds;
    vector<Serie*> seriesPtr;
 
    while (getline(archivo, linea))
    {
        if (linea.empty()) continue;
 
        vector<string> campos = parsearLinea(linea);
 
        if ((int)campos.size() < 6)
            throw runtime_error("Formato invalido en linea: " + linea);
 
        string id     = campos[0];
        string nombre = campos[1];
        string genero = campos[3];
        string fecha  = campos[5];
        int duracion  = 0;
        double calif  = 0.0;
 
        try { duracion = stoi(campos[2]); }
        catch (...) { throw runtime_error("Duracion invalida en: " + nombre); }
 
        try { calif = stod(campos[4]); }
        catch (...) { throw runtime_error("Calificacion invalida en: " + nombre); }
 
        bool esEpisodio = ((int)campos.size() >= 10 && !campos[6].empty());
 
        if (esEpisodio)
        {
            string nomEp  = campos[6];
            string idEp   = campos[9];
            int temporada = 0;
            int numEp     = 0;
 
            try { temporada = stoi(campos[7]); }
            catch (...) { throw runtime_error("Temporada invalida en: " + nomEp); }
 
            try { numEp = stoi(campos[8]); }
            catch (...) { throw runtime_error("Num episodio invalido en: " + nomEp); }
 
            // Buscar serie existente sin find
            Serie* serieActual = nullptr;
            for (int i = 0; i < (int)seriesIds.size(); i++)
            {
                if (seriesIds[i] == id)
                {
                    serieActual = seriesPtr[i];
                    break;
                }
            }
 
            if (serieActual == nullptr)
            {
                serieActual = new Serie(id, nombre, genero);
                seriesIds.push_back(id);
                seriesPtr.push_back(serieActual);
                videos.push_back(serieActual);
            }
 
            Episodio* ep = new Episodio(idEp, nomEp, duracion, calif, fecha, numEp, temporada);
            serieActual->agregarEpisodio(ep);
        }
        else
        {
            Pelicula* p = new Pelicula(id, nombre, duracion, calif, fecha, genero);
            videos.push_back(p);
        }
    }
 
    if (videos.empty())
        throw runtime_error("El archivo no contiene datos validos.");
 
    cout << "Archivo cargado. Videos: " << videos.size() << endl;
}
 
void Menu::mostrarVideos(string genero)
{
    cout << "\n--- Videos con genero: " << genero << " ---" << endl;
    for (int i = 0; i < (int)videos.size(); i++)
        videos[i]->mostrarVideos(genero);
}
 
void Menu::mostrarVideosC(double calificacion)
{
    cout << "\n--- Videos con calificacion > " << calificacion << " ---" << endl;
    for (int i = 0; i < (int)videos.size(); i++)
        videos[i]->mostrarVideosC(calificacion);
}
 
void Menu::mostrarEpisodios(string nombreSerie)
{
    cout << "\n--- Episodios de: " << nombreSerie << " ---" << endl;
    for (int i = 0; i < (int)videos.size(); i++)
    {
        Serie* s = dynamic_cast<Serie*>(videos[i]);
        if (s != nullptr)
            s->mostrarEpisodio(nombreSerie);
    }
}
 
void Menu::mostrarPeliculas(double calificacion)
{
    cout << "\n--- Peliculas con calificacion > " << calificacion << " ---" << endl;
    for (int i = 0; i < (int)videos.size(); i++)
    {
        Pelicula* p = dynamic_cast<Pelicula*>(videos[i]);
        if (p != nullptr)
            p->mostrarPelicula(calificacion);
    }
}
 
void Menu::calificarVideo(string nombre, double calificacion)
{
    if (calificacion < 1.0 || calificacion > 10.0)
        throw std::invalid_argument("La calificacion debe estar entre 1 y 10.");
 
    for (int i = 0; i < (int)videos.size(); i++)
    {
        videos[i]->calificarVideo(nombre, calificacion);
    }
}