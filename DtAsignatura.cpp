#include "DtAsignatura.h"


DtAsignatura::DtAsignatura(){}
DtAsignatura::DtAsignatura(string nombre, string codigo, DtInstanciaClase tipoClases){
    this->nombre = nombre;
    this->codigo = codigo;
    this->tipoClases = tipoClases;
}
string DtAsignatura::getNombre(){
    return this->nombre;
}

string DtAsignatura::getCodigo(){
    return this->codigo;
}

DtInstanciaClase DtAsignatura:: getTipoClases(){
    return this->tipoClases;
}

DtAsignatura::~DtAsignatura(){}