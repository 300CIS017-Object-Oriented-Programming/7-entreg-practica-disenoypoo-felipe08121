//
// Created by felip on 12/10/2025.
//

#ifndef POOSISTEMAGESTIONVENTAS_TIENDA_H
#define POOSISTEMAGESTIONVENTAS_TIENDA_H

#include <iomanip>
#include <iostream>
#include <vector>
#include "Producto.h"
#include "Cliente.h"




using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::cin;
using std::vector;
using std::getline;

class Tienda {
private:

    vector<Producto *> productos;
    vector<Cliente *> clientes;

    void inicializarClientes();
    void inicializarProductos();
    void inicializarDatos();

public:
//Constructores y Destructores:
    Tienda();
    virtual ~Tienda();


//Metodos:
    void agregarProducto( );
    void mostrarProductos( );
    void calcularTotalInventario();

    void realizarVenta();
    void registrarCliente();

    void mostrarClientes();
    void mostrarVentas();
    void llegadaProductos();


};



#endif //POOSISTEMAGESTIONVENTAS_TIENDA_H