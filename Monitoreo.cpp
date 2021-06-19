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
	//la funcion esta bien, solo que pasa algo raro en DtInfoMonitoreo.h
	map<string, Estudiante*>::iterator it2;
	DtInfoClase* retorno = new DtInfoMonitoreo(this->getId(), this->getNombre(), this->getDocente());

	for (it2 = this->estudiantes.begin(); it2 != this->estudiantes.end(); it2++){
		retorno->agregarEstudiante((*it2)->getEmail());
	}
	return retorno;
}

Monitoreo::~Monitoreo(){}