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

Cliente::~Cliente() {
    for (int i = 0; i < ventas.size(); i++) {
        delete ventas[i];
    }

}

//getters y setters:

void Cliente::setNombre(string nombre) {
    Cliente::nombre = nombre;
}
string Cliente::getNombre() {
    return Cliente::nombre;
}


void Cliente::setId(string id) {
    Cliente::id = id;
}
string Cliente::getId() {
    return Cliente::id;
}


//Metodos:
void Cliente::mostrarDatos() {
    cout << "\n=======Datos del Cliente:=========" << endl;
    cout << "nombre: " << nombre << endl;
    cout << "id: " << id << endl;
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
            }
        }
    }
    cout << "================================" << endl;
}

void Cliente::agregarVenta( Venta * venta) {
    if (venta != NULL) {
        ventas.push_back(venta);
    }
}