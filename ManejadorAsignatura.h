#ifndef MANEJADORASIGNATURA
#define MANEJADORASIGNATURA
#include "Asignatura.h"
#include <map>

class ManejadorAsignatura{
    private:
        static ManejadorAsignatura* instancia;
        ManejadorAsignatura();
        map<string, Asignatura*> asignaturas;
    public:
        void add(Asignatura*);
        Asignatura* find(string);
        static ManejadorAsignatura* getInstancia();
        bool existeAsignatura(string);
        //IControlador* getIControlador();

        ~ManejadorAsignatura();
};

#endif