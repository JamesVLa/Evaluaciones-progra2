/* 
 * Archivo: Comunes.cpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 23:33
 */

#include <cstring>
#include "Comunes.hpp"

using namespace std;

char *mi_strdup(const char *cadena) {
    int tamanho_cadena = strlen(cadena);
    char *bloque_nuevo = new char[tamanho_cadena + 1];
    strcpy(bloque_nuevo, cadena);
    return bloque_nuevo;
}

int *retorna_referencia_a_entero(int entero) {
    int *ptrEntero = new int;
    *ptrEntero = entero;
    return ptrEntero;
}

double *retorna_referencia_a_real(double real) {
    double *ptrReal = new double;
    *ptrReal = real;
    return ptrReal;
}

int obtener_cantidad_de_cliente(int **bloque_clientes) {
    int i = 0;
    while (bloque_clientes[i] != nullptr)
        i++;
    return i;
}

int obtener_cantidad_de_subtotales(double **bloque_subtotales) {
    int i = 0;
    while (bloque_subtotales[i] != nullptr)
        i++;
    return i;
}

void obtener_nombre_archivo_por_repartidor(char *nombre_archivo, char* codigo) {
    strcpy(nombre_archivo, "reportes/");
    strcat(nombre_archivo, codigo);
    strcat(nombre_archivo, ".txt");
}

void imprimir_linea(ofstream &archDeReporte, char c) {
    for (int i = 0; i < MAXIMO_POR_LINEA; i++)
        archDeReporte << c;
    archDeReporte << endl;
}

void mi_itoa(int numero, char *cadena) {
    int i = 0;
    while (numero != 0) {
        int digito = numero % 10;
        numero /= 10;
        cadena[i++] = '0' + digito;
    }
    invierte_cadena(cadena, 0, i - 1);
    cadena[i] = '\0';
}

void invierte_cadena(char *cadena, int inicio, int fin) {
    while (inicio < fin) {
        char aux = cadena[inicio];
        cadena[inicio] = cadena[fin];
        cadena[fin] = aux;
        fin--;
        inicio++;
    }
}