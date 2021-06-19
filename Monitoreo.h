#ifndef MONITOREO_H
#define MONITOREO_H
#include "Clase.h"
#include "Estudiante.h"
#include "ManejadorPerfil.h"

class Monitoreo : public Clase{
    private:
        map<string, Estudiante*> estudiantes;
    public:
        Monitoreo();
        Monitoreo(int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*, list<string>);
        DtInfoMonitoreo* getDtInfoMonitoreo();

        ~Monitoreo();
};

#endif