//
// Created by felip on 16/10/2025.
//

#ifndef POOSISTEMAGESTIONVENTAS_PRODUCTOVENDIDO_H
#define POOSISTEMAGESTIONVENTAS_PRODUCTOVENDIDO_H

#include <iostream>
#include <iomanip>
#include "Producto.h"

using std::cout;
using std::endl;
using std::string;

class ProductoVendido {
private:
    Producto* producto;
    int cantidad;
    double precioUnitario;

public:
    // Constructores y destructores
    ProductoVendido();
    ProductoVendido(Producto* producto, int cantidad, double precioUnitario);
    virtual ~ProductoVendido();

    // Getters y Setters
    void setProducto(Producto* producto);
    Producto* getProducto();

    void setCantidad(int cantidad);
    int getCantidad();

    void setPrecioUnitario(double precioUnitario);
    double getPrecioUnitario();

    // Métodos
    double calcularSubtotal();
    void mostrarDatos();
};



#endif //POOSISTEMAGESTIONVENTAS_PRODUCTOVENDIDO_H