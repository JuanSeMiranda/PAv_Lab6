#ifndef DTPARTICIPACION
#define DTPARTICIPACION
#include <string>
#include "DtTimeStamp.h"

using namespace std;

class DtParticipacion{
    private:
        int id;
        DtTimeStamp fecha;
        string mensaje;
        DtParticipacion * responde;
    public:
        DtParticipacion();
        DtParticipacion(int, DtTimeStamp, string);
        int getId();
        DtTimeStamp getFecha();
        ~DtParticipacion();
};
#endif