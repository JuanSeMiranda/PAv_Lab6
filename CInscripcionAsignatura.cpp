#include "CInscripcionAsignatura.h"

CInscripcionAsignatura::CInscripcionAsignatura(){}

list<string> CInscripcionAsignatura::asignaturasNoInscripto(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Estudiante* e = dynamic_cast<Estudiante*>(p);
    list<string> asign = e->getAsignaturas();

    //continuar
}

void CInscripcionAsignatura::selectAsignatura(string codigo){
    ManejadorAsignatura* mA = ManejadorAsignatura::getInstancia();
    Asignatura* a = mA->find(codigo);
}

void CInscripcionAsignatura::inscribir(){}

void CInscripcionAsignatura::cancelar(){}
        
CInscripcionAsignatura::~CInscripcionAsignatura(){}