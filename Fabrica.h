#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"
#include "CInscripcionAsignatura.h"
#include "CInicioClase.h"
#include "CAltaAsignatura.h"
#include "CEliminarAsignatura.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
        ICInscripcionAsignatura* getCInscripcionAsignatura();
        ICInicioClase* getCInicioClase();
        ICAltaAsignatura* getCAltaAsignatura();
        ICEliminarAsignatura* getCEliminarAsignatura();
};

#endif