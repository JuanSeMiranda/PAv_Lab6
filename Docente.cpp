#include "Docente.h"

Docente::Docente(){}
Docente::Docente(string nombre, string imagen_url, string email, string password, string instituto): 
                 Perfil(nombre, imagen_url, email, password){
    this->instituto = instituto;
}

void Docente::setInstituto(string instituto){
    this->instituto = instituto;
}

string Docente::getInstituto(){
    return this->instituto;
}

list<string> Docente::asignaturas(){
    list<Rol*>:: iterator it;
    list<string> retorno;
    for(it= this->roles.begin(); it!=this->roles.end(); it++){
        string cod = (*it)->getCodigoAsignatura();
        retorno.push_back(cod);
    }
    return retorno;
}

Docente::~Docente(){}