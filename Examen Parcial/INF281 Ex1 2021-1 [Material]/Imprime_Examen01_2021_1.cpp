/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Imprime_Examen01_2021_1.cpp
 * Author: cueva
 * 
 * Created on 20 de mayo de 2021, 09:45 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Imprime_Examen01_2021_1.h"

using namespace std;


void imprimecondreg(ofstream &arch,void *registro){
    void **laux = (void**)registro;
    int *licencia;
    char *nombre;
    
    licencia = (int*)laux[0];
    nombre = (char*)laux[1];
    
    arch <<left<<setw(20)<< *licencia << setw(20)<< nombre << endl;
    
}


void imprimeconductor(void *conductor){
    int i=0;
    void **laux = (void**)conductor;
    ofstream arch("repconductor.txt",ios::out);
    if(!arch){
        cout << "No se puede leer";
        exit(1);
    }

    while(1){
        if(laux[i]==NULL) break; 
        imprimecondreg(arch,laux[i]);
        i++;
    }
      
}
///////////////////////////////////////////////////////////////////////


void imprimefaltareg(ofstream &arch,void *registro){
    void **laux = (void**)registro;
    int *codigo;
    char *nombre;
    double *monto;
    
    codigo = (int*)laux[0];
    nombre = (char*)laux[1];
    monto = (double*)laux[2];
    
    arch <<left<<setw(20)<< *codigo << setw(200)<< nombre 
            << setprecision(2) << fixed << setw(20)<< *monto << endl;
    
}


void imprimefalta(void *falta){
    int i=0;
    void **laux = (void**)falta;
    ofstream arch("repfalta.txt",ios::out);
    if(!arch){
        cout << "No se puede leer";
        exit(1);
    }

    while(1){
        if(laux[i]==NULL) break; 
        imprimefaltareg(arch,laux[i]);
        i++;
    }
      
}

