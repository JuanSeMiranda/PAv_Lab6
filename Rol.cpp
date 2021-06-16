#include "Rol.h"

Rol::Rol(){}

Rol::Rol(TipoRol tipo, Asignatura* asignatura){
    this->tipo = tipo;
    this->asignatura=asignatura; /*77777777777777777*/
}

TipoRol Rol::getRol(){
    return this->tipo;
}

void Rol::setRol(TipoRol tipo){
    this->tipo = tipo;
}

Asignatura* Rol::getAsignatura(){
    return this->asignatura;
}

void Rol::setAsignatura(Asignatura* asignatura){
    this->asignatura = asignatura;
}

string Rol::getCodigoAsignatura(){//creo que ya lo tiene dalto pero con getcodigo asignara
    return this->asignatura->getCodigo();
}


Rol::~Rol(){}