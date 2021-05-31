#ifndef CLASE
#define CLASE
#include <string>
#include "DtTimeStamp.h"

using namespace std;

class Clase{
    private:
        int id;
        string nombre;
        DtTimeStamp inicio;
        DtTimeStamp fin;
        string rutaVideo;
    public:
        Clase();
        Clase(int, string, DtTimeStamp, DtTimeStamp, string);
        void setId(int);
        int getId();

        void setNombre(string);
        string getNombre();

        void setInicio(DtTimeStamp);
        DtTimeStamp getInicio();

        void setFin(DtTimeStamp);
        DtTimeStamp getFin();

        void setRutaVideo(string);
        string getRutaVideo();

        virtual ~Clase();
};

#endif