#ifndef DOCENTE_H
#define DOCENTE_H
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

        bool noDictaAsignatura(string);//string cod //no creada /*77777777777777777777777*/
        void agregarAsignatura(Rol*);    /*77777777777777777777777*/

        ~Docente();
};

#endif