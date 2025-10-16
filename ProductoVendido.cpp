//
// Created by felip on 16/10/2025.
//

#include "ProductoVendido.h"

//Constructores y Destructores:

ProductoVendido::ProductoVendido() {
    producto = nullptr;
    cantidad = 0;
    precioUnitario = 0.0;
}

ProductoVendido::ProductoVendido(Producto* producto, int cantidad, double precioUnitario) {
    this->producto = producto;
    this->cantidad = cantidad;
    this->precioUnitario = precioUnitario;
}

ProductoVendido::~ProductoVendido() {
    // No eliminamos el producto porque pertenece a Tienda
    producto = nullptr;
}

// Getters y Setters:

void ProductoVendido::setProducto(Producto* producto) {
    this->producto = producto;
}

Producto* ProductoVendido::getProducto() {
    return producto;
}


void ProductoVendido::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int ProductoVendido::getCantidad() {
    return cantidad;
}


void ProductoVendido::setPrecioUnitario(double precioUnitario) {
    this->precioUnitario = precioUnitario;
}

double ProductoVendido::getPrecioUnitario() {
    return precioUnitario;
}

// Métodos:

double ProductoVendido::calcularSubtotal() {
    return cantidad * precioUnitario;
}

void ProductoVendido::mostrarDatos() {
    // Muestro los atributos del objeto.

    if (producto != nullptr) {
        cout << "Producto: " << producto->getNombreProducto() << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << std::fixed << std::setprecision(2);
        cout << "Precio Unitario: $" << precioUnitario << endl;
        cout << "Subtotal: $" << calcularSubtotal() << endl;
        cout << "---------------" << endl;
    }
}