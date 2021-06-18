#include "DtInfoTeorico.h"


DtInfoTeorico::DtInfoTeorico(){}

DtInfoTeorico::DtInfoTeorico(int id, string nombre, int cantAsistentes):DtInfoClase(id, nombre){
    this->cantAsistentes=cantAsistentes;
}

int DtInfoTeorico::getCantAsistentes(){
    return this->cantAsistentes;
}

DtInfoTeorico::~DtInfoTeorico(){}