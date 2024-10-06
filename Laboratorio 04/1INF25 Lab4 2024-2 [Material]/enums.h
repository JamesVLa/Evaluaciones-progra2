/* 
 * File:   enums.h
 * Author: erichuiza
 *
 * Created on September 25, 2024, 3:39 PM
 */

#ifndef ENUMS_H
#define ENUMS_H

using namespace std;

enum cps {
    invCodigo = 0,
    invNombre = 1,
    invCantDisponible = 2,
    invCantRequerida = 3,
    invUnidadMedida = 4, 
    
    bebCodigo = 0,
    bebNombre = 1,
    bebDescripcion = 2,
    bebTipo = 3,
    bebDisponible = 4,
    bebPrecio = 5, 
    bebCantVent = 6, 
    bebInsumoInv = 7,
    
    insCodigoInv = 0,
    insCant = 1,
    insUnidadMedida = 2
};

enum tam {
    invNumCampos = 5,
    bebNumCampos = 8,
    insNumCapos = 3,
    buffer = 200
};

#endif /* ENUMS_H */
