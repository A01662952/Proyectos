#include <iostream>
#include "tienda.h"

using std::cout;
using std::cin;
using std::endl;

Tienda::Tienda(Inventario& inv) : inventario(inv) {}

void Tienda::mostrarMenu()
{
    int opcion = 0;

    while (opcion != 4)
    {
        cout << "*****  MENU PRINCIPAL  *****" << endl;
        cout << "1) Seleccionar producto" << endl;
        cout << "2) Ver carrito de compras" << endl;
        cout << "3) Terminar compra" << endl;
        cout << "4) Salir" << endl;
        cout << "Selecciona opcion: ";
        cin >> opcion;
        cout << endl;

        if (opcion == 1)
        {
            inventario.imprimirInventario();

            cout << "Ingrese el numero del producto: ";
            int indice;
            cin >> indice;

            auto productos = inventario.getProductos();

            if (indice < 0 || indice >= (int)productos.size())
            {
                cout << "Producto invalido." << endl << endl;
                continue;
            }

            Producto seleccionado = productos[indice];

            if (seleccionado.getStock() <= 0)
            {
                cout << "No hay stock disponible." << endl << endl;
                continue;
            }

            cout << "Cantidad a comprar: ";
            int cant;
            cin >> cant;

            if (cant <= 0)
            {
                cout << "Cantidad invalida." << endl << endl;
                continue;
            }

            if (cant > seleccionado.getStock())
            {
                cout << "No hay suficiente stock." << endl << endl;
                continue;
            }

            carrito.agregar(seleccionado, cant);
            inventario.disminuirStock(seleccionado.getId(), cant);

            cout << "Producto agregado al carrito." << endl << endl;
        }

        else if (opcion == 2)
        {
            carrito.imprimir();
            cout << endl;
        }

        else if (opcion == 3)
        {
            cout << "El total de tu compra es: $" << carrito.total() << endl;
            cout << "¡Gracias por comprar en MiTienditaAlexa.com!" << endl << endl;
            carrito.vaciar();
        }

        else if (opcion == 4)
        {
            break;
        }

        else
        {
            cout << "Opción inválida." << endl << endl;
        }
    }
}