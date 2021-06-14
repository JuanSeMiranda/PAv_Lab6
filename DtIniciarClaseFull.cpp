#include "DtIniciarClaseFull.h"

DtIniciarClaseFull::DtIniciarClaseFull(){}

DtIniciarClaseFull::DtIniciarClaseFull(string codigo, string nombre, DtTimeStamp* fechaHora):DtIniciarClase(codigo, nombre, fechaHora){
    //this->id = rand(); como hacer si en algun momento rand da un numero repetido
}

int DtIniciarClaseFull::getId(){
    return this->id;
}

DtIniciarClaseFull::~DtIniciarClaseFull(){}