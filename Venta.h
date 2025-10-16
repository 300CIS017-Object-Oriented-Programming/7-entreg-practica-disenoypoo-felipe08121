//
// Created by felip on 12/10/2025.
//

#ifndef POOSISTEMAGESTIONVENTAS_VENTA_H
#define POOSISTEMAGESTIONVENTAS_VENTA_H

#include <iomanip>
#include <iostream>
#include <vector>
#include "Producto.h"
#include "ProductoVendido.h"

using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::cin;
using std::vector;

class Venta {
private:
    vector<ProductoVendido*> productosVendidos;

public:
    // Constructores y destructores
    Venta();
    virtual ~Venta();

    // Métodos
    void mostrarDatos();
    void agregarLinea(Producto* producto, int cantidad, double precio);
    void mostrarProductos();
    double totalVentas();
};



#endif //POOSISTEMAGESTIONVENTAS_VENTA_H