#ifndef MANEJADORCLASE
#define MANEJADORCLASE
#include "Clase.h"
#include <list>
#include <map>

class ManejadorClase{
    private:
        static ManejadorClase* instancia;
        ManejadorClase();
        //list <Clase*> clases; // cual hay que usar aca, list o map?
        map<int, Clase*> clases;
    public:
        void add(Clase*);
        Clase* find(int);// cambie el argumento que era un string por un int
        static ManejadorClase* getInstancia();
        bool existeClase(int);// cambie el argumento que era un string por un int
        //IControlador* getIControlador();

        ~ManejadorClase();
};

#endif