#include "Asignatura.h"

Asignatura:: Asignatura(){};

Asignatura:: Asignatura(string codigo, string nombre, DtInstanciaClase* tipoClases){
    this->codigo = codigo;
    this->nombre = nombre;
    this->tipoClases = tipoClases;
}

void Asignatura::setCodigo(string codigo){
    this->codigo = codigo;
}

void Asignatura::setNombre(string nombre){
    this->nombre = nombre;
}

string Asignatura::getCodigo(){
    return this->codigo;
}

string Asignatura::getNombre(){
    return this->nombre;
}

DtInstanciaClase* Asignatura::getTipoClases(){
    return this->tipoClases;
}

list<int> Asignatura::getClases(){
    map<int, Clase*> ::iterator it;
    list<int> retorno;
    for(it = clases.begin(); it != clases.end(); ++it){
        retorno.push_back(it->first);
    }
    return retorno;
}

bool Asignatura::tieneClases(){
    return clases.empty();
}

Asignatura::~Asignatura(){}