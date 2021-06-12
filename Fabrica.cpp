#include "Fabrica.h"

ICAltaUsuario* Fabrica::getCAltaUsuario(){
    CAltaUsuario* cau = new CAltaUsuario();
    return cau;
}

ICAltaAsignatura* Fabrica::getCAltaAsignatura(){
    CAltaAsignatura* caa = new CAltaAsignatura();
    return caa;
}

ICEnvioDeMensaje* Fabrica:: getCEnvioDeMensaje(){
    CEnvioDeMensaje* cem = new CEnvioDeMensaje();
    return cem;
}

