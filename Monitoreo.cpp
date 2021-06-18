#include "Monitoreo.h"

Monitoreo::Monitoreo(){}

Monitoreo::Monitoreo(int id, string nombre, DtTimeStamp* inicio,  DtTimeStamp* fin, string rutaVideo, Docente* docente, list<string> estudiantesList) : Clase(id, nombre, inicio, fin, rutaVideo, docente){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    list<string>::iterator it;
    for(it = estudiantesList.begin(); it != estudiantesList.end(); it++){
        Estudiante* e = dynamic_cast<Estudiante*>(mP->find(*it));
        estudiantes.insert(std::pair<string, Estudiante*>(e->getEmail(), e));
    }
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