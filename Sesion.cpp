#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){}

Sesion* Sesion::getInstancia(){
    if(instancia == NULL){
        instancia = new Sesion();
    }
    return instancia;
}

Sesion::~Sesion(){}