#include "DtInfoClase.h"
DtInfoClase::DtInfoClase(){}
DtInfoClase::DtInfoClase(int id, string nombre){
    this->id = id;
    this->nombre = nombre;
}
void DtInfoClase::agregarDocente(Docente* doc){
	this->docentes.push_back(doc->getEmail());
}
int DtInfoClase::getId(){
    return this->id;
}
string DtInfoClase::getNombre(){
    return this->nombre;
}
DtInfoClase::~DtInfoClase(){}