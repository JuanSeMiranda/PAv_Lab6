#ifndef ROL
#define ROL
#include "TipoRol.h"

class Rol{
    private: 
        TipoRol tipo;
    public:
        Rol();
        Rol(TipoRol);
        TipoRol getRol();
        void setRol(TipoRol);
        ~Rol();
};

#endif