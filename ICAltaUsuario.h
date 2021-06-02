#ifndef ICALTAUSUARIO
#define ICALTAUSUARIO
#include "DtPerfil.h"

class ICAltaUsuario{
    public:
        virtual void ingresarDatosPerfil(DtPerfil*)=0;
        virtual void ingresarDocente(string)=0;
        virtual void ingresarEstudiante(string)=0;
        virtual void altaUsuario()=0;
};

#endif