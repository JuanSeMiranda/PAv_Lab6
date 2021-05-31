#ifndef DOCENTE
#define DOCENTE
#include <list>
#include "Perfil.h"
#include "Rol.h"

class Rol;

class Docente : public Perfil{
    private:
        string instituto;
        list <Rol*> roles;
    public:
        Docente();
        Docente(string,string,string,string,string);
        void setInstituto(string);
        string getInstituto();

        ~Docente();
};

#endif