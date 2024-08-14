/* 
 * Proyecto: Clases
 * Archivo:  RegistroPrestamo.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 30 de noviembre de 2021, 07:21 PM
 */

#ifndef REGISTROPRESTAMO_H
#define REGISTROPRESTAMO_H
#include <fstream>
using namespace std;

class RegistroPrestamo {
private:
    char *codigoLibro;
    int fecha;
public:
    RegistroPrestamo();
    RegistroPrestamo(const RegistroPrestamo& orig);
    virtual ~RegistroPrestamo();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCodigoLibro(const char* codigoLibro);
    void GetCodigoLibro(char*) const;
    void operator =(const RegistroPrestamo &orig);
    
    // Recibe una fecha (f) de la forma aaaammdd y determina la cantidad de 
    // días que hay entre f y el atributo fecha 
    int numeroDeDias(int f);
    
    //Convierte una fecha (f: aaaammdd) en día, mes, año
    void fTodma(int f, int&dd, int&mm, int&aa);
    
    // Devuelve la cantidad de días del mes según el año
    int diasDelMes(int mm,int aa);

    // Lee una linea de la forma: ZM20053,10/10/2021
    void leeDatos(ifstream &arch);
    
    // Imprime los atributos: codigoLibro y la fecha
    void imprimeDatos(ofstream &arch);
};

#endif /* REGISTROPRESTAMO_H */

