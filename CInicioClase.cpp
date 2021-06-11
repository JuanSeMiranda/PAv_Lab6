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
    this->inicioClase = ic;
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Docente* d = dynamic_cast<Docente*>(p);

    return d->tieneMonitoreo(ic->getCodigo());
}

list<string> CInicioClase::inscriptosAsignaturas(){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    map<string, Perfil*>:: iterator it;
    map<string, Perfil*> listaP = mP->listarPerfiles();
    list<string> retorno;

    for(it = listaP.begin(); it != listaP.end(); it++){
        if(Estudiante* estudiante = dynamic_cast<Estudiante*>(it->second)){
            if(estudiante->estaInscripto(this->inicioClase->getCodigo())){
                this->email = estudiante->getEmail();
            }
        }
        retorno.push_back(it->first);
    }

    
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

