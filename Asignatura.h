#ifndef ASIGNATURA
#define ASIGNATURA
#include <string>
#include <map>
#include "Clase.h"
#include "DtInstanciaClase.h"
using namespace std;

class Clase;

class Asignatura{
    private:
        string codigo;
        string nombre;
        DtInstanciaClase* tipoClases;
        map<int, Clase*> clases;
    public:
        Asignatura();
        Asignatura(string, string, DtInstanciaClase*);
        void setCodigo(string);
        void setNombre(string);
        string getCodigo();
        string getNombre();
        DtInstanciaClase* getTipoClases();

        ~Asignatura();
};


#endif