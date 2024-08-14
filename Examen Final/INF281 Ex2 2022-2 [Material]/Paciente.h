/* 
 * Proyecto: Pregunta01_Examen02_2022-2
 * Archivo:  Paciente.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 23 de noviembre de 2022, 07:38 PM
 */


#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente {
private:
    int dni;
    char *nombre;
    int fechaUltimaConsulta;
public:
    Paciente();
    Paciente(const Paciente& orig);
    virtual ~Paciente();
    void SetFechaUltimaConsulta(int fechaUltimaConsulta);
    int GetFechaUltimaConsulta() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator = (const Paciente& orig);
};

#endif /* PACIENTE_H */

