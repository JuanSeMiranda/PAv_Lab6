#include "Estudiante.h"
#include "ManejadorAsignatura.h"

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
    map<string, Asignatura*>:: iterator it;
    list<string> retorno;
    for(it= this->asignaturas.begin(); it!=this->asignaturas.end(); it++){
        retorno.push_back(it->first);
    }
    return retorno;
}

bool Estudiante::estaInscripto(string codigo){
    map<string, Asignatura*>::iterator it;
    return this->asignaturas.find(codigo) != this->asignaturas.end();
}

Estudiante::~Estudiante(){}