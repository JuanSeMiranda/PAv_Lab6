#include "ManejadorPerfil.h"

ManejadorPerfil* ManejadorPerfil::instancia = NULL;

void ManejadorPerfil::add(Perfil* perfil){
    perfiles.insert(std::pair<string, Perfil*>(perfil->getEmail(), perfil));
}

ManejadorPerfil* ManejadorPerfil::getInstancia(){
    if(instancia == NULL){
        instancia = new ManejadorPerfil;
    }
    return instancia;
}

ManejadorPerfil::~ManejadorPerfil(){}