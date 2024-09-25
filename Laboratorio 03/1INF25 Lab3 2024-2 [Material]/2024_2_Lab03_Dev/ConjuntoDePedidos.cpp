/* 
 * Archivo: ConjuntoDePedidos.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ConjuntoDePedidos.hpp"
#include "Pedido.hpp"
#include "Comunes.hpp"
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo) {
    ifstream archivo_de_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_pedidos, nombre_de_archivo);
    archivo_de_pedidos >> conjuntoDePedidos;
    archivo_de_pedidos.close();
}

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePedidos buffer_de_conjuntoDePedidos;
    inicializar_buffer_de_conjunto_de_pedidos(buffer_de_conjuntoDePedidos, 200);

    while (true) {
        Pedido pedido;
        bool continua_leyendo = archivo_de_pedidos >> pedido;
        if (not continua_leyendo)
            break;
        buffer_de_conjuntoDePedidos << pedido;
    }
    buffer_de_conjuntoDePedidos>>conjuntoDePedidos;
}

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad) {
    conjuntoDePedidos.enteros = new int*[cantidad];
    conjuntoDePedidos.cadenas = new char**[cantidad];
    conjuntoDePedidos.reales = nullptr;
    for (int i = 0; i < cantidad; i++) {
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    int dni = pedido.dni_cliente;
    int indice_cliente = buscar_cliente(buffer_de_conjuntoDePedidos, dni);
    if (indice_cliente == CLIENTE_NO_ENCONTRADO) {
        //el cliente no existe en el conjunto de datos, por lo tanto debe agregarse
        indice_cliente = obtener_cantidad_de_cliente(buffer_de_conjuntoDePedidos);

        int *bloque_de_enteros = new int[3];
        char **bloque_de_cadenas = new char*[2];

        bloque_de_enteros[0] = pedido.dni_cliente;
        bloque_de_enteros[1] = 1; //número de los diferentes tipos de platos que ha pedido el cliente
        bloque_de_enteros[2] = pedido.cantidad_platos;

        bloque_de_cadenas[0] = mi_strdup(pedido.codigo_repartidor);
        bloque_de_cadenas[1] = mi_strdup(pedido.codigo_plato);

        buffer_de_conjuntoDePedidos.enteros[indice_cliente] = bloque_de_enteros;
        buffer_de_conjuntoDePedidos.cadenas[indice_cliente] = bloque_de_cadenas;
    } else {

        //el cliente existe por lo tanto se agrega un plato
        int *bloque_de_enteros_antiguo = buffer_de_conjuntoDePedidos.enteros[indice_cliente];
        char **bloque_de_cadenas_antiguo = buffer_de_conjuntoDePedidos.cadenas[indice_cliente];

        int cantidad_tipos_de_platos = bloque_de_enteros_antiguo[1] + 1;
        int *bloque_de_enteros = new int[2 + cantidad_tipos_de_platos];
        char **bloque_de_cadenas = new char*[1 + cantidad_tipos_de_platos];

        //copiamos los datos del bloque antiguo al bloque nuevo
        for (int i = 0; i < 2 + cantidad_tipos_de_platos - 1; i++) {
            bloque_de_enteros[i] = bloque_de_enteros_antiguo[i];
        }
        bloque_de_enteros[1] = cantidad_tipos_de_platos;
        bloque_de_enteros[2 + cantidad_tipos_de_platos - 1] = pedido.cantidad_platos;

        for (int i = 0; i < 1 + cantidad_tipos_de_platos - 1; i++) {
            bloque_de_cadenas[i] = bloque_de_cadenas_antiguo[i];
        }
        bloque_de_cadenas[1 + cantidad_tipos_de_platos - 1] = mi_strdup(pedido.codigo_plato);

        //actualizamos los nuevos bloques en el buffer
        buffer_de_conjuntoDePedidos.enteros[indice_cliente] = bloque_de_enteros;
        buffer_de_conjuntoDePedidos.cadenas[indice_cliente] = bloque_de_cadenas;

        //liberamos los bloques antiguos
        delete bloque_de_enteros_antiguo;
        delete bloque_de_cadenas_antiguo;
    }
}

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    int cantidad = obtener_cantidad_de_cliente(buffer_de_conjuntoDePedidos);
    conjuntoDePedidos.enteros = new int*[cantidad + 1];
    conjuntoDePedidos.cadenas = new char**[cantidad + 1];
    conjuntoDePedidos.reales = nullptr;

    for (int i = 0; i < cantidad; i++) {
        conjuntoDePedidos.enteros[i] = buffer_de_conjuntoDePedidos.enteros[i];
        conjuntoDePedidos.cadenas[i] = buffer_de_conjuntoDePedidos.cadenas[i];
    }
    conjuntoDePedidos.enteros[cantidad] = nullptr;
    conjuntoDePedidos.cadenas[cantidad] = nullptr;
}

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni) {
    int i = 0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        int dni_del_bloque = bloque_de_enteros[0];
        if (dni_del_bloque == dni)
            return i;
        i++;
    }
    return CLIENTE_NO_ENCONTRADO;
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");

    int cantidad = obtener_cantidad_de_cliente(conjuntoDePedidos);
    conjuntoDePedidos.reales = new double*[cantidad];
    for (int i = 0; i < cantidad; i++) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        char **bloque_de_cadenas = conjuntoDePedidos.cadenas[i];
        int cantidad_tipos_de_platos = bloque_de_enteros[1];
        double *bloque_de_reales = new double[cantidad_tipos_de_platos + 1];

        double total = 0;
        for (int j = 0; j < cantidad_tipos_de_platos; j++) {
            char *codigo_del_plato = bloque_de_cadenas[1 + j];
            int cantidad_platos = bloque_de_enteros[2 + j];
            double precio_plato = conjuntoDePlatos += codigo_del_plato;
            double subtotal = cantidad_platos*precio_plato;
            bloque_de_reales[1 + j] = subtotal;
            total += subtotal;
        }
        bloque_de_reales[0] = total;
        conjuntoDePedidos.reales[i] = bloque_de_reales;
    }
    liberar_conjunto_de_platos(conjuntoDePlatos);
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    ++conjuntoDePedidos;
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {

}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos conjuntoDePlatos;
    cargar_conjunto_de_platos(conjuntoDePlatos, "platos.csv");

    int i = 0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        char **bloque_de_cadenas = conjuntoDePedidos.cadenas[i];
        int cantidad_tipos_de_platos = bloque_de_enteros[1];

        for (int j = 0; j < cantidad_tipos_de_platos; j++) {
            char *codigo_del_plato = bloque_de_cadenas[1 + j];
            char *nombre_del_plato = conjuntoDePlatos == codigo_del_plato;
            delete codigo_del_plato;
            bloque_de_cadenas[1 + j] = mi_strdup(nombre_del_plato);
        }
        i++;
    }
    liberar_conjunto_de_platos(conjuntoDePlatos);
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    int i = 0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        char **bloque_de_cadenas = conjuntoDePedidos.cadenas[i];
        double *bloque_de_reales = conjuntoDePedidos.reales[i];
        int dni_numero = bloque_de_enteros[0];
        int cantidad_tipos_de_platos = bloque_de_enteros[1];

        char nombre_archivo[30];
        obtener_nombre_archivo(nombre_archivo, dni_numero);
        ofstream archivo_del_comprobante;
        AperturaDeUnArchivoDeTextosParaEscribir(archivo_del_comprobante, nombre_archivo);

        imprimir_linea(archivo_del_comprobante);
        archivo_del_comprobante << setw(20) << right << "D.N.I. CLIENTE: " << dni_numero << endl;
        archivo_del_comprobante << setw(20) << right << "CODIGO REPARTIDOR: " << bloque_de_cadenas[0] << endl;
        imprimir_linea(archivo_del_comprobante);
        archivo_del_comprobante << "ITEM" << " PLATO" << setw(21) << "CANT" << " SUBTOTAL" << endl;
        imprimir_linea(archivo_del_comprobante, '-');
        for (int j = 0; j < cantidad_tipos_de_platos; j++) {
            archivo_del_comprobante << setw(2) << "" << setfill('0') << setw(2) << j + 1 << setfill(' ');
            archivo_del_comprobante << " " << setw(25) << left << setfill('.') << bloque_de_cadenas[1 + j] << setfill(' ');
            archivo_del_comprobante << bloque_de_enteros[2 + j] << setfill(' ');
            archivo_del_comprobante << " " << setw(5) << setprecision(2) << fixed << right << bloque_de_reales[1 + j];
            archivo_del_comprobante << endl;
        }
        imprimir_linea(archivo_del_comprobante, '-');
        archivo_del_comprobante << setw(31) << "SUBTOTAL: " << setw(6) << setfill('0') << right << bloque_de_reales[0] << setfill(' ') << endl;
        archivo_del_comprobante << setw(31) << "I.G.V.: " << setw(6) << setfill('0') << right << bloque_de_reales[0]*0.18 << setfill(' ') << endl;
        archivo_del_comprobante << setw(31) << "TOTAL: " << setw(6) << setfill('0') << right << bloque_de_reales[0] + bloque_de_reales[0]*0.18 << setfill(' ') << endl;
        imprimir_linea(archivo_del_comprobante);
        archivo_del_comprobante.close();
        i++;
    }
}

void obtener_nombre_archivo(char *nombre_archivo, int dni_numero) {
    char dni_cadena[9];
    mi_itoa(dni_numero, dni_cadena);
    strcpy(nombre_archivo, "comprobante/");
    strcat(nombre_archivo, dni_cadena);
    strcat(nombre_archivo, ".txt");
}

int obtener_cantidad_de_cliente(const ConjuntoDePedidos &conjuntoDePedidos) {
    int i = 0;
    while (conjuntoDePedidos.enteros[i] != nullptr)
        i++;
    return i;
}