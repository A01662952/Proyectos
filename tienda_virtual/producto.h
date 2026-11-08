#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using std::string;

class Producto
{
    private:
    string id;
    string descripcion;
    double precio;
    int stock;

    public:
    Producto();
    Producto(string id, string d, double p, int s);
    string getId();
    string getDescripcion();
    double getPrecio();
    int getStock();
    void setStock(int s);
};
#endif