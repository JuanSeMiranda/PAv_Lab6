#include "Asignatura.h"

Asignatura:: Asignatura(){};

Asignatura:: Asignatura(string codigo, string nombre, map <int,Asignatura> clases){
    this->codigo = codigo;
    this->nombre = nombre;
    this->clases = clases;//desconfio
}

void Asignatura::setCodigo(string codigo){
    this->codigo = codigo;
}

void Asignatura::setNombre(string nombre){
    this->nombre = nombre;
}

void Asignatura::setClases(map<int,Asignatura>){
    //this->chan chan chaaaaaaaan
}

string Asignatura::getCodigo(){
    return this->codigo;
}

string Asignatura::getNombre(){
    return this->nombre;
}

map<int,Asignatura> Asignatura::getClases(){
    return this->clases;
}

Asignatura::~Asignatura(){}