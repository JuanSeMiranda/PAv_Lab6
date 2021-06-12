#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include"Perfil.h"
#include "Asignatura.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class Asignatura;

class Estudiante : public Perfil{
    private:
        string documento;
        map<string, Asignatura*> asignaturas;
    public:
        Estudiante();
        Estudiante(string,string,string,string,string);
        void setDocumento(string);
        string getDocumento();
        list<string> getAsignaturas();
        bool estaInscripto(string);
        void agregarAsignatura(Asignatura*);

        ~Estudiante();
};



#endif