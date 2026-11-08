#include <iostream>
#include <string>
#include "producto.h"

using std::endl;
using std::string;

Producto::Producto()
{
    id = "";
    descripcion = "";
    precio = 0.0;
    stock = 0;
}

Producto::Producto(string id, string d, double p, int s)
{
    this->id = id;
    this->descripcion = d;
    this->precio = p;
    this->stock = s;
}

string Producto::getId()
{
    return id;
}

string Producto::getDescripcion()
{
    return descripcion;
}

double Producto::getPrecio()
{
    return precio;
}

int Producto::getStock()
{
    return stock;
}

void Producto::setStock(int s)
{
    stock = s;
}