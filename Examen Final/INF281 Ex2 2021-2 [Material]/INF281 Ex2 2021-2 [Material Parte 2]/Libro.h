/* 
 * Proyecto: Clases
 * Archivo:  Libros.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 30 de noviembre de 2021, 08:31 PM
 */


#ifndef LIBROS_H
#define LIBROS_H
#include <fstream>
using namespace std;

class Libro {
private:
    char*codigo;
    char*titulo;
    char *autor;
    int agno;       // Año de publicación
    int cantidad;   // Cantidad de libros que tiene la biblioteca
    int prestados;  // Cantidad de libros prestados
    double precio;
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetPrestados(int prestados);
    int GetPrestados() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetAgno(int agno);
    int GetAgno() const;    
    void SetAutor(const char* autor);
    void GetAutor(char*) const;
    void SetTitulo(const char* titulo);
    void GetTitulo(char*) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;
    void operator =(const Libro& orig);
    
    // Lee una linea de la forma: 
    // ZM20053,The Fencing Master,Felicita Castillo Chung,1998,15,26.41
    void leeDatos(ifstream &arch);
    
    // Imprime los atributos: codigo, titulo, cantidad, prestados y precio ;
    void imprimeDatos(ofstream &arch);
};

#endif /* LIBROS_H */

