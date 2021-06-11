#include "Estudiante.h"

Estudiante::Estudiante(){}
Estudiante::Estudiante(string nombre ,string imagen_url ,string email ,string password, string documento)
                        :Perfil(nombre,imagen_url,email,password){
    this->documento = documento;
}
void Estudiante::setDocumento(string documento){
    this->documento = documento;
}
string Estudiante:: getDocumento(){
    return this->documento;
}

list<string> Estudiante::getAsignaturas(){
    list<Asignatura*>:: iterator it;
    list<string> retorno;
    for(it= this->asignaturas.begin(); it!=this->asignaturas.end(); it++){
        string cod = (*it)->getCodigo();
        retorno.push_back(cod);
    }
    return retorno;
}

Estudiante::~Estudiante(){}