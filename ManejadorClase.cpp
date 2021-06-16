#include "ManejadorClase.h"

ManejadorClase* ManejadorClase::instancia = NULL;

ManejadorClase::ManejadorClase(){}

void ManejadorClase::add(Clase* clase){
  
}

Clase* ManejadorClase::find(string clase){

}

ManejadorClase* ManejadorClase::getInstancia(){
    if(instancia == NULL){
        instancia = new ManejadorClase();
    }
    return instancia;
}

bool ManejadorClase::existeClase(string clase){


bool ManejadorClase::estaVacio(){
    return clases.empty();
}

ManejadorClase::~ManejadorClase(){}