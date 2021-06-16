#include "CAsignarAsignaturaDocente.h"

CAsignarAsignaturaDocente::CAsignarAsignaturaDocente(){};

list<string> CAsignarAsignaturaDocente::listarAsignaturas(){
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    return mA->listarAsignatura();
}

list<string> CAsignarAsignaturaDocente::docentesSinLaAsignatura(string cod){//preguntar si el mail es para recorre cada uno de los perfiles
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    map<string, Perfil*>:: iterator it;
    map<string, Perfil*> listP = mP->listarPerfiles();
    list<string> aux;
    this->cod=cod;

    for(it = listP.begin(); it != listP.end(); ++it){
        Docente* d=dynamic_cast<Docente*>(it->second);
        if(d->noDictaAsignatura(cod)){
            aux.push_back(d->getEmail());
        }
    }
    
    return aux;
}

void CAsignarAsignaturaDocente::selectDocente(string email, TipoRol rol){
    this->rol=rol;
    this->email=email;
}//desconfio

void CAsignarAsignaturaDocente::asignarDocente(){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p=mP->find(email);
    Docente* d= dynamic_cast<Docente*>(p);

    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    Asignatura* a=mA->find(cod);

    Rol* r= new Rol(rol, a);//super desconfio
    d->agregarAsignatura(r);
}