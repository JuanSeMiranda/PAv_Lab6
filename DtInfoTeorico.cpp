#include "DtInfoTeorico"


DtInfoTeorico::DtInfoTeorico(){}

DtInfoTeorico::DtInfoTeorico(int id, string nombre, int cantAsistentes):DtInfoClase(id, nombre){
    this->canAsistentes=cantAsistentes;
}

int DtInfoTeorico::getCantAsistentes(){
    return this->cantAsistentes;
}

DtInfoTeorico::~DtInfoTeorico(){}
