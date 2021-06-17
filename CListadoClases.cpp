#include "CListadoClases.h"

CListadoClases::CListadoClases{}

list<string> CListadoClases::asignaturasAsignadas(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    Perfil* p = mP->find(email);
    Docente* d = dynamic_cast<Docente*>(p);
    return d->asignaturas();
}


map<int,DtInfoClase*> CLisadoClases::selectAsignatura(string cod){
	ManejadorAsignatura* mA= ManejadorAsignatura :: getInstancia();
	Asignatura* a = mA->asignaturas.find(cod);
    return a->getDtInfoClase();
}