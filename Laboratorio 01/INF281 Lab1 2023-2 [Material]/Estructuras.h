/* 
 * Proyecto: Laboratorio_01_2023_2
 * Archivo:  Estructuras.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 29 de agosto de 2023, 06:16 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Producto{
    char codigo[8];
    char descripcion[60];
    double precio;
    int stock;
    int clientesServidos[20];
    int clientesNoServidos[20];
    int cantidadClientesServidos;
    int cantidadClientesNoServidos;
};

struct ProductoEntregado{
    char codigo[8];
    double precio;
};

struct Cliente{
    int dni;
    char nombre[60];
    int telefono;
    struct ProductoEntregado productosEntregados[20];
    int cantidadProductosEntrgados;
    double montoTotal;
};

struct Pedido{
    char CodigoProducto[8];
    int dniCliente;
    double precioProducto;
};

#endif /* ESTRUCTURAS_H */

