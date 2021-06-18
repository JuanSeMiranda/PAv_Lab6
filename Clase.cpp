#include "Clase.h"

Clase::Clase(){}

int Clase:: idAutogenerado = 1;

int Clase:: getIdAutogenerado(){
    return idAutogenerado;
}

Clase::Clase(int id, string nombre, DtTimeStamp* inicio, DtTimeStamp* fin, string rutaVideo, Docente* docente){
    this->id = idAutogenerado;
    idAutogenerado++;
    this->nombre = nombre;
    this-> inicio = inicio;
    this->fin = fin;
    this->rutaVideo = rutaVideo;
    this->docente = docente;
}

void Clase::setId(int id){
    this->id = id;
}

int Clase::getId(){
    return this->id;
}

void Clase::setNombre(string nombre){
    this->nombre = nombre;
}

string Clase::getNombre(){
    return this->nombre;
}

void Clase::setInicio(DtTimeStamp* inicio){
    this->inicio = inicio;
}

DtTimeStamp* Clase::getInicio(){
    return this->inicio;
}

void Clase::setFin(DtTimeStamp* fin){
    this->fin = fin;
}

DtTimeStamp* Clase::getFin(){
    return this->fin;
}

void Clase::setRutaVideo(string rutaVideo){
    this->rutaVideo = rutaVideo;
}

string Clase::getRutaVideo(){
    return this->rutaVideo;
}

void Clase::insertarAsistenciaEnVivo(AsisteEnVivo* aev){
    asistentesEnVivo.push_back(aev);
}

Docente* Clase::getDocente(){
    return this->docente;
}

bool Clase::participaEstudiante(Estudiante* est){
    bool retorno = false;
    list<AsisteEnVivo*>::iterator it = asistentesEnVivo.begin();

    while(!retorno && (it != asistentesEnVivo.end())){
        it++;
        if((*it)->getEstudiante() == est)
            retorno = true;
    }
    return retorno;
}

DtInfoClase* Clase::getDtInfoClase(){
    list<string> docentes;
    docentes.push_back(this->docente->getEmail());
    DtInfoClase* dtif = new DtInfoClase(this->id, this->nombre, docentes);
    return dtif;
}

Clase::~Clase(){
    this->participaciones.clear();
    this->asistentesEnVivo.clear(); 
    this->asistentesDiferido.clear();
    
}