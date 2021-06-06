#ifndef CINICIOCLASE
#define CINICIOCLASE
#include <string>
#include "DtIniciarClaseFull.h"
#include "ICInicioClase.h"

using namespace std;

class CInicioClase : public ICInicioClase{
    private:
        DtIniciarClase* inicioClase;
        string email;
    public:
        CInicioClase();
        string* asignaturasAsignadas();
        bool selectAsignatura(DtIniciarClase*);
        string* inscriptosAsignaturas();
        void habilitar(string);
        DtIniciarClaseFull datosIngresados();
        void iniciarClase();
        ~CInicioClase();
};


#endif