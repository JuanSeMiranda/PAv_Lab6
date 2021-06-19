#include "DtInfoMonitoreo.h"

DtInfoMonitoreo::DtInfoMonitoreo(){}

DtInfoMonitoreo::DtInfoMonitoreo(int id, string nombre, Docente* docente):DtInfoClase(id, nombre, docente){}

void DtInfoMonitoreo:: agregarEstudiante(string email){
	this->estudiantes.push_back(email);
}

DtInfoMonitoreo::~DtInfoMonitoreo(){}