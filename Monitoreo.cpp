#include "Monitoreo.h"

Monitoreo::Monitoreo(){}

Monitoreo::Monitoreo(int id, string nombre, DtTimeStamp* inicio,  DtTimeStamp* fin, string rutaVideo, Docente* docente, Estudiante* estudiante) : Clase(id, nombre, inicio, fin, rutaVideo, docente){
    estudiantes.insert(std::pair<string, Estudiante*>(estudiante->getEmail(), estudiante));
}

Monitoreo::~Monitoreo(){}