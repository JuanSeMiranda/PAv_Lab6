#ifndef DTINFOTEORICO //que carajos pasa aca que se pone como opaco?
#define DTINFOTEORICO
#include "DtInfoClase.h"
#include <string>
#include <list>

using namespace std;

class DtInfoMonitoreo: public DtInfoClase{
    private:
        list<string> estudiantes;
    public:
        DtInfoMonitoreo();
        DtInfoMonitoreo(int, string, Docente*);
        void agregarEstudiante(string);
        ~DtInfoMonitoreo();

};

#endif