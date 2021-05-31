#include "Teorico.h"

Teorico::Teorico(){}

Teorico::Teorico(int cantAsistentes){
    this->cantAsistentes = cantAsistentes;
}

void Teorico::setCantAsistentes(int cantAsistentes){
    this->cantAsistentes = cantAsistentes;
}

int Teorico::getCantAsistentes(){
    return this->cantAsistentes;
}

Teorico::~Teorico(){}