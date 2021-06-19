#include "DtInfoTeorico.h"


DtInfoTeorico::DtInfoTeorico(){}

DtInfoTeorico::DtInfoTeorico(int id, string nombre, Docente* docente, int cantAsistentes):DtInfoClase(id, nombre, docente){
    this->cantAsistentes=cantAsistentes;
}

int DtInfoTeorico::getCantAsistentes(){
    return this->cantAsistentes;
}

DtInfoTeorico::~DtInfoTeorico(){}