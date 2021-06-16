#include "Fabrica.h"

ICAltaUsuario* Fabrica::getCAltaUsuario(){
    CAltaUsuario* cau = new CAltaUsuario();
    return cau;
}


ICInscripcionAsignatura* Fabrica::getCInscripcionAsignatura(){
    CInscripcionAsignatura* cia = new CInscripcionAsignatura();
    return cia;
}

ICInicioClase* Fabrica::getCInicioClase(){
    CInicioClase* cic = new CInicioClase();
    return cic;
}

ICAltaAsignatura* Fabrica::getCAltaAsignatura(){
    CAltaAsignatura* caa = new CAltaAsignatura();
    return caa;
}

ICEliminarAsignatura* Fabrica::getCEliminarAsignatura(){
    CEliminarAsignatura* cea = new CEliminarAsignatura();
    return cea;
}

