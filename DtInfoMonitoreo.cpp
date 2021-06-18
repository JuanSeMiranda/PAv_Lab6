#include "DtInfoMonitoreo.h"

DtInfoMonitoreo::DtInfoMonitoreo(){}

DtInfoMonitoreo::DtInfoMonitoreo(int id, string nombre):DtInfoClase(id, nombre){
}

void DtInfoMonitoreo:: agregarEstudiante(string email){
	this->estudiantes.push_back(email);
}

DtInfoMonitoreo::~DtInfoMonitoreo(){}