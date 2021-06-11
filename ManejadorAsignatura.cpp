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

list<string> ManejadorAsignatura::listarAsignatura(){
    list<string> aux;
    for(map<string,Asignatura*>::iterator it = this->asignaturas.begin(); it != this->asignaturas.end(); it++)
        aux.push_back(it->first);
    return aux;
}

ManejadorAsignatura::~ManejadorAsignatura(){}
