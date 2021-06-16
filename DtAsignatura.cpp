#include "DtAsignatura.h"


DtAsignatura::DtAsignatura(){}
DtAsignatura::DtAsignatura(string nombre, string codigo, DtInstanciaClase* tipoClases){
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

DtInstanciaClase* DtAsignatura:: getTipoClases(){
    return this->tipoClases;
}

ostream& operator << (ostream& salida, const DtAsignatura& asignatura){
    
    salida <<"Nombre de la Asignatura: " << asignatura.nombre << endl;
    cout << "Codigo de la Asignatura: " << asignatura.codigo << endl;
    cout << asignatura.tipoClases << endl;
    return salida;
}

DtAsignatura::~DtAsignatura(){}