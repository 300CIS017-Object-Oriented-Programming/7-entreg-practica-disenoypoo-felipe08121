//
// Created by felip on 12/10/2025.
//

#include "Tienda.h"

Tienda:: Tienda() {
   cout << "Se ingresa al constructor de la tienda. " << endl;
   inicializarProductos();
   cout << "Termina la inicializacion." << endl;

}

//Constructores y destructores:
void Tienda::inicializarProductos() {
    Producto * producto1 = new Producto();
    Producto * producto2 = new Producto();

    producto1 -> setNombreProducto("Margaritas");
    producto1 -> setCodigoProducto("Milo");
    producto1 -> setCantidadProductos(30);
    producto1 -> setPrecioProducto(8000);

    producto2 -> setNombreProducto("Coca Cola ");
    producto2 -> setCodigoProducto("zero");
    producto2 -> setCantidadProductos(80);
    producto2 -> setPrecioProducto(3000);

    productos.push_back(producto1);
    productos.push_back(producto2);

}

Tienda::~Tienda() {
    for (int i=0; i < productos.size(); i++) {
        delete productos[i];
    }

    for (int i=0; i < clientes.size(); i++) {
        delete clientes[i];
    }

    cout << "Se llama al destructor, se elimina todo y se termina " << endl;
}

//Metodos:

void Tienda::agregarProducto() {
     string nombre;
     string codigo;
     double precio;
     long cantidad;

    cout << "Ingrese el nombre del producto: " << endl;
    cin.ignore();
    getline( cin, nombre);

    cout << "Ingrese el codigo del producto: " << endl;
    cin.ignore();
    getline( cin, codigo);

    cout << "ingrese la cantidad del producto: "<< endl;
    cin >> cantidad;
    cout << "Ingrese el precio del producto: " << endl;
    cin >> precio;

    Producto *productoTemporal = new Producto();
    productoTemporal -> setNombreProducto(nombre);
    productoTemporal -> setCodigoProducto(codigo);
    productoTemporal -> setCantidadProductos(cantidad);
    productoTemporal -> setPrecioProducto(precio);
    productos.push_back( productoTemporal);

}


void Tienda::mostrarProductos() {

    cout << "************************+"<< endl;
    for (int i = 0; i < productos.size(); i++ ) {
     if (productos[i] != NULL){
         cout << "Detalles del producto: " << endl;
         productos[i] -> mostrarDatos();
     }
    }

    cout << "************************+"<< endl;
}


void Tienda::calcularTotalIventario() {
    double totalPrecio = 0;
    double totalCantidadProductos = 0;
    cout << "************************+"<< endl;
    for (int i = 0; i < productos.size(); i++) {
        cout << "Detalles producto: "<< endl;
        cout << "nombre: "<< productos[i] -> getNombreProducto() << endl;
        cout << "precio: "<< productos[i] -> getPrecioProducto() << endl;
        cout << "cantidad: " << productos[i] -> getCantidadProductos() << endl;
        cout << endl;
        totalPrecio = totalPrecio + ( (productos[i] -> getPrecioProducto() ) * productos[i] -> getCantidadProductos() );
        totalCantidadProductos += productos[i] -> getCantidadProductos();
    }
    cout << "Total de productos: " << totalCantidadProductos << endl;
    cout << std::fixed <<std::setprecision(2);
    cout << "Valor total de los productos: $" << totalPrecio << endl;

    cout << "************************+"<< endl;
}


void Tienda::registrarCliente() {
    string nombre;
    string id;


    cout << "=====Registrar nuevo cliente: =======" << endl;
    cout << "Ingrese el nombre del cliente: " << endl;
    cin.ignore();
    getline( cin, nombre);
    cout << "Ingrese el codigo del cliente: " << endl;
    cin.ignore();
    getline( cin, id);

    Cliente *clienteTemporal = new Cliente();
    clienteTemporal->setNombre(nombre);
    clienteTemporal->setId( id );

    clientes.push_back(clienteTemporal);
    cout << "El nuevo cliente fue registrado exitosamente. " << endl;


}


void Tienda::realizarVenta() {
     int opcionCliente;
     char continuar = 's';
     string codigo;
     int cantidad;


     if (clientes.empty()) {
         cout << "No clientes registrados encontrados. Registre un clientes primero" << endl;
         registrarCliente();
         return;
     }

    // Mostrar Clientes:

    cout << "Lista de Clientes: " << endl;
    for (int i = 0 ; i < clientes.size(); i++) {
        cout << i + 1 << ". " << clientes[i]->getNombre()<< "; ";
        cout << "ID: " << clientes[i]->getId() << endl;;
        cout << endl;
    }

   cout << "Seleccione el numero del cliente: " << endl;
    cin >> opcionCliente;

    if (opcionCliente < 1 || opcionCliente > clientes.size() ) {
        cout << "Cliente invalido. " << endl;
        return;
    }


    Cliente * clienteSeleccionado = clientes[opcionCliente - 1];
    Venta *  nuevaVenta = new Venta();

    while (continuar == 's' || continuar == 'S') {
        mostrarProductos();

        cout << "---- Ingrese el codigo del prodcuto: " << endl;
        cin.ignore();
        getline( cin, codigo);

        Producto * productoEncontrado = nullptr;

        for ( int i = 0; i < productos.size(); i++ ) {
            if ( codigo == productos[i]->getCodigoProducto() ) {
                productoEncontrado = productos[i];
                break;
            }

        }

        if (productoEncontrado == nullptr) {
            cout << "No se encontro el codigo del producto: " << endl;
            continue; // El continue sirve para que se salte este ciclo y continue
            // con el siguiente, asi de esa manera no tiene que empezar desde cero
            // entrando al menu y luego a la opcion de realizar ventas.
        }
        cout << "Ingrese la cantidad a comprar: " << endl;
        cin >> cantidad;

        if (cantidad > productoEncontrado->getCantidadProductos()) {
            cout << "Inventario Insuficientes. Cantidad Disponible: " <<
                productoEncontrado->getCantidadProductos() << endl;
            continue;
        }


        //agregar linea a la venta:
        nuevaVenta->agregarLinea( productoEncontrado, cantidad,
            productoEncontrado-> getPrecioProducto());

        // ajustar Inventario:

        productoEncontrado -> ajustarCantidad(-cantidad);
        cout << "\nProducto agregado a la venta. " << endl;
        cout << "Desea agregar otro producto? (s/n): ";
        cin >> continuar;


    }

    // mostrar resumen y agregar venta al cliente:
    nuevaVenta -> mostrarDatos();
    clienteSeleccionado->agregarVenta(nuevaVenta);

    cout << "\n Venta agregada exitosamente! " << endl;

}

void Tienda::mostrarClientes() {
    for ( int i = 0 ; i < clientes.size(); i++ ) {
        cout << "\n---Datos del cliente: ----" << endl;
        cout << i + 1 << ". " << clientes[i] -> getNombre() << endl;
        cout << "ID: " << clientes[i] -> getId() << endl;

    }

}

void Tienda::mostrarVentas() {
    for (int i = 0; i < clientes.size(); i++) {
        clientes[i]->mostrarDatos();
    }
}

void Tienda::llegadaProductos() {
    string codigo;
    char continuar = 's';
    int cantidad;
    mostrarProductos();
    Producto * productoEncontrado = nullptr;



    while ( continuar == 's' || continuar == 'S') {
        cout << "\n-------------Ingrese el codigo del producto: " ;
        cin.ignore();
        getline( cin, codigo);

        for( int i = 0; i < productos.size(); i++ ) {
            if ( codigo == productos[i]->getCodigoProducto() ) {
                productoEncontrado = productos[i];
                break;
            }
        }
        if ( productoEncontrado == nullptr ) {
            cout << "No se encontro el codigo del producto: " << endl;
            continue;
        }

        cout << "Ingrese la cantidad a agregar: " << endl;
        cin >> cantidad;

        if ( cantidad <=0 ) {
            cout << "Cantidad invalida par agregar. " << endl;
            continue;
        }
        else {
            productoEncontrado -> ajustarCantidad( cantidad );
        }

        cout << "\nCantidad agregada al inventario. " << endl;
        cout << "Desea aumentar el inventario de otor producto? (s/n): ";
        cin >> continuar;
    }

    //Mostrar los nuevos datos del producto;
    productoEncontrado->mostrarDatos();

}