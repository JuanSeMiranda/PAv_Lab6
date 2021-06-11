#ifndef CINSCRIPCIONASIGNATURA
#define CINSCRIPCIONASIGNATURA

#include "ICInscripcionAsignatura.h"
#include "ManejadorPerfil.h"
#include "ManejadorAsignatura.h"
#include "Estudiante.h"

class CInscripcionAsignatura : public ICInscripcionAsignatura{
    private:
        string codigo;
    public:
        CInscripcionAsignatura();
        list<string> asignaturasNoInscripto(string);
        void selectAsignatura(string codigo);
        void inscribir();
        void cancelar();

        ~CInscripcionAsignatura();
};

#endif