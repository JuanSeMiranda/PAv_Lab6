#ifndef DTINFOCLASE
#define DTINFOCLASE
#include "Docente.h"
#include <string>

using namespace std;

class Docente;

class DtInfoClase{
    private:
        int id;
        string nombre;
        Docente* docente;
    public:
        DtInfoClase();
        DtInfoClase(int, string, Docente*);
        int getId();
        string getNombre();

        //void agregarDocente(Docente*);//talves no va; efectivamente no va
        ~DtInfoClase();

};

#endif