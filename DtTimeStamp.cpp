#include"DtTimeStamp.h"


DtTimeStamp::DtTimeStamp(){}
DtTimeStamp::DtTimeStamp(DtFecha, int, int, int){}
DtFecha DtTimeStamp::getFecha(){
    return this->fecha;
}
int DtTimeStamp::getHora(){
    return this->hora;
}
int DtTimeStamp::getMinuto(){
    return this->minuto;
}
int DtTimeStamp::getSegundo(){
    return this->segundo;
}

DtTimeStamp::~DtTimeStamp(){}