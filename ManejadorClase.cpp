#include "ManejadorClase.h"

ManejadorClase* ManejadorClase::instancia = NULL;

ManejadorClase::ManejadorClase(){}

void ManejadorClase::add(Clase* clase){
    // ITERAR CON LISTAS
}

Clase* ManejadorClase::find(string clase){}
//PODER: CHANCLETAZO
//Nivel: 9999999

ManejadorClase* ManejadorClase::getInstancia(){
    if(instancia == NULL){
        instancia = new ManejadorClase();
    }
    return instancia;
}

bool ManejadorClase::existeClase(string clase){}

ManejadorClase::~ManejadorClase(){}