#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){}

Sesion* Sesion::getInstancia(){
    if(instancia == NULL){
        instancia = new Sesion();
    }
    return instancia;
}

Perfil* Sesion::getPerfil(){
    return this->perfil;
}

void Sesion::setPerfil(Perfil* perfil){
    if(this->perfil == NULL)
        this->perfil = perfil;
    else
        cout << "ya existe un perfil asociado" << endl;
}

Sesion::~Sesion(){}