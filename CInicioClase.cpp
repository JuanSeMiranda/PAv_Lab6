#include "CInicioClase.h"
#include "ManejadorPerfil.h"

CInicioClase::CInicioClase(){}

list<string> CInicioClase::asignaturasAsignadas(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Docente* d = dynamic_cast<Docente*>(p);
    list<string> asign = d->asignaturas();
    return asign;
}
bool CInicioClase::selectAsignatura(DtIniciarClase* ic){}
string* CInicioClase::inscriptosAsignaturas(){}
void CInicioClase::habilitar(string algo){}
DtIniciarClaseFull CInicioClase::datosIngresados(){}
void CInicioClase::iniciarClase(){}
CInicioClase::~CInicioClase(){}

