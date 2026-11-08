#include "streaming.h"
#include <iostream>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void Streaming::ejecutar()
{
    int opcion = 0;
    do {
        cout << "\n========= STREAMING =========\n";
        cout << "1. Cargar archivo de datos\n";
        cout << "2. Mostrar videos\n";
        cout << "3. Mostrar episodios de una serie\n";
        cout << "4. Mostrar peliculas por calificacion\n";
        cout << "5. Calificar un video\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore(1000, '\n');
        if (opcion != 6)
            ejecutarOpcion(opcion);
    } while (opcion != 6);

    cout << "Hasta luego." << endl;
}

void Streaming::ejecutarOpcion(int opcion)
{
    string entrada;
    double calificacion;

    if (opcion == 1)
    {
        cout << "Ruta del archivo: ";
        getline(cin, entrada);
        try
        {
            sistemaStreaming.cargarArchivo(entrada);
        }
        catch (std::exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    else if (opcion == 2)
    {
        int sub;
        cout << "1. Por calificacion\n2. Por genero\nOpcion: ";
        cin >> sub;
        cin.ignore(1000, '\n');
        if (sub == 1)
        {
            cout << "Calificacion minima: ";
            cin >> calificacion;
            cin.ignore(1000, '\n');
            sistemaStreaming.mostrarVideosC(calificacion);
        }
        else if (sub == 2)
        {
            cout << "Genero: ";
            getline(cin, entrada);
            sistemaStreaming.mostrarVideos(entrada);
        }
    }
    else if (opcion == 3)
    {
        cout << "Nombre de la serie: ";
        getline(cin, entrada);
        sistemaStreaming.mostrarEpisodios(entrada);
    }
    else if (opcion == 4)
    {
        cout << "Calificacion minima: ";
        cin >> calificacion;
        cin.ignore(1000, '\n');
        sistemaStreaming.mostrarPeliculas(calificacion);
    }
    else if (opcion == 5)
    {
        cout << "Nombre del video: ";
        getline(cin, entrada);
        cout << "Calificacion (1-10): ";
        cin >> calificacion;
        cin.ignore(1000, '\n');
        try
        {
            sistemaStreaming.calificarVideo(entrada, calificacion);
        }
        catch (std::exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}