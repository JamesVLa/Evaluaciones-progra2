/* 
 * Proyecto: EX01_2021-1_Proy
 * Archivo:  BibCargaConductores.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 21 de mayo de 2021, 08:33 AM
 */

#ifndef BIBCARGACONDUCTORES_H
#define BIBCARGACONDUCTORES_H

void cargarConductores(int *&, char **&, char ***&);
void reporteConductores(int *, char **, char ***);

char **leePlacas(ifstream &);
void aumentarEspacios(int*&, char**&, char***&,int&, int&);
void imprimePlacas(char **);

#endif /* BIBCARGACONDUCTORES_H */

