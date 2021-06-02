#include "CAltaUsuario.h"

CAltaUsuario::CAltaUsuario(){}

void CAltaUsuario::ingresarDatosPerfil(DtPerfil* datosUsuario){
    this->datosUsuario = datosUsuario;
}

void CAltaUsuario::ingresarEstudiante(string doc){
    this->doc = doc;
}

void CAltaUsuario::ingresarDocente(string inst){
    this->inst = inst;
}

void CAltaUsuario::altaUsuario(){
    //implementar la funcion que pide el lab
}

CAltaUsuario::~CAltaUsuario(){}