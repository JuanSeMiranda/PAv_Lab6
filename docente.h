#ifndef DOCENTE
#define DOCENTE
#include "perfil.h"

class Docente : public Perfil{
    private:
        string instituto;
    public:
        Docente();
        Docente(string,string,string,string,string);
        void setInstituto(string);
        string getInstituto();

        ~Docente();
};

#endif