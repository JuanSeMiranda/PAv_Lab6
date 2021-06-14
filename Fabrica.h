#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"
#include "CInscripcionAsignatura.h"
#include "CInicioClase.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
        ICInscripcionAsignatura* getCInscripcionAsignatura();
        ICInicioClase* getCInicioClase();
};

#endif