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

list<string> Estudiante::asignaturaInscriptas(){
    map<string, Asignatura*>::iterator it;
    list<string> retorno;
    for(it = asignaturas.begin(); it != asignaturas.end(); ++it){
        retorno.push_back(it->first);
    }
    return retorno;
}

Estudiante::~Estudiante(){}