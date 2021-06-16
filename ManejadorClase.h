#ifndef MANEJADORCLASE
#define MANEJADORCLASE
#include "Clase.h"
#include <list>

class ManejadorClase{
    private:
        static ManejadorClase* instancia;
        ManejadorClase();
        list <Clase*> clases;
    public:
        void add(Clase*);
        Clase* find(string);
        static ManejadorClase* getInstancia();
        bool existeClase(string);
        //IControlador* getIControlador();

        ~ManejadorClase();
};

#endif