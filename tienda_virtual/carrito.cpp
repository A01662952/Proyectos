#include "carrito.h"
#include <iostream>
#include <sstream>

using std::string;
using std::stringstream;
using std::vector;
using std::cout;
using std::endl;

void Carrito::agregar(Producto pro, int cantidad)
{
    //Si el producto ya estaba, aumentamos la cantidad
    for(size_t i = 0; i < productos.size(); i++)
    {
        if(productos[i].getId() == pro.getId())
        {
            cantidades[i] += cantidad;
            return;
        }
    }

    //Si no estaba, se añade
    productos.push_back(pro);
    cantidades.push_back(cantidad);
}

void Carrito::quitar(string id)
{
    for(size_t i = 0; i < productos.size(); i++)
    {
        if(productos[i].getId() == id)
        {
            productos.erase(productos.begin() + i);
            cantidades.erase(cantidades.begin() + i);
            break;
        }
    }
}

vector<Producto> Carrito::verProductos()
{
    return productos;
}

double Carrito::total()
{
    double suma = 0.0;
    for(size_t i=0; i < productos.size(); i++)
    {
        suma += productos[i].getPrecio() * cantidades[i];
    }
    return suma;
}

void Carrito::vaciar()
{
    productos.clear();
    cantidades.clear();
}

void Carrito::imprimir()
{
    if (productos.size() == 0)
    {
        cout << "El carrito está vacío." << endl;
        return;
    }

    for (size_t i = 0; i < productos.size(); i++)
    {
        cout << cantidades[i] << " "
            << productos[i].getDescripcion()
            << "  $" << productos[i].getPrecio() << endl;
    }
}
