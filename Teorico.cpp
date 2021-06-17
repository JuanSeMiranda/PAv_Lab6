#include "Teorico.h"

Teorico::Teorico(){}

Teorico::Teorico(int id, string nombre, DtTimeStamp* inicio, DtTimeStamp* fin, string rutaVideo, Docente* docente, int cantAsistentes) : Clase(id, nombre, inicio, fin, rutaVideo, docente){
    this->cantAsistentes = cantAsistentes;
}

void Teorico::setCantAsistentes(int cantAsistentes){
    this->cantAsistentes = cantAsistentes;
}

int Teorico::getCantAsistentes(){
    return this->cantAsistentes;
}

DtInfoTeorico* Teorico :: getDtInfoTeorico(){

	int cantidadA=0;
	map<string, Docente*>:: iterator it1;
	list<string>::iterator it2;
		
	for (it2 = this->asistentesEnVivo.begin(); it1 != this->asistentesEnVivo.end(); it2++){
		cantidadA++;
	}
	DtInfoClase* retorno= new DtInfoTeorico(this->getId(), this->getNombre(),cantidadA);

	for (it1 = this->docentes.begin(); i != this->docentes.end(); it1++){
		retorno->agregarDocente((*it1)->getEmail());
	}
	return retorno;

}



Teorico::~Teorico(){}