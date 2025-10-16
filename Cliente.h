//
// Created by felip on 12/10/2025.
//

#ifndef POOSISTEMAGESTIONVENTAS_CLIENTE_H
#define POOSISTEMAGESTIONVENTAS_CLIENTE_H

#include <iomanip>
#include <iostream>
#include <vector>
#include "Venta.h"


using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::cin;
using std::vector;
using std::getline;




class Cliente {
private:
    string nombre;
    string id;
    vector <Venta *> ventas;


public:
//constructores y destructores:
    Cliente();
    Cliente(string nombre, string id);
    virtual ~Cliente() ;

// sets y gets:
    void setNombre(string nombre);
    string getNombre();

    void setId(string id);
    string getId();

// metodos:
    void mostrarDatos();
    void agregarVenta( Venta * venta);
    double calcularTotalCompras();


};




#endif //POOSISTEMAGESTIONVENTAS_CLIENTE_H