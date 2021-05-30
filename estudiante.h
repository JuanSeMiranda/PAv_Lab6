#ifndef ESTUDIANTE
#define ESTUDIANTE
#include"Perfil.h"

#include<string>

class Estudiante : public Perfil{

    private:
        string documento;
    public:
        Estudiante();
        Estudiante(string,string,string,string,string);
        void setDocumento(string);
        string getDocumento();

        ~Estudiante();
};



#endif