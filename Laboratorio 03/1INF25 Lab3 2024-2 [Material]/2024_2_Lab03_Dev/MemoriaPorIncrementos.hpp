#ifndef MEMORIAPORINCREMENTOS_HPP
#define MEMORIAPORINCREMENTOS_HPP

void cargar_estructuras(char ***&repartidores, int ***&clientes, double ***&subtotales, char ***cadenas, int **enteros, double **reales);

void reporte_de_repartidores(const char*nombre_archivo, char ***repartidores, int ***clientes, double ***subtotales);

void reporte_por_repartidor(char ***repartidores, int ***clientes, double ***subtotales);

#endif /* MEMORIAPORINCREMENTOS_HPP */

