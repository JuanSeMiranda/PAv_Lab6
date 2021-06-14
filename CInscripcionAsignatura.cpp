#include "CInscripcionAsignatura.h"

CInscripcionAsignatura::CInscripcionAsignatura(){}

list<string> CInscripcionAsignatura::asignaturasNoInscripto(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Estudiante* e = dynamic_cast<Estudiante*>(p);
    map<string, Asignatura*> asignaturasEstudiante = e->getAsignaturas();

    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    map<string, Asignatura*> asignaturas = mA->getAsignaturas();

    list<string> retorno;
    map<string, Asignatura*>::iterator it1;
    map<string, Asignatura*>::iterator it2;
    for(it1 = asignaturas.begin(); it1 != asignaturas.end(); it1++){
        bool repetido = false;
        for(it2 = asignaturas.begin(); it2 != asignaturas.end(); it2++){
            if(it1->first == it2->first){
                repetido == true;
            }
        }
        if(!repetido){
            retorno.push_back(it1->first);
        }
    }

    return retorno;
}

void CInscripcionAsignatura::selectAsignatura(string codigo){
    this->codigo = codigo;
}

void CInscripcionAsignatura::inscribir(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Estudiante* e = dynamic_cast<Estudiante*>(p);

    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    Asignatura* a = mA->find(this->codigo);
    
    e->agregarAsignatura(a);
}

void CInscripcionAsignatura::cancelar(){
    //no hace nada porque la clase no reserva memoria dinamica en niguno de sus atributos
}
        
CInscripcionAsignatura::~CInscripcionAsignatura(){}