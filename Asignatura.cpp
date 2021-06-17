#include "Asignatura.h"
#include "ManejadorClase.h"

Asignatura:: Asignatura(){};

Asignatura:: Asignatura(string codigo, string nombre){
    this->codigo = codigo;
    this->nombre = nombre;
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
n
map<int,DtInfoClase*> Asignatura:: getDtInfoClase(){
	ManejadorClase* mC = ManejadorClase::getInstancia();
	map<int, Clase*>:: iterator it;

	for (it = this->clases.begin(); it != this->clases.end(); it++){
	


	
	}


  }

Asignatura::~Asignatura(){}