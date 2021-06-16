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

