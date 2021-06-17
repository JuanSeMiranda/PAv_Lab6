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

bool Docente::noDictaAsignatura(string cod){
   // Rol* r =Rol::getAsignatura();
    list<Rol*>::iterator it;
    bool aux=true;

    for(it= this->roles.begin(); it != this->roles.end();it++){//++
       // if(!(*it)->getAsignatura()){// usurio inicil no tine rol ni asignatura por ende vos no le asignas ni una asignatura o rol
            if((*it)->getCodigoAsignatura()==cod){
                aux=false;
            }
       // }
    }
    return aux;
}

bool Docente::tieneMonitoreo(string codigo){
    bool retorno = false;
    list<Rol*>:: iterator it;
    for(it= this->roles.begin(); it!=this->roles.end(); it++){
        string cod = (*it)->getCodigoAsignatura();
        if(cod == codigo){
            if((*it)->getTipo() == MONITOREO)
                retorno = true;
        }
    }
    return retorno;
}


void Docente::agregarAsignatura(Rol* rol){
    this->roles.push_back(rol);
}

TipoRol Docente::decimeTuRol(string cod){
    list<Rol*>::iterator it=roles.begin();
    bool encontre=false;
    TipoRol retorno;
    while(it!=roles.end() && !encontre){
        if((*it)->getCodigoAsignatura()==cod){
            retorno=(*it)->getTipo();
            encontre=true;
        }
        it++;
    }
    return retorno;
}

void Docente:: eliminarAsignatura(string cod){
    list<Rol*>::iterator it;
    for(it = roles.begin(); it != roles.end(); ++it){
        bool esA = (*it)->esAsignatura(cod); // buscamos pav
        if(esA){// resivimos qque justo este rol coiside con la asignatura
            delete *it;
            //roles.remove(*it);
        }
    }
}

Docente::~Docente(){}