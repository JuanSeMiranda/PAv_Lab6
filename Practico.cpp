#include "Practico.h"

Practico::Practico(){}

Practico::Practico(int id, string nombre, DtTimeStamp* inicio, DtTimeStamp* fin, string rutaVideo, Docente* docente):Clase(id, nombre, inicio, fin, rutaVideo, docente){}

DtInfoClase* Practico :: getDtInfoPractico(){
	map<string, Docente*>:: iterator it;

	DtInfoClase* retorno= new DtInfoClase(this->getId(), this->getNombre()); 
	for (it = this->docente.getEmail());
	}
	return retorno;
}

Practico::~Practico(){}