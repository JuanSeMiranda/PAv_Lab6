#ifndef ICINSCRIPCIONASIGNATURA
#define ICINSCRIPCIONASIGNATURA

#include <string>
#include <list>

using namespace std;

class ICInscripcionAsignatura{
    public:
        virtual list<string> asignaturasNoInscripto(string email)=0;
        virtual void selectAsignatura(string codigo)=0;
        virtual void inscribir()=0;
        virtual void cancelar()=0;
};

#endif