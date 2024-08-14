/* 
 * Proyecto: Pregunta01_Examen02_2022-2
 * Archivo:  Medicina.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 23 de noviembre de 2022, 07:25 PM
 */


#ifndef MEDICINA_H
#define MEDICINA_H

class Medicina {
private:
    int codigo;
    char *descripcion;
    double precio;
public:
    Medicina();
    Medicina(const Medicina& orig);
    virtual ~Medicina();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char*) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void operator = (const Medicina& orig);
};

void operator >>(ifstream &, class Medicina&);
void operator <<(ofstream &,const class Medicina&);
#endif /* MEDICINA_H */

