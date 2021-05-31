#ifndef ASIGNATURA
#define ASIGNATURA
#include <string>
#include <map>
#include "Clase.h"
using namespace std;

class Clase;

class Asignatura{
    private:
        string codigo;
        string nombre;
        map<int, Clase*> clases;
    public:
        Asignatura();
        Asignatura(string, string);
        void setCodigo(string);
        void setNombre(string);
        string getCodigo();
        string getNombre();

        ~Asignatura();
};

#endif