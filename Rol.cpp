#include "Rol.h"

Rol::Rol(){}

Rol::Rol(TipoRol tipo){
    this->tipo = tipo;
}

TipoRol Rol::getTipo(){
    return this->tipo;
}

void Rol::setTipo(TipoRol tipo){
    this->tipo = tipo;
}

Asignatura* Rol::getAsignatura(){
    return this->asignatura;
}

void Rol::setAsignatura(Asignatura* asignatura){
    this->asignatura = asignatura;
}

string Rol::getCodigoAsignatura(){
    return this->asignatura->getCodigo();
}

bool Rol::esAsignatura(string cod){
    return (cod == asignatura->getCodigo());
}

Rol::~Rol(){
    delete asignatura;
}