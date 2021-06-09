#ifndef ICINICIOCLASE
#define ICINICIOCLASE
#include "DtPerfil.h" // lo necesita?
#include <list>

class ICInicioClase{
    public:
        virtual list<string> asignaturasAsignadas(string)=0;
        virtual bool selectAsignatura(DtIniciarClase*)=0;
        virtual string* inscriptosAsignaturas()=0;
        virtual void habilitar(string)=0;
        virtual DtIniciarClaseFull datosIngresados()=0;
        virtual void iniciarClase()=0;
};

#endif