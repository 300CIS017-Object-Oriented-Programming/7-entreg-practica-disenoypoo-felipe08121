//
// Created by felip on 12/10/2025.
//

#include "Venta.h"


// Constructor:
Venta::Venta() {
    productos = {};
    cantidades = {};
    precios = {};
}

//Metodos:

void Venta::agregarLinea(Producto *producto, int cantidad, double precio) {

    if ( !producto  || cantidad <= 0) {
        return;
    }

    productos.push_back( producto );
    cantidades.push_back(cantidad);
    precios.push_back(precio);
}

void Venta::mostrarDatos() {
    cout << " ===== Detalle de la venta: ====== " << endl;
    double total = 0;
    double subtotal = 0;

    for (int i = 0; i < productos.size(); i++) {
        cout << "Producto: " << productos[i]->getNombreProducto() << endl;
        cout << "Cantidades: " << cantidades[i] << endl;
        cout << "Precio Unitario: $" << precios[i] << endl;
        subtotal = cantidades[i] * precios[i];
        cout << "Subtotal: $" << subtotal << endl;
        cout << "---------------" << endl;
        total += subtotal;

    }
    cout << "Total de la venta: $" << total << endl;


}

double Venta::totalVentas() {
    double total = 0;
    for (int i = 0; i < cantidades.size(); i++) {
        total += cantidades[i] * precios[i];
    }
    return total;
}

void Venta::mostrarProductos() {
    cout << " ------- Productos en esta Venta: " << endl;
    for ( int i = 0; i < productos.size(); i++ ) {
        cout << "-> " << productos[i]->getNombreProducto() << endl;
        cout << "Cantidades: " << cantidades[i] << endl;
    }
}