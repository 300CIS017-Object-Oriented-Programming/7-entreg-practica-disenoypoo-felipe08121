//
// Created by felip on 12/10/2025.
//

#include "Venta.h"


#include "Venta.h"

// Constructor
Venta::Venta() {
    productosVendidos = {};
}

Venta::~Venta() {
    // ⭐ AHORA SÍ eliminamos ProductoVendido porque los creamos nosotros
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

    // ⭐ CREAMOS un objeto ProductoVendido
    ProductoVendido* productoVendido = new ProductoVendido(producto, cantidad, precio);
    productosVendidos.push_back(productoVendido);
}

void Venta::mostrarDatos() {
    cout << " ===== Detalle de la venta: ====== " << endl;
    double total = 0;

    // ⭐ USAMOS el método mostrarDatos() de ProductoVendido
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
    // ⭐ USAMOS el método calcularSubtotal() de ProductoVendido
    for (int i = 0; i < productosVendidos.size(); i++) {
        if (productosVendidos[i] != nullptr) {
            total += productosVendidos[i]->calcularSubtotal();
        }
    }
    return total;
}

void Venta::mostrarProductos() {
    cout << " ------- Productos en esta Venta: " << endl;
    // ⭐ ACCEDEMOS al producto a través de ProductoVendido
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