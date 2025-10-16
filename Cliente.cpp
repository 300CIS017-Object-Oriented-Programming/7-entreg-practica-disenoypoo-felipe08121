//
// Created by felip on 12/10/2025.
//

#include "Cliente.h"

// Contructores y destructores:

Cliente::Cliente() {
    nombre = "Sin nombre";
    id = "Sin ID";
    ventas = {};
}

Cliente::Cliente(string nombre, string id) {
    this->nombre = nombre;
    this->id = id;
    ventas = {};
}


Cliente::~Cliente() {

    for (int i = 0; i < ventas.size(); i++) {
        if (ventas[i] != NULL) {
            delete ventas[i];
            ventas[i] = NULL;
        }
    }

    ventas.clear();

}

//getters y setters:

void Cliente::setNombre(string nombre) {
    this->nombre = nombre;
}
string Cliente::getNombre() {
    return Cliente::nombre;
}


void Cliente::setId(string id) {
    this->id = id;
}
string Cliente::getId() {
    return Cliente::id;
}


//Metodos:
void Cliente::mostrarDatos() {
    double Total = 0; //<----- otra forma de calcular el total de la venta.
    cout << "\n=======Datos del Cliente:=========" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "ID: " << id << endl;
    cout << "Numero de compras del cliente: " << ventas.size() << endl;

    if ( ventas.empty()) {
        cout << "\nEste Cliente aun no ha realizado compras." << endl;
    }
    else {
        cout << "\n-----------Historial de Compras--------------" << endl;
        for (int i = 0; i < ventas.size(); i++) {
            if (ventas[i] != NULL) {
                cout << "\n >>> Compra #" << i+1 << " <<<< " << endl;
                ventas[i]->mostrarDatos();
                Total += ventas[i]->totalVentas();
            }
        }
    }
    cout << std::fixed <<std::setprecision(2);
    cout << "----------------" << endl;
    cout << "---> Total de todas las compras del cliente: $" << Total << endl;
    cout << "----------------" << endl;

    cout << "================================" << endl;
}

void Cliente::agregarVenta( Venta * venta) {
    if (venta != NULL) {
        ventas.push_back(venta);
    }
}

double Cliente::calcularTotalCompras() {
    double total = 0;
    for (int i = 0; i < ventas.size(); i++) {
        if (ventas[i]!=NULL) {
            total += ventas[i]->totalVentas();
        }
    }
    return total;
}