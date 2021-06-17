#include "Monitoreo.h"

Monitoreo::Monitoreo(){}

Monitoreo::Monitoreo(int id, string nombre, DtTimeStamp* inicio,  DtTimeStamp* fin, string rutaVideo, Docente* docente, Estudiante* estudiante) : Clase(id, nombre, inicio, fin, rutaVideo, docente){
    estudiantes.insert(std::pair<string, Estudiante*>(estudiante->getEmail(), estudiante));
}

DtInfoClase* Monitoreo:: getDtInfoMonitoreo(){
	map<string, Docente*>:: iterator it1;
	map<string, Estudiante*>::iterator it2;
	
	
	DtInfoClase* retorno= new DtInfoMonitoreo(this->getId(), this->getNombre());

	for (it1 = this->docentes.begin(); it1 != this->docentes.end(); it1++){
		retorno->agregarDocente((*it1)->getEmail());
	}


	for (it2 = this->estudiantes.begin(); it2 != this->estudiantes.end(); it2++){
		retorno->agregarEstudiante((*it2)->getEmail());
	}
	return retorno;




}



Monitoreo::~Monitoreo(){}
