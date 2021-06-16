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

Monitoreo::~Monitoreo(){}