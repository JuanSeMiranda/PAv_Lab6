#ifndef DOCENTE
#define DOCENTE
#include <list>
#include "perfil.h"
#include "rol.h"

class Docente : public Perfil{
    private:
        string instituto;
        list <Rol> roles;//meter una coleccion de roles, con coso raro list o map
    public:
        Docente();
        Docente(string,string,string,string,string);
        void setInstituto(string);
        string getInstituto();

        ~Docente();
};

#endif