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

bool Docente::noDictaAsignatura(string cod){/*77777777777777777777777*/
   // Rol* r =Rol::getAsignatura();
    list<Rol*>::iterator it;
    bool aux=true;

    for(it= this->roles.begin(); it != this->roles.end();++it){
       if((*it)->getCodigoAsignatura()==cod){
           aux=false;
       }
    }
    return aux;
}

void Docente::agregarAsignatura(Rol* rol){
    this->roles.push_back(rol);//desconfio
}

Docente::~Docente(){}