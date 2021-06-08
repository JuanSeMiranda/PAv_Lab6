#ifndef ICINICIOCLASE
#define ICINICIOCLASE
#include "DtPerfil.h" // lo necesita?

class ICInicioClase{
    public:
        virtual string* asignaturasAsignadas()=0;
        virtual bool selectAsignatura(DtIniciarClase*)=0;
        virtual string* inscriptosAsignaturas()=0;
        virtual void habilitar(string)=0;
        virtual DtIniciarClaseFull datosIngresados()=0;
        virtual void iniciarClase()=0;
};

#endif