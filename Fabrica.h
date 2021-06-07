#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
};

#endif