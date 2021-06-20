#include "Teorico.h"

Teorico::Teorico(){}

Teorico::Teorico(int cantAsistentes, int id, string nombre, DtTimeStamp* inicio, DtTimeStamp* fin, string rutaVideo, Docente* docente) : Clase(id, nombre, inicio, fin, rutaVideo, docente){
    this->cantAsistentes = cantAsistentes;
}

void Teorico::setCantAsistentes(int cantAsistentes){
    this->cantAsistentes = cantAsistentes;
}

int Teorico::getCantAsistentes(){
    return this->cantAsistentes;
}

DtInfoTeorico* Teorico::getDtInfoClase(){
	int cantidadA=0;
	list<AsisteEnVivo*>::iterator it2;
		
	for (it2 = this->getAsistentesEnVivo().begin(); it2 != this->getAsistentesEnVivo().end(); it2++){
		cantidadA++;
	}
	DtInfoTeorico* retorno= new DtInfoTeorico(this->getId(), this->getNombre(), this->getDocente(), cantidadA);
	
	return retorno;
}

Teorico::~Teorico(){}