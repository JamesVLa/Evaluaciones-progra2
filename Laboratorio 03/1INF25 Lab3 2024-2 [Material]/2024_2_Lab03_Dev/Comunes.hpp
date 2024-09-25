/* 
 * Archivo: Comunes.hpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 23:33
 */

#ifndef COMUNES_HPP
#define COMUNES_HPP
#include <fstream>
#define MAXIMO_POR_LINEA 60

using namespace std;

char *mi_strdup(const char *cadena);

int *retorna_referencia_a_entero(int entero);

double *retorna_referencia_a_real(double real);

int obtener_cantidad_de_cliente(int **bloque_clientes);

int obtener_cantidad_de_subtotales(double **bloque_subtotales);

void obtener_nombre_archivo_por_repartidor(char *nombre_archivo, char* codigo);

void imprimir_linea(ofstream &archDeReporte, char c = '=');

void invierte_cadena(char *cadena, int inicio, int fin);

void mi_itoa(int numero, char *cadena);

void obtener_nombre_archivo_por_repartidor(char *nombre_archivo, char* codigo);

#endif /* COMUNES_HPP */

