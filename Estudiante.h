#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include"Perfil.h"
#include "Asignatura.h"
#include <list>
#include <string>

using namespace std;

class Asignatura;

class Estudiante : public Perfil{
    private:
        string documento;
        list<Asignatura*> asignaturas;
    public:
        Estudiante();
        Estudiante(string,string,string,string,string);
        void setDocumento(string);
        string getDocumento();
        list<string> getAsignaturas();

        ~Estudiante();
};



#endif