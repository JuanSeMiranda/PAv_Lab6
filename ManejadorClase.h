#ifndef MANEJADORCLASE
#define MANEJADORCLASE
#include "Clase.h"
#include <list>

class Clase;

class ManejadorClase{
    private:
        static ManejadorClase* instancia;
        ManejadorClase();
        map<int, Clase*> clases;
    public:
        void add(Clase*);
        Clase* find(int);
        static ManejadorClase* getInstancia();
        map<int, Clase*> listarClases();
        bool existeClase(int);
        bool estaVacio();
        void remove(int);

        ~ManejadorClase();
};

#endif