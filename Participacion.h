#ifndef PARTICIPACION
#define PARTICIPACION
#include <string>
#include "DtTimeStamp.h"
#include "Perfil.h"

using namespace std;

class Participacion{
    private:
        int id;
        DtTimeStamp fecha;
        string mensaje;
        Participacion* enRespuestaA;
        Perfil* perfil;
    public:
        Participacion();
        Participacion(int, DtTimeStamp, string, Participacion*, Perfil*);
        void setId(int);
        int getId();
        void setFecha(DtTimeStamp);
        DtTimeStamp getFecha();
        void setMensaje(string);
        string getMensaje();
        void setEnRespuestaA(Participacion*);
        Participacion* getEnRespuestaA();
        void setPerfil(Perfil*);
        Perfil* getPerfil();
        ~Participacion();
};

#endif