#include "CInicioClase.h"
#include "ManejadorClase.h"
#include "ManejadorPerfil.h"
#include "ManejadorAsignatura.h"

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
                retorno.push_back(it->first);
            }
        }
    }
    return retorno;
}

void CInicioClase::habilitar(string email){
    if(this->habilitados.size() < 15){
        this->habilitados.push_back(email);
        cout << "Estudiante habilitado con exito" << endl;
    }else{
        cout << "No pueden haber mas de 15 habilitados" << endl;
    }
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
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    Asignatura* a = mA->find(inicioClase->getCodigo());
    if(tipo==TEORICO){
        Teorico* t = new Teorico(this->data->getId(), this->inicioClase->getNombre(), this->inicioClase->getFechaHora(), NULL, "ruta de video", d, 1); //el ultimo parametro es la cantidad de asistentes
        mC->add(t);
        a->agregarClase(t);
    }else if(tipo==PRACTICO){
        Practico* p = new Practico(this->data->getId(), this->inicioClase->getNombre(), this->inicioClase->getFechaHora(), NULL, "ruta de video", d);
        mC->add(p);
        a->agregarClase(p);
    }else if(tipo==MONITOREO){
        Monitoreo* m = new Monitoreo(this->data->getId(), this->inicioClase->getNombre(), this->inicioClase->getFechaHora(), NULL, "ruta de video", d, this->habilitados);
        mC->add(m);
        a->agregarClase(m);
    }
}

void CInicioClase::cancelar(){
    delete inicioClase;
    delete data;
}

CInicioClase::~CInicioClase(){}

