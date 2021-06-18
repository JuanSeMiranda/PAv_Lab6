#ifndef DTINFOTEORICO
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
        DtInfoMonitoreo(int, string);
        void agregarEstudiante(string);
        ~DtInfoMonitoreo();

};

#endif