#ifndef CALTAUSUARIO
#define CALTAUSUARIO
#include "TipoPerfil.h"
#include "DtPerfil.h"

class CAltaUsuario{
    private:
        DtPerfil* datosUsuario;
        TipoPerfil tipoPerfil;
        string doc;
        string inst;
    public:
        CAltaUsuario();
        void ingresarDatosPerfil(DtPerfil*);
        void ingresarEstudiante(string);
        void ingresarDocente(string);
        void altaUsuario();
        ~CAltaUsuario();
};

#endif