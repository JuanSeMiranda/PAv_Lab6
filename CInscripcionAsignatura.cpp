#include "CInscripcionAsignatura.h"

CInscripcionAsignatura::CInscripcionAsignatura(){}

list<string> CInscripcionAsignatura::asignaturasNoInscripto(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Estudiante* e = dynamic_cast<Estudiante*>(p);
    list<string> asignaturasEstudiante = e->getAsignaturas();


    //continuar
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

void CInscripcionAsignatura::cancelar(){}
        
CInscripcionAsignatura::~CInscripcionAsignatura(){}