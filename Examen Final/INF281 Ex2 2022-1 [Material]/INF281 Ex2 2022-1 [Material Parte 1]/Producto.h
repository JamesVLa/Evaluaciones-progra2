/* 
 * Proyecto: Preg01_Ex02_2022-1
 * Archivo:  Producto.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 6 de julio de 2022, 07:58 AM
 */


#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>
using namespace std;

class Producto {
private:
    int codigo;
    char *descripcion;
    double descuento;
    double precioUnitario;
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void operator = (const class Producto &orig);
    void SetPrecioUnitario(double precioUnitario);
    double GetPrecioUnitario() const;
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char* descripcion) const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetCodigo(int codigo);
    int GetCodigo() const; 
    // Lee una línea de la forma:
    // 306824,FLAN LALA SABOR VAINILLA 100GR,5.88,
    // 186026,YOGHURT NATURAL LIGHT LALA 1KG,%4.7,25.86,  <==
    void leerDatos(ifstream &);
    // Imprime los atributos: codigo, descripción y precio unitario
    void imprimirDatos(ofstream &);
    
};

#endif /* PRODUCTO_H */

