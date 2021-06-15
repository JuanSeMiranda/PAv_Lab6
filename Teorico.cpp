#include "Teorico.h"

Teorico::Teorico(){}

Teorico::Teorico(int id, string nombre, DtTimeStamp* inicio, DtTimeStamp* fin, string rutaVideo, Docente* docente, int cantAsistentes) : Clase(id, nombre, inicio, fin, rutaVideo, docente){
    this->cantAsistentes = cantAsistentes;
}

void Teorico::setCantAsistentes(int cantAsistentes){
    this->cantAsistentes = cantAsistentes;
}

int Teorico::getCantAsistentes(){
    return this->cantAsistentes;
}

Teorico::~Teorico(){}