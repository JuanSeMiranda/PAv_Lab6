#include "CInicioClase.h"

CInicioClase::CInicioClase(){}

list<string> CInicioClase::asignaturasAsignadas(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Docente* d = dynamic_cast<Docente*>(p);
    list<string> asign = d->asignaturas();
    return asign;
}

bool CInicioClase::selectAsignatura(DtIniciarClase* ic, string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Docente* d = dynamic_cast<Docente*>(p);

    return d->tieneMonitoreo(ic->getCodigo());
}

string* CInicioClase::inscriptosAsignaturas(){
    /*ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    map<string, Perfil*>:: iterator it;
    for(it= mP->perfiles.begin(); it!=mP->perfiles.end(); it++){

    }*/
}

void CInicioClase::habilitar(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Estudiante* e = dynamic_cast<Estudiante*>(p);
}

DtIniciarClaseFull CInicioClase::datosIngresados(){
    //como accedo a el int id de DtIniciarClaseFull?
    
}

void CInicioClase::iniciarClase(){
    ManejadorClase* mC = ManejadorClase::getInstancia();
    //creo la clase c 
    //agrego la clase con mC->add(c)
    //hago un mC->find(DtIniciarClaseFull->getCodigo())
    //implemento la funcion agregarClase(Clase*) en Asignatura.h en le paso como parametro a c
}

CInicioClase::~CInicioClase(){}

