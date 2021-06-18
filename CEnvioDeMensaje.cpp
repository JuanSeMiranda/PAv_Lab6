#include "CEnvioDeMensaje.h"


CEnvioDeMensaje::CEnvioDeMensaje(){}

void CEnvioDeMensaje::verificarPerfil(string email){
    ManejadorPerfil* mP = ManejadorPerfil::getInstancia();
    this->perfil = mP->find(email);

}

list<int> CEnvioDeMensaje::clasesOnLineAsistiendo(){
    ManejadorClase* mC = ManejadorClase::getInstancia();
    //ManejadorPerfil* mP = ManejadorPerfil::getInstancia(); no se usa
    map<int, Clase*>::iterator it;
    map<int, Clase*> listaC = mC->listarClases();
    list<int> retorno;

    if(Docente* d = dynamic_cast<Docente*>(this->perfil)){
        for(it = listaC.begin();it != listaC.end(); ++it){
            if(it->second->getDocente()==d)
                retorno.push_back(it->first);
        }

    }
    else if(Estudiante* e = dynamic_cast<Estudiante*>(this->perfil)){
        for(it = listaC.begin();it != listaC.end(); ++it){
            if(it->second->participaEstudiante(e))
                retorno.push_back(it->first);
        }
    }

    return retorno;
}

list<DtParticipacion*> CEnvioDeMensaje::selectClase(int id){
    this->id = id;

    list <DtParticipacion*> retorno;
    ManejadorClase* mC = ManejadorClase::getInstancia();
    Clase* c = mC->find(id);
    DtParticipacion* dtp;

    //list<Participacion*> listaP = c->getParticipaciones(); 

    return retorno;
}

void CEnvioDeMensaje::responder(int idp){}

void CEnvioDeMensaje::ingresarTexto(string txt){}

void CEnvioDeMensaje::enviarMensaje(){}

void CEnvioDeMensaje::cancelar(){}

CEnvioDeMensaje::~CEnvioDeMensaje(){}