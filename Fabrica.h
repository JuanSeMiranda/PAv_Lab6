#ifndef FABRICA
#define FABRICA
#include "CAltaUsuario.h"
#include "CAltaAsignatura.h"
#include "CAsistenciaAClaseEnVivo.h"
#include "CAsignarAsignaturaDocente.h"
#include "CEliminarAsignatura.h"
#include "CInicioClase.h"
#include "CInscripcionAsignatura.h"
#include "CListadoClases.h"

class Fabrica{
    public:
        ICAltaUsuario* getCAltaUsuario();
        ICAltaAsignatura* getCAltaAsignatura();
        ICAsistenciaAClaseEnVivo* getCAsistenciaAClaseEnVivo();
        ICAsignarAsignaturaDocente* getCAsignarAsignaturaDocente();
        ICEliminarAsignatura* getCEliminarAsignatura();
        ICInicioClase* getCInicioClase();
        ICInscripcionAsignatura* getCInscripcionAsignatura();
        ICListadoClases* getCListadoClases();
};

#endif