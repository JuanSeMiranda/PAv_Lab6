#include "ManejadorAsignatura.h"

ManejadorAsignatura::ManejadorAsignatura(){}

ManejadorAsignatura* ManejadorAsignatura::instancia = NULL;

void ManejadorAsignatura::add(Asignatura* asignatura){
    asignaturas.insert(std::pair<string, Asignatura*>(asignatura->getCodigo(), asignatura));
}

Asignatura* ManejadorAsignatura::find(string codigo){
    map<string, Asignatura*>::iterator it;
    it = asignaturas.find(codigo);
    return it->second;
}

ManejadorAsignatura* ManejadorAsignatura::getInstancia(){
    if(instancia == NULL){
        instancia = new ManejadorAsignatura();
    }
    return instancia;
}

bool ManejadorAsignatura::existeAsignatura(string codigo){
    map<string, Asignatura*>::iterator it;
    return this->asignaturas.find(codigo) != this->asignaturas.end();
}

map<string, Asignatura*> ManejadorAsignatura::getAsignaturas(){
    map<string, Asignatura*> retorno;
    map<string, Asignatura*>::iterator it;
    for(it = asignaturas.begin(); it != asignaturas.end(); it++){
        retorno.insert(std::pair<string, Asignatura*>(it->first, it->second));
    }
    return retorno;
}

ManejadorAsignatura::~ManejadorAsignatura(){}