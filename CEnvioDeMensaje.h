#ifndef CENVIODEMENSAJE
#define CENVIODEMENSAJE
#include "ICEnvioDeMensaje.h"
#include "ManejadorPerfil.h"
#include "ManejadorClase.h"

class CEnvioDeMensaje : public ICEnvioDeMensaje{
    private:
        int id;
        int idp;
        string txt;
        Perfil* perfil;
    public:
        CEnvioDeMensaje();
        void verificarPerfil(string);   
        list<int> clasesOnLineAsistiendo();
        list<DtParticipacion*> selectClase(int);
        void responder(int);
        void ingresarTexto(string);
        void enviarMensaje();
        void cancelar();
        ~CEnvioDeMensaje();

};

#endif