//
// Created by felip on 12/10/2025.
//

#include "Tienda.h"

Tienda:: Tienda() {
    cout << "\n====== ====================================== =====" << endl;
   cout << "Se ingresa al constructor de la tienda. " << endl;
    cout << "====== Inicializando el sistema de la tienda. =====" << endl;
    cout << "====== ====================================== =====" << endl;
   inicializarDatos();
   cout << "\n===== =========Termina la inicializacion.  ====== =====" << endl;
    cout << "====== ====================================== =====\n" << endl;

}

void Tienda::inicializarDatos() {
    cout << "\n[1/2] Inicializando productos..." << endl;
    inicializarProductos();

    cout << "\n[2/2] Inicializando clientes..." << endl;
    inicializarClientes();

}


//Constructores y destructores:
void Tienda::inicializarProductos() {


    Producto * producto1 = new Producto();
    producto1 -> setNombreProducto("Shampoo Organico");
    producto1 -> setCodigoProducto("SH001");
    producto1 -> setCantidadProductos(50);
    producto1 -> setPrecioProducto(15000);

    Producto * producto2 = new Producto();
    producto2 -> setNombreProducto("Jabon Artesanal");
    producto2 -> setCodigoProducto("JA001");
    producto2 -> setCantidadProductos(100);
    producto2 -> setPrecioProducto(5000);

    Producto * producto3 = new Producto();
    producto3 -> setNombreProducto("Cafe Organico");
    producto3 -> setCodigoProducto("CAF001");
    producto3 -> setCantidadProductos(75);
    producto3 -> setPrecioProducto(7500);

    Producto * producto4 = new Producto();
    producto4 -> setNombreProducto("Pastillas Naturales para Dormir");
    producto4 -> setCodigoProducto("PAST007");
    producto4 -> setCantidadProductos(40);
    producto4->setPrecioProducto(25000);

    Producto * producto5 = new Producto();
    producto5 -> setNombreProducto("Hierba de Gatos");
    producto5 -> setCodigoProducto("HIL001");
    producto5 -> setCantidadProductos(30);
    producto5 -> setPrecioProducto(8000);

    productos.push_back(producto1);
    productos.push_back(producto2);
    productos.push_back(producto3);
    productos.push_back(producto4);
    productos.push_back(producto5);

    cout << "     -> " << productos.size() << " productos cargados. "<< endl;

}

void Tienda::inicializarClientes() {

    //----> Cliente 1 :

    Cliente * cliente1 = new Cliente();
    cliente1->setNombre( "Juan Felipe Perafan" );
    cliente1->setId("1002213406");

    // Venta 1 del Cliente 1
    Venta * venta1_c1 = new Venta();
    venta1_c1 -> agregarLinea(productos[0], 2, productos[0]->getPrecioProducto());
    venta1_c1 -> agregarLinea(productos[1], 3, productos[1]->getPrecioProducto());
    cliente1->agregarVenta(venta1_c1);

    //Venta 2 del Cliente 1
    Venta * venta2_c1 = new Venta();
    venta2_c1 ->agregarLinea(productos[3], 5, productos[3]->getPrecioProducto());
    cliente1->agregarVenta(venta2_c1);

    clientes.push_back(cliente1);

    //-----> Cliente 2
    Cliente * cliente2 = new Cliente();
    cliente2->setNombre("John-117");
    cliente2->setId("SPARTAN-117");

    // Venta 1 del cliente 2
    Venta * venta1_c2 = new Venta();
    venta1_c2 -> agregarLinea(productos[2], 1, productos[2]->getPrecioProducto());
    venta1_c2 -> agregarLinea(productos[4], 2, productos[4]->getPrecioProducto());
    cliente2->agregarVenta(venta1_c2);

    clientes.push_back(cliente2);

    // ---> Cliente 3
    Cliente * cliente3 = new Cliente();
    cliente3->setNombre("Hu Tao");
    cliente3->setId("Funeraria el Camino");

    Venta * venta1_c3 = new Venta();
    venta1_c3 -> agregarLinea(productos[1], 10, productos[1]->getPrecioProducto());
    venta1_c3 -> agregarLinea(productos[3], 3, productos[3]->getPrecioProducto());
    cliente3->agregarVenta(venta1_c3);

    clientes.push_back(cliente3);

    cout << "     -> " << clientes.size() << " clientes cargados con historial de compras." << endl;
}


Tienda::~Tienda() {
    for (int i=0; i < productos.size(); i++) {
        if (productos[i] != NULL) {
            delete productos[i];
            productos[i] = NULL;
        }
    }

    productos.clear();

    for (int i=0; i < clientes.size(); i++) {
        if (clientes[i] != NULL) {
            delete clientes[i];
            clientes[i] = NULL;
        }
    }
    clientes.clear();

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


void Tienda::calcularTotalInventario() {
    double totalPrecio = 0;
    double totalCantidadProductos = 0;
    cout << "************************+"<< endl;
    for (int i = 0; i < productos.size(); i++) {
        cout << "Detalles del producto: "<< endl;
        cout << "nombre: "<< productos[i] -> getNombreProducto() << endl;
        cout << "precio: $"<< productos[i] -> getPrecioProducto() << endl;
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
    getline( cin, id);

    Cliente *clienteTemporal = new Cliente();
    clienteTemporal->setNombre(nombre);
    clienteTemporal->setId( id );

    clientes.push_back(clienteTemporal);
    cout << "El nuevo cliente fue registrado exitosamente. " << endl;


}


void Tienda::realizarVenta() {
     int opcionCliente;
     double totalVentas = 0;
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

        cout << "---- Ingrese el codigo del producto: " << endl;
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
        nuevaVenta->mostrarProductos();

        totalVentas = nuevaVenta->totalVentas();
        cout << std::fixed <<std::setprecision(2);
        cout << "-------- Total de las ventas: $" << totalVentas <<endl;

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
    Producto * productoEncontrado = nullptr;



    while ( continuar == 's' || continuar == 'S') {
        mostrarProductos();
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
            cout << "Cantidad invalida para agregar. " << endl;
            continue;
        }
        else {
            productoEncontrado -> ajustarCantidad( cantidad );
        }

        cout << "\nCantidad agregada al inventario. " << endl;
        //Mostrar los nuevos datos del producto;
        productoEncontrado->mostrarDatos();
        cout << "Desea aumentar el inventario de otor producto? (s/n): ";
        cin >> continuar;
    }


}

void Tienda::mostrarTotalVentasGlobal() {
    double totalVentas = 0;

    for (int i = 0; i < clientes.size(); i++) {
        totalVentas += clientes[i]->calcularTotalCompras();
    }

    cout << "\n========================================" << endl;
    cout << "Total de ventas realizadas en el sistema" << endl;
    cout << "========================================" << endl;
    cout << std::fixed << std::setprecision(2);
    cout << "-> Total: $" << totalVentas << endl;
    cout << "========================================\n" << endl;
}