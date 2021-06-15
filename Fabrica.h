#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"
#include "CInscripcionAsignatura.h"
#include "CInicioClase.h"
#include "CAltaAsignatura.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
        ICInscripcionAsignatura* getCInscripcionAsignatura();
        ICInicioClase* getCInicioClase();
        ICAltaAsignatura* getCAltaAsignatura();

};

#endif