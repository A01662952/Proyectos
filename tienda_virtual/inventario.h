#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>
#include "producto.h"

using std::vector;
using std::string;

class Inventario
{
    private:
    vector<Producto> productos;

    public:
    Inventario();
    void cargarCSV(string ruta);
    vector<Producto> getProductos();
    void disminuirStock(string id, int cantidad);
    void imprimirInventario();
};
#endif