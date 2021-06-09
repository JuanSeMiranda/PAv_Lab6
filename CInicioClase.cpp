#include "CInicioClase.h"
#include "ManejadorPerfil.h"
#include "ManejadorClase.h"

CInicioClase::CInicioClase(){}

string* CInicioClase::asignaturasAsignadas(){
    Sesion* sesion = Sesion::getInstancia();
    Perfil* docnt = sesion->getPerfil();
    //aiuuuda
}

bool CInicioClase::selectAsignatura(DtIniciarClase*){}

string* CInicioClase::inscriptosAsignaturas(){}

void CInicioClase::habilitar(string){}

DtIniciarClaseFull CInicioClase::datosIngresados(){}

void CInicioClase::iniciarClase(){}

CInicioClase::~CInicioClase(){}

/*
ManejadorPerfil* mP= ManejadorPerfil::getInstancia();
Perfil* doc=mP->find(email);*/