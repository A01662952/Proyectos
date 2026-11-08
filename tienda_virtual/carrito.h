#ifndef CARRITO_H
#define CARRITO_H

#include <vector>
#include <string>
#include "producto.h"

using std::vector;
using std::string;

class Carrito
{
    private:
    vector<Producto> productos;
    vector<int> cantidades;

    public:
    void agregar(Producto pro, int cantidad);
    void quitar(string id);
    vector<Producto> verProductos();
    double total();
    void vaciar();
    void imprimir();
};
#endif