#include "ManejadorPerfil.h"

ManejadorPerfil* ManejadorPerfil::instancia = NULL;

void ManejadorPerfil::add(Perfil* perfil){
    perfiles.insert(std::pair<string, Perfil*>(perfil->getEmail(), perfil));
}

Perfil* ManejadorPerfil::find(string email){
    map<string, Perfil*>::iterator it;
    it = perfiles.find(email);
    return it->second;
}

ManejadorPerfil* ManejadorPerfil::getInstancia(){
    if(instancia == NULL){
        instancia = new ManejadorPerfil;
    }
    return instancia;
}

ManejadorPerfil::~ManejadorPerfil(){}