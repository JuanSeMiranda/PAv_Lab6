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
        TipoRol getRol();
        void setRol(TipoRol);
        Asignatura* getAsignatura();
        void setAsignatura(Asignatura* asignatura);

        ~Rol();
};

#endif