```mermaid

classDiagram
   class Tienda{
    - vector productos
    - vector clientes 
    + void registrarProductos()
    + void realizarVenta( long cantidades, double precios)
    + void registrarCliente()
    + void mostrar/productos/clientes/ventas()
    + void llegadaProductos( )
    + void calcularTotalInventario()


   }

    class Producto{
        


        - long cantidadProducto
        - double precioProducto
        - String nombreProducto
        - String codigoProducto
        + void ajustarCantidad( int cantidad) 
        + gets/sets()
        + void mostrarDatos()
        
        

    }

    class Venta {
        - vector productos
        - vector cantidades
        - vector precios
       
        + double totalVentas()
        + void mostrarDatos()
        + void agregarLinea( Producto *, int cantidades, double precios)
        + void mostrarProductos()
    }

    class Cliente{
        - vector ventas
        
        + gets/sets()
        + void mostrarDatos()
        + void agregarVenta( Venta * venta)
        - String nombre
        - String ID

    }

    class Main{

    }

     Main "Usa "..> Tienda
     
     Tienda "Tiene" --o Cliente
     Tienda "Tiene" --o Producto
     Cliente "Tiene" --o Venta
     Venta "Tiene" --o Producto


```