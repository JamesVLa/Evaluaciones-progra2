/* 
 * File:   Libro.h
 * Author: cueva
 *
 * Created on 8 de noviembre de 2021, 04:01 PM
 */
#include <fstream>

using namespace std;

#ifndef LIBRO_H
#define LIBRO_H

class Libro {
public:
    Libro(); //Implementado
    Libro(const Libro& orig); //Implementado
    virtual ~Libro(); //Implementado
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(char* );
    void GetCodigo(char *nom) const;
    void SetTitulo(char* );
    void GetTitulo(char *) const;
    void SetAutor(char* );
    void GetAutor(char *) const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void leelibros(ifstream &); //Lee todos los campos del archivo libros2.csv
    void imprimelibro(ofstream &); //Imprime los datos del libro necesarios
    void SetAnho(int anho);
    int GetAnho() const;
    void SetStock(int stock);
    int GetStock() const;
    
    Libro operator = (const Libro&); 
private:
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    int stock;
    int anho;
    double precio;
};


#endif /* LIBRO_H */

