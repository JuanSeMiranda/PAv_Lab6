#ifndef SESION
#define SESION
#include "Perfil.h"

class Sesion{ // creo que le faltan cosas
    private:
        static Sesion* instancia;
        Sesion();
        Perfil* perfil;
    public:
        static Sesion* getInstancia();
        ~Sesion();
};

#endif