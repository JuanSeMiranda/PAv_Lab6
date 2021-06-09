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
    //Crear una lista
    //Iterar en el map y agregar los cod en la lista
    //Retornar la lista.
}

ManejadorAsignatura::~ManejadorAsignatura(){}