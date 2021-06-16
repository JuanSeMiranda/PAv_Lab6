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


void Asignatura::agregarClase(Clase* clase){
    this->clases.insert(std::pair<int, Clase*>(clase->getId(), clase));
}

DtInstanciaClase* Asignatura::getTipoClases(){
    return this->tipoClases;

}

Asignatura::~Asignatura(){
    delete tipoClases;
    map<int, Clase*>::iterator it;
    for(it = clases.begin(); it != clases.end(); ++it){
        (*it).second->~Clase();
    }
}