#ifndef ESTUDIANTE
#define ESTUDIANTE
#include"Perfil.h"
#include "Asignatura.h"
#include <map>
#include<string>

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

        ~Estudiante();
};



#endif