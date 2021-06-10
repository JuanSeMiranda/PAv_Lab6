#ifndef CINICIOCLASE
#define CINICIOCLASE
#include <string>
#include "DtIniciarClaseFull.h"
#include "ICInicioClase.h"
#include "ManejadorClase.h"
#include "ManejadorPerfil.h"

using namespace std;

class CInicioClase : public ICInicioClase{
    private:
        DtIniciarClase* inicioClase;
        string email;
    public:
        CInicioClase();
        list<string> asignaturasAsignadas(string);
        bool selectAsignatura(DtIniciarClase*, string);
        string* inscriptosAsignaturas();
        void habilitar(string);
        DtIniciarClaseFull datosIngresados();
        void iniciarClase();
        ~CInicioClase();
};

#endif