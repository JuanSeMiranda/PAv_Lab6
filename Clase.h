#ifndef CLASE
#define CLASE
#include <string>
#include <map>
#include "DtTimeStamp.h"
#include "Docente.h"
#include "Participacion.h"
#include "AsisteEnVivo.h"
#include "AsisteDiferido.h"
#include "DtInfoTeorico.h"
#include "DtInfoClase.h"
#include "DtInfoMonitoreo.h"

using namespace std;

class Docente;
class AsisteEnVivo;
class AsisteDiferido;

class Clase{
    private:
        int id;
        string nombre;
        DtTimeStamp* inicio;
        DtTimeStamp* fin;
        string rutaVideo;
        static int idAutogenerado;
        Docente* docente;
        map<int, Participacion*> participaciones;
        list<AsisteEnVivo*> asistentesEnVivo;
        list<AsisteDiferido*> asistentesDiferido;
    public:
        Clase();
        Clase(int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*);
        void setId(int);
        int getId();

        void setNombre(string);
        string getNombre();

        void setInicio(DtTimeStamp*);
        DtTimeStamp* getInicio();

        void setFin(DtTimeStamp*);
        DtTimeStamp* getFin();

        void setRutaVideo(string);
        string getRutaVideo();

        static int getIdAutogenerado();
        void insertarAsistenciaEnVivo(AsisteEnVivo*);

        Docente* getDocente();
        bool participaEstudiante(Estudiante*);

        DtInfoClase* getDtInfoClase();

        virtual ~Clase();
};

#endif