#include "Fabrica.h"

ICAltaUsuario* Fabrica::getCAltaUsuario(){
    CAltaUsuario* cau = new CAltaUsuario();
    return cau;
}

ICAltaAsignatura* Fabrica::getCAltaAsignatura(){
    CAltaAsignatura* caa = new CAltaAsignatura();
    return caa;
}

ICAsistenciaAClaseEnVivo* Fabrica::getCAsistenciaAClaseEnVivo(){
    CAsistenciaAClaseEnVivo* caacen = new CAsistenciaAClaseEnVivo();
    return caacen;
}

ICAsignarAsignaturaDocente* Fabrica::getCAsignarAsignaturaDocente(){
    CAsignarAsignaturaDocente* caad = new CAsignarAsignaturaDocente();
    return caad;
}

ICEliminarAsignatura* Fabrica::getCEliminarAsignatura(){
    CEliminarAsignatura* cea = new CEliminarAsignatura();
    return cea;
}

