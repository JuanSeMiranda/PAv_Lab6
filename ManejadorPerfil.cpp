#include "ManejadorPerfil.h"

ManejadorPerfil::ManejadorPerfil(){}

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
        instancia = new ManejadorPerfil();
    }
    return instancia;
}

bool ManejadorPerfil :: existePerfil(string email){
    map<string, Perfil*>::iterator it;
    return this->perfiles.find(email) != this->perfiles.end();
}

bool ManejadorPerfil :: estaVacio(){
    return perfiles.empty();
}

ManejadorPerfil::~ManejadorPerfil(){}