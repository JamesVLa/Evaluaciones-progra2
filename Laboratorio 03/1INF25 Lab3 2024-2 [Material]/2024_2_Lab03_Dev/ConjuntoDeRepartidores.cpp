/* 
 * Archivo: ConjuntoDeRepartidores.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:44
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "ConjuntoDeRepartidores.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *nombre_de_archivo){
    ifstream archivo_de_repartidores;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_repartidores, nombre_de_archivo);
    archivo_de_repartidores >> conjuntoDeRepartidores;
    archivo_de_repartidores.close();
}

void operator>>(istream &archivo_de_repartidores, ConjuntoDeRepartidores &conjuntoDeRepartidores){   
    Repartidor buffer_repartidores[50];
    
    int i = 0;
    while (archivo_de_repartidores >> buffer_repartidores[i]) {
        i++;
    }
    conjuntoDeRepartidores.cantidad = i;
    conjuntoDeRepartidores.conjunto_de_datos = new Repartidor[conjuntoDeRepartidores.cantidad];

    for (i = 0; i < conjuntoDeRepartidores.cantidad; i++)
        conjuntoDeRepartidores.conjunto_de_datos[i] = buffer_repartidores[i];
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    
}

char* operator==(const ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *codigo) {
    for (int i = 0; i < conjuntoDeRepartidores.cantidad; i++) {
        if (strcmp(conjuntoDeRepartidores.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDeRepartidores.conjunto_de_datos[i].nombre;
    }
    return nullptr;
}