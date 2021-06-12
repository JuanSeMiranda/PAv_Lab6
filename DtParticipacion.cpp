#include "DtParticipacion.h"

DtParticipacion::DtParticipacion(){}
DtParticipacion::DtParticipacion(int id, DtTimeStamp fecha, string mensaje){
    this->id = id;
    this->fecha = fecha;
    this->mensaje = mensaje;
}
int DtParticipacion::getId(){
    return this->id;
}
DtTimeStamp DtParticipacion::getFecha(){
    return this->fecha;
}
DtParticipacion::~DtParticipacion(){}