/* 
 * Proyecto: EstructurasLab3_2022_2
 * Archivo:  Estructuras.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 13 de septiembre de 2022, 09:26 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct StCita{
    int codigoDelMedico;
    int fecha;  // Fecha en el formato AAAAMMDD
    double tarifaPorConsulta;
    char especialidad[50];   
};

struct StPaciente{
    int dni;
    char nombre[60];
	int telefono;
    struct StCita citas[20];
    int numeroDeCitas;
    double totalGastado;
};

struct StMedico{
    int codigo;
    char nombre[60];
    double tarifaPoxConsulta;
    char especialidad[50];
};

#endif /* ESTRUCTURAS_H */

