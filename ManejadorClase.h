#ifndef MANEJADORCLASE
#define MANEJADORCLASE
#include "Clase.h"
#include <list>
#include <map>

class ManejadorClase{
    private:
        static ManejadorClase* instancia;
        ManejadorClase();
        map<int, Clase*> clases;
    public:
        void add(Clase*);
        Clase* find(int);
        static ManejadorClase* getInstancia();
        bool existeClase(int);
        //IControlador* getIControlador();

        ~ManejadorClase();
};

#endif