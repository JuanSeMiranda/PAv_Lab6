#ifndef DTTIMESTAMP
#define DTTIMESTAMP
#include "DtFecha.h"

class DtTimeStamp{
    private:
        DtFecha* fecha;
        int hora;
        int minuto;
        int segundo;
    public:
        DtTimeStamp();
        DtTimeStamp(DtFecha*, int, int, int);
        DtFecha* getFecha();
        int getHora();
        int getMinuto();
        int getSegundo();

        ~DtTimeStamp();
}; 

#endif