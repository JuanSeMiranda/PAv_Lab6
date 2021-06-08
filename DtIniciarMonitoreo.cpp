#include "DtIniciarMonitoreo.h"

DtIniciarMonitoreo::DtIniciarMonitoreo(){}

DtIniciarMonitoreo::DtIniciarMonitoreo(string codigo, string nombre, DtTimeStamp fechaHora, int id, string* habilitados):DtIniciarClaseFull(codigo, nombre, fechaHora, id){
    this->habilitados = habilitados;
}

string* DtIniciarMonitoreo::getHabilitados(){
    return this->habilitados;
}

DtIniciarMonitoreo::~DtIniciarMonitoreo(){}