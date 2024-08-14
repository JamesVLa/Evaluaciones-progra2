/* 
 * Proyecto: Clases
 * Archivo:  Usuario.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 29 de noviembre de 2021, 05:23 PM
 */


#ifndef USUARIO_H
#define USUARIO_H
#include <fstream>
using namespace std;

class Usuario {
private:
    int codigo;
    char tipo;
    char *nombre;
public:
    Usuario();
    Usuario(const Usuario &orig);
    virtual ~Usuario();
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator =(const Usuario &orig);
    
    // Lee una linea de la forma: 17750908E,Hernandez Barrios Emilio
    void leeDatos(ifstream &arch);
    
    // Imprime loa atributos: codigo, nombre y el tipo de ususario
    void imprimeDatos(ofstream &arch);
};

#endif /* USUARIO_H */

