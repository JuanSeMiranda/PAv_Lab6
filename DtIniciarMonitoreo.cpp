#include "DtIniciarMonitoreo.h"

DtIniciarMonitoreo::DtIniciarMonitoreo(){}

DtIniciarMonitoreo::DtIniciarMonitoreo(string codigo, string nombre, DtTimeStamp* fechaHora, int id):DtIniciarClaseFull(codigo, nombre, fechaHora){}

list<string> DtIniciarMonitoreo::getHabilitados(){
    return this->habilitados;
}

DtIniciarMonitoreo::~DtIniciarMonitoreo(){}