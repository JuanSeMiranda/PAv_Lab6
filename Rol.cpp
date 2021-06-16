#include "Rol.h"

Rol::Rol(){}

Rol::Rol(TipoRol tipo){
    this->tipo = tipo;
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

Rol::~Rol(){}