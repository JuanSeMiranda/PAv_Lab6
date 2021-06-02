#include "Practico.h"

Practico::Practico(){}

Practico::Practico(int id, string nombre, DtTimeStamp inicio, DtTimeStamp fin, string rutaVideo, Docente* docente):Clase(id, nombre, inicio, fin, rutaVideo, docente){}

Practico::~Practico(){}