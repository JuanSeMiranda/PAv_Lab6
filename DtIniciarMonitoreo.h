#ifndef DTINICIARMONITOREO
#define DTINICIARMONITOREO
#include "DtIniciarClaseFull.h"

using namespace std;


class DtIniciarMonitoreo : public DtIniciarClaseFull{
    private:
        string* habilitados;
    public:
        DtIniciarMonitoreo();
        DtIniciarMonitoreo(string, string, DtTimeStamp, int, string*);
        string* getHabilitados();
        ~DtIniciarMonitoreo();
};

#endif