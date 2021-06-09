#ifndef CALTAASIGNATURA
#define CALTAASIGNATURA
#include "ICAltaAsignatura.h"
#include "DtAsignatura.h"

class CAltaAsignatura : public ICAltaAsignatura{
    private:
    DtAsignatura* datosAsignatura;
    public:
        void ingresar();
        void altaAsignatura();
        void cancelar();
};

#endif