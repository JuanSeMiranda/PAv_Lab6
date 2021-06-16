#ifndef CASISTENCIAACLASEENVIVO
#define CASISTENCIAACLASEENVIVO
#include "DtAsistir.h"
#include "ICAsistenciaAClaseEnVivo.h"
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

        bool perfilesVacio()=0;
        bool asignaturasVacio()=0;
        bool clasesVacio()=0;
        bool asignaturaTieneClases(string)=0;

        ~CAsistenciaAClaseEnVivo();
};

#endif