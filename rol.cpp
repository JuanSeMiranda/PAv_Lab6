#include "rol.h"

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

Rol::~Rol(){}