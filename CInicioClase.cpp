#include "CInicioClase.h"

CInicioClase::CInicioClase(){}

list<string> CInicioClase::asignaturasAsignadas(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Docente* d = dynamic_cast<Docente*>(p);
    return d->getAsignaturas();
}
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
                retorno.push_back(it->first);
            }
        }
    }
    return retorno;
}

void CInicioClase::habilitar(string email){
    //si la cantidad de habilitados es menor que 15
    this->habilitados.push_back(email);
    //habilitados.size()
}

DtIniciarClaseFull* CInicioClase::datosIngresados(){
    DtIniciarClaseFull* retorno = new DtIniciarClaseFull(inicioClase->getCodigo(), inicioClase->getNombre(), inicioClase->getFechaHora(), Clase::getIdAutogenerado()); //id es autogenerado
    this->data = retorno;
    return retorno;
}

void CInicioClase::iniciarClase(string email){
    ManejadorClase* mC = ManejadorClase::getInstancia();
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Docente* d = dynamic_cast<Docente*>(p);
    TipoRol tipo = d->decimeTuRol(this->inicioClase->getCodigo());
    if(tipo==TEORICO){
        Teorico* t = new Teorico(this->data->getId(), this->inicioClase->getNombre(), this->inicioClase->getFechaHora(), NULL, "ruta de video", d, 1);
    }else if(tipo==PRACTICO){

    }else if(tipo==MONITOREO){

    }
    //agrego la clase con mC->add(c)
    //hago un mC->find(DtIniciarClaseFull->getCodigo())
    //implemento la funcion agregarClase(Clase*) en Asignatura.h en le paso como parametro a c
}

void CInicioClase::cancelar(){
    delete inicioClase;
    delete data;
}

CInicioClase::~CInicioClase(){}

