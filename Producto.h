//
// Created by felip on 12/10/2025.
//

#ifndef POOSISTEMAGESTIONVENTAS_PRODUCTO_H
#define POOSISTEMAGESTIONVENTAS_PRODUCTO_H
#include <iostream>



using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::cin;

class Producto {
private:
    string nombreProducto;
    string codigoProducto;
    long cantidadProductos;
    double precioProducto;

public:
//Constructores:
    Producto();
    Producto(string nombreProducto, string codigoProducto,
        long cantidadProductos, double precioProducto);



// Sets y getters
void setNombreProducto(string nombreProducto);
string getNombreProducto();

void setCodigoProducto(string codigoProducto);
string getCodigoProducto();

void setCantidadProductos(long cantidadProductos);
long getCantidadProductos();

void setPrecioProducto(double precioProducto);
double getPrecioProducto();

//Metodos
void ajustarCantidad( int cantidad);

void mostrarDatos();



};



#endif //POOSISTEMAGESTIONVENTAS_PRODUCTO_H