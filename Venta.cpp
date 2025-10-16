//
// Created by felip on 12/10/2025.
//

#include "Venta.h"




// Constructor
Venta::Venta() {
    //Creo el objeto vacio
    productosVendidos = {};
}

Venta::~Venta() {
    // Modifico el destructor para borrar los Productos Vendidos

    for (int i = 0; i < productosVendidos.size(); i++) {
        if (productosVendidos[i] != nullptr) {
            delete productosVendidos[i];
            productosVendidos[i] = nullptr;
        }
    }
    productosVendidos.clear();
}

// Métodos
void Venta::agregarLinea(Producto* producto, int cantidad, double precio) {
    if (!producto || cantidad <= 0) {
        return;
    }

    // Reutilizo el agregarLinea de Venta

    ProductoVendido* productoVendido = new ProductoVendido(producto, cantidad, precio);
    productosVendidos.push_back(productoVendido);
}

void Venta::mostrarDatos() {
    cout << " ===== Detalle de la venta: ====== " << endl;
    double total = 0;
   //Uso el mostrar datos de ProductoVendido

    for (int i = 0; i < productosVendidos.size(); i++) {
        if (productosVendidos[i] != nullptr) {
            productosVendidos[i]->mostrarDatos();
            total += productosVendidos[i]->calcularSubtotal();
        }
    }

    cout << std::fixed << std::setprecision(2);
    cout << "---> Total en esta compra: $" << total << endl;
}

double Venta::totalVentas() {
    double total = 0;
    // lo mismo de arriba.
    for (int i = 0; i < productosVendidos.size(); i++) {
        if (productosVendidos[i] != nullptr) {
            total += productosVendidos[i]->calcularSubtotal();
        }
    }
    return total;
}

void Venta::mostrarProductos() {
    cout << " ------- Productos en esta Venta: " << endl;
    // lo mismo
    for (int i = 0; i < productosVendidos.size(); i++) {
        if (productosVendidos[i] != nullptr) {
            Producto* prod = productosVendidos[i]->getProducto();
            if (prod != nullptr) {
                cout << "-> " << prod->getNombreProducto() << endl;
                cout << "Cantidad: " << productosVendidos[i]->getCantidad() << endl;
                cout << "--------------------------" << endl;
            }
        }
    }
}