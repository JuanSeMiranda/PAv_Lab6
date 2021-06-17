#ifndef ROL
#define ROL
#include "TipoRol.h"
#include "Asignatura.h"

class Asignatura;

class Rol{
    private: 
        TipoRol tipo;
        Asignatura* asignatura;
    public:
        Rol();
        Rol(TipoRol);
        TipoRol getTipo();
        void setTipo(TipoRol);
        Asignatura* getAsignatura();
        void setAsignatura(Asignatura* asignatura);

        string getCodigoAsignatura();

        ~Rol();
};

#endif