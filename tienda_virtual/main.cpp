#include <iostream>
#include <string>
#include "tienda.h"
#include "inventario.h"
#include "carrito.h"
#include "producto.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Inventario inv;
    inv.cargarCSV("inventario.csv");

    Tienda t(inv);
    t.mostrarMenu();
}