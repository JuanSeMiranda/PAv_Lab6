#include "DtInfoClase.h"
DtInfoClase::DtInfoClase(){}
DtInfoClase::DtInfoClase(int id, string nombre, Docente* docente){
    this->id = id;
    this->nombre = nombre;
    this->docente = docente;
}
/* esto no va
void DtInfoClase::agregarDocente(Docente* doc){
	this->docente = doc;
}*/

int DtInfoClase::getId(){
    return this->id;
}

string DtInfoClase::getNombre(){
    return this->nombre;
}

DtInfoClase::~DtInfoClase(){}