#ifndef MANEJADORASIGNATURA
#define MANEJADORASIGNATURA
#include "Asignatura.h"
#include <map>
#include <list>

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
        map<string, Asignatura*> getAsignaturas();
        list<string> listarAsignatura();
        bool estaVacio();
        void destroy(string);

        ~ManejadorAsignatura();
};

#endif