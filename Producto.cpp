//
// Created by felip on 12/10/2025.
//

#include "Producto.h"

//Constructores:
Producto::Producto() {
    nombreProducto = "No tiene nombre";
    codigoProducto = "No tiene codigo";
    precioProducto = 0;
    cantidadProductos = 0;
}

Producto::Producto( string nombreProducto, string codigoProducto,
        long cantidadProductos, double precioProducto) {

    this->nombreProducto = nombreProducto;
    this->codigoProducto = codigoProducto;
    this->precioProducto = precioProducto;
    this->cantidadProductos = cantidadProductos;

}

// Sets y getters:

void Producto::setCodigoProducto(string codigoProducto) {
    this->codigoProducto = codigoProducto;
}
string Producto::getCodigoProducto() {
    return Producto::codigoProducto;
}


void Producto::setNombreProducto(string nombreProducto) {
    this->nombreProducto = nombreProducto;
}
string Producto::getNombreProducto() {
    return Producto::nombreProducto;
}


void Producto::setPrecioProducto(double precioProducto) {
    this->precioProducto = precioProducto;
}
double Producto::getPrecioProducto() {
    return precioProducto;
}


void Producto::setCantidadProductos(long cantidadProductos) {
    this->cantidadProductos = cantidadProductos;
}
long Producto::getCantidadProductos() {
    return cantidadProductos;
}

// Metodos:

void Producto::ajustarCantidad(int cantidad) {
    this->cantidadProductos += cantidad;
}

void Producto::mostrarDatos() {

     cout << "El nombre del producto es: " << nombreProducto << endl;
     cout << "El codigo del producto es: " << codigoProducto << endl;
     cout << "El precio del producto es: $" << precioProducto << endl;
     cout << "La cantidad en stock es: " << cantidadProductos << endl;
     cout << endl;


}

