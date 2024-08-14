/* 
 * Proyecto: EX01_2021-1_Proy
 * Archivo:  BibCargaConductores.cpp
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 21 de mayo de 2021, 08:34 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "BibCargaConductores.h"
#define INCREMENTO 5;

void cargarConductores(int *&licencia, char **&conductor, char ***&placa){
    int numDat=0, tam=0, lic;
    char nombre[100],*nomb, **pl;
    
    ifstream arch("Conductores_Placa.csv", ios::in);
    if(!arch){
        cout<<"ERROR: No se pudo abrir el archivo Conductores_Placa.csv"<<endl;
        exit(1);
    }
    licencia = nullptr;
    conductor = nullptr;
    placa = nullptr;
    while(1){
        arch>>lic;
        if(arch.eof())break;
        arch.get();
        arch.getline(nombre,100,',');
        nomb = new char[strlen(nombre)+1];
        strcpy(nomb,nombre);
        pl = leePlacas(arch);
        if(numDat==tam) aumentarEspacios(licencia, conductor, placa, 
                                         numDat,tam);
        licencia[numDat] = 0;
        conductor[numDat] = nullptr;
        placa[numDat] = nullptr;
        
        licencia[numDat-1] = lic;
        conductor[numDat-1] = nomb;
        placa[numDat-1] = pl;
        
        numDat++;
    }
}

char **leePlacas(ifstream &arch){
    char *plac[20], **placa, *pl;
    int nd=0;
    while(1){
        pl = new char[8];
        arch.get(pl,8);
        plac[nd] = pl;
        nd++;
        if(arch.get()=='\n')break;
    }
    plac[nd] = nullptr;
    nd++;
    placa = new char*[nd];
    for(int i=0; i<nd; i++)
        placa[i] = plac[i];
    return placa;
}
void aumentarEspacios(int *&licencia, char **&conductor, char ***&placa, 
                      int &nd, int &t){
    int *auxL;
    char** auxC;
    char*** auxP;
    t += INCREMENTO;
    if (licencia == nullptr){
        licencia = new int[t];
        conductor = new char*[t];
        placa = new char**[t];
        licencia[0] = 0;
        conductor[0] = nullptr;
        placa[0] = nullptr;
        nd = 1;
    }
    else{
        auxL = new int[t];
        auxC = new char*[t];
        auxP = new char**[t];
        for(int i=0; i<nd; i++){
            auxL[i] = licencia[i];
            auxC[i] = conductor[i];
            auxP[i] = placa[i];
        }
        delete licencia;
        delete conductor;
        delete placa;
        licencia = auxL;
        conductor = auxC;
        placa = auxP;
    }
}

void reporteConductores(int *licencia, char **conductor, char ***placa){
    for (int i=0; licencia[i]; i++){
        cout<<left<<setw(10)<<licencia[i]<<conductor[i]<<endl;
        if(placa[i]) imprimePlacas(placa[i]);
    }
}

void imprimePlacas(char **placa){
    for(int i=0; placa[i]; i++)
        cout<<placa[i]<<endl;
}