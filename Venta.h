//
// Created by felip on 12/10/2025.
//

#ifndef POOSISTEMAGESTIONVENTAS_VENTA_H
#define POOSISTEMAGESTIONVENTAS_VENTA_H

#include <iomanip>
#include <iostream>
#include <vector>
#include "Producto.h"

using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::cin;
using std::vector;
using std::getline;


class Venta {
private:

    vector<Producto *> productos;
    vector<long> cantidades;
    vector<double> precios;


public:

// Contructores y destructores:
    Venta() ;
    virtual ~Venta() ;

// Metodos:
void mostrarDatos();
void agregarLinea( Producto * producto, int cantidades, double precios);
void mostrarProductos();
double totalVentas();

};



#endif //POOSISTEMAGESTIONVENTAS_VENTA_H