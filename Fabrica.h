#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"
#include "CAltaAsignatura.h"
#include "CAsignarAsignaturaDocente.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
        ICAltaAsignatura* getCAltaAsignatura();
        ICAsignarAsignaturaDocente* getCAsignarAsignaturaDocente();
};

#endif