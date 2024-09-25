#include "ConjuntoDePedidos.hpp"
#include "MemoriaPorIncrementos.hpp"

int main(int argc, char** argv) {
    ConjuntoDePedidos conjuntoDePedidos;
    cargar_conjunto_de_pedidos(conjuntoDePedidos, "pedidos.txt");
    conjuntoDePedidos++;
    
    int **enteros= conjuntoDePedidos.enteros;
    char ***cadenas = conjuntoDePedidos.cadenas;
    double **reales = conjuntoDePedidos.reales;
    
    char ***repartidores;
    int ***clientes;
    double ***subtotales;
    cargar_estructuras(repartidores, clientes, subtotales, cadenas, enteros, reales);  
    reporte_de_repartidores("reporte_repartidores.csv", repartidores, clientes, subtotales);
    reporte_por_repartidor(repartidores, clientes, subtotales);
    return 0;
}