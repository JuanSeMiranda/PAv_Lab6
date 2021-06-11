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

list<string> CInicioClase::inscriptosAsignaturas(){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    map<string, Perfil*>:: iterator it;
    list<string> retorno;

    
    /*map<string, Perfil*> listaP = mP->listarPerfiles();
    
    for(it= listaP.begin(); it!=listaP.end(); it++){
        //como hago para acceder al perfil actual en el loop?
        if(dynamic_cast(it))
    }*/
    return retorno;
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
    //creo la clase c , como hay que hacer?
    //agrego la clase con mC->add(c)
    //hago un mC->find(DtIniciarClaseFull->getCodigo())
    //implemento la funcion agregarClase(Clase*) en Asignatura.h en le paso como parametro a c
}

CInicioClase::~CInicioClase(){}

