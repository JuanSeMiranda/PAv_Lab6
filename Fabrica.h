#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"
#include "CAltaAsignatura.h"
#include "CAsistenciaAClaseEnVivo.h"
#include "CAsignarAsignaturaDocente.h"
#include "CEliminarAsignatura.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
        ICAltaAsignatura* getCAltaAsignatura();
        ICAsistenciaAClaseEnVivo* getCAsistenciaAClaseEnVivo();
        ICAsignarAsignaturaDocente* getCAsignarAsignaturaDocente();
        ICEliminarAsignatura* getCEliminarAsignatura();
};

#endif