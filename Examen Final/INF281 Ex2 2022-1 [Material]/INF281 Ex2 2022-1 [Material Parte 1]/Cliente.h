/* 
 * Proyecto: Preg01_Ex02_2022-1
 * Archivo:  Cliente.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 5 de julio de 2022, 05:42 PM
 */


#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
using namespace std;

class Cliente {
private:
    int dni;
    char *nombre;
    char tipo;
    int telefono;
    double descuento;
public:
    Cliente(); // Además de los punteros, pone en cero el descuento
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void operator = (const class Cliente &orig);
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    // Lee una línea de la forma:
    // 71984468,IPARRAGUIRRE VILLEGAS NICOLAS EDILBERTO B,935441620
    // NO coloca valores al al atributo "descuento"
    void leerDatos(ifstream &);
    // Imprime los atributos: dni, nombre, tipo y telefono
    void imprimirDatos(ofstream &);
};

#endif /* CLIENTE_H */

