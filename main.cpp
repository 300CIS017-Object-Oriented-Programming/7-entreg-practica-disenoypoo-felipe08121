
#include <iostream>
#include "Tienda.h"

using std::cin;
using std::cout;
using std::string;

void mostrarMenuTienda(Tienda &tiendaMenu)
{
    int opc = 0;
    cout << "\n================ Opciones:  ================\n"<< endl;
    cout << "1. Agregar productos \n";
    cout << "2. Mostrar productos \n";
    cout << "3. Calcular el valor total del inventario \n";
    cout << "4. Registrar cliente \n";
    cout << "5. Realizar venta \n";
    cout << "6. Mostrar clientes  \n";
    cout << "7. Mostrar clientes y ventas.\n";
    cout << "8. Aumentar inventario de productos existentes.\n";
    cout << "-1. Volver\n" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opc;

    switch (opc){
     case 1: {
        tiendaMenu.agregarProducto();
        break;
     }

     case 2: {
        tiendaMenu.mostrarProductos();
        break;
     }

     case 3: {
        tiendaMenu.calcularTotalIventario();
        break;
     }

        case 4: {
         tiendaMenu.registrarCliente();
         break;
        }
        case 5: {
         tiendaMenu.realizarVenta();
         break;
        }
        case 6: {
         tiendaMenu.mostrarClientes();
         break;
        }

        case 7: {
         tiendaMenu.mostrarVentas();
         break;
        }
        case 8: {
         tiendaMenu.llegadaProductos();
         break;
        }
        default: {
         break;
    }

    }
}

void menu(Tienda &tiendaMenu)
{
    int opc = 0;
    do
    {
        cout << "\n *********Bienvenidos *********\n" << endl;
        cout << "1. Mostrar menu Tienda \n";
        cout << "-1. Salir \n";
        cout << "\nSeleccione una opcion:  ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            mostrarMenuTienda(tiendaMenu);
            break;
        default:
            break;
        }
    } while (opc != -1);
}

int main()
{

    Tienda tienda; // Instanciado con el stack
    menu(tienda);



    return 0;
}