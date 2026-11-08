#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "inventario.h"
#include "producto.h"

using std::ifstream;
using std::stringstream;
using std::string;
using std::vector;
using std::endl;
using std::cout;

Inventario::Inventario()
{
    productos = {};
}

void Inventario::cargarCSV(string ruta)
{
    ifstream archivo;
    archivo.open(ruta);
    string linea;
    while(getline(archivo, linea))
    {
        string id, descripcion, precioStr, stockStr;
        
        stringstream split(linea);
        getline(split, id, ',');
        getline(split, descripcion, ',');
        getline(split, precioStr, ',');
        getline(split, stockStr, ',');
        
        double precio = stod(precioStr);
        int stock = stoi(stockStr);

        Producto p(id, descripcion, precio, stock);
        productos.push_back(p);
    }
    archivo.close();
}

vector<Producto> Inventario::getProductos()
{
    return productos;
}

void Inventario::disminuirStock(string id, int cantidad)
{
    for (auto& p : productos)
    {
        if (p.getId() == id)
        {
            int nuevoStock = p.getStock() - cantidad;
            if (nuevoStock < 0) nuevoStock = 0;
            p.setStock(nuevoStock);
            return;
        }
    }
}

void Inventario::imprimirInventario()
{
    cout << "SELECCIONAR PRODUCTO" << endl;

    for (size_t i = 0; i < productos.size(); i++)
    {
        cout << i << " : "
             << productos[i].getId() << "; "
             << productos[i].getDescripcion() << " "
             << productos[i].getPrecio()
             << endl;
    }

    cout << endl;
}