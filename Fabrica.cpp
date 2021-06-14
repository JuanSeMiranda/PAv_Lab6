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