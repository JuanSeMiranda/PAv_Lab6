#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"
#include "CAltaAsignatura.h"
#include "CAsistenciaAClaseEnVivo.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
        ICAltaAsignatura* getCAltaAsignatura();
        ICAsistenciaAClaseEnVivo* getCAsistenciaAClaseEnVivo();
};

#endif