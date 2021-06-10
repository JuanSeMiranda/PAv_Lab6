#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"
#include "CAltaAsignatura.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
        ICAltaAsignatura* getCAltaAsignatura();
};

#endif