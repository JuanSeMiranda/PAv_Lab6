#ifndef DTASIGNATURA
#define DTASIGNATURA
#include "DtInstanciaClase.h"
#include <string>

using namespace std;

class DtAsignatura{
    public:
        string nombre;
        string codigo;
        DtInstanciaClase tipoClases;
    private:
        DtAsignatura();
        DtAsignatura(string, string, DtInstanciaClase);
        string getNombre();
        string getCodigo();
        DtInstanciaClase getTipoClases();
        ~DtAsignatura();
};
#endif