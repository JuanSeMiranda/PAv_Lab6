#ifndef ASIGNATURA
#define ASIGNATURA
#include <string>
#include <map>
#include "Clase.h"
#include "DtInstanciaClase.h"
#include "ManejadorClase.h"
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
        void agregarClase(Clase*);
        DtInstanciaClase* getTipoClases();


        ~Asignatura();
};


#endif