#ifndef MANEJADORPERFIL
#define MANEJADORPERFIL
#include "Perfil.h"
#include <map>

class ManejadorPerfil{
    private:
        static ManejadorPerfil* instancia;
        ManejadorPerfil();
        map<string, Perfil*> perfiles;
    public:
        void add(Perfil*);
        static ManejadorPerfil* getInstancia();
        //IControlador* getIControlador();

        ~ManejadorPerfil();
};

#endif