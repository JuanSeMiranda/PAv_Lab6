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
        Perfil* find(string);
        static ManejadorPerfil* getInstancia();
        bool existePerfil(string);
        //IControlador* getIControlador();

        bool estaVacio();

        ~ManejadorPerfil();
};

#endif