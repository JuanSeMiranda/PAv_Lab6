#include "Fabrica.h"

ICAltaUsuario* Fabrica::getCAltaUsuario(){
    CAltaUsuario* cau = new CAltaUsuario();
    return cau;
}

ICAltaAsignatura* Fabrica::getCAltaAsignatura(){
    CAltaAsignatura* caa = new CAltaAsignatura();
    return caa;
}

ICAsignarAsignaturaDocente* Fabrica::getCAsignarAsignaturaDocente(){
    CAsignarAsignaturaDocente* caad = new CAsignarAsignaturaDocente();
    return caad;
}