#ifndef CASISTENCIAACLASEENVIVO
#define CASISTENCIAACLASEENVIVO
#include "DtAsistir.h"
#include "ICAsistenciaAClaseEnVivo.h"
#include "Teorico.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

class CAsistenciaAClaseEnVivo: public ICAsistenciaAClaseEnVivo{
    private:
        string cod;
        int id;
    public:
        CAsistenciaAClaseEnVivo();
        list<string> asignaturasInscripto(string);
        list<int> clasesOnlineDisponibles(string);
        DtAsistir* selectClase(int);
        void asistirClaseEnVivo();
        void cancelar();

        bool existeUsuario(string);
        bool esEstudiante(string);
        bool existeAsignatura(string);
        bool existeClase(int);

        bool perfilesVacio();
        bool asignaturasVacio();
        bool clasesVacio();
        bool asignaturaTieneClases(string);

        ~CAsistenciaAClaseEnVivo();
};

#endif