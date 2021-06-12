#ifndef ICINSCRIPCIONASIGNATURA
#define ICINSCRIPCIONASIGNATURA

#include <string>
#include <list>

using namespace std;

class ICInscripcionAsignatura{
    public:
        virtual list<string> asignaturasNoInscripto(string)=0;
        virtual void selectAsignatura(string)=0;
        virtual void inscribir(string)=0;
        virtual void cancelar()=0;
};

#endif