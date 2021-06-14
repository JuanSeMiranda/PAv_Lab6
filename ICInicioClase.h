#ifndef ICINICIOCLASE
#define ICINICIOCLASE
#include "DtPerfil.h" // lo necesita?
#include <list>

class ICInicioClase{
    public:
        virtual list<string> asignaturasAsignadas(string)=0;
        virtual bool selectAsignatura(DtIniciarClase*, string)=0;
        virtual list<string> inscriptosAsignaturas()=0;
        virtual void habilitar(string)=0;
        virtual DtIniciarClaseFull* datosIngresados()=0;
        virtual void iniciarClase()=0;
        virtual void cancelar()=0;
};

#endif