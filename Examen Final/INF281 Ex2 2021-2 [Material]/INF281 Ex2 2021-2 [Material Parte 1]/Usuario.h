/* 
 * File:   usuario.h
 * Author: cueva
 *
 * Created on 8 de noviembre de 2021, 03:16 PM
 */

#include <fstream>

using namespace std;

#ifndef USUARIO_H
#define USUARIO_H


class Usuario {
public:
    Usuario();  //Implementado
    Usuario(const Usuario& orig); //Implementado
    virtual ~Usuario();  //Implementado
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCarne(int carne);
    int GetCarne() const;
    void SetNombre(char* );
    void GetNombre(char *) const;
    virtual void leer(ifstream &)=0;
    virtual void imprime(ofstream &); //Imprime los datos necesarios del usuario
private:
    int carne;
    char tipo;
    char *nombre;
};



#endif /* USUARIO_H */



