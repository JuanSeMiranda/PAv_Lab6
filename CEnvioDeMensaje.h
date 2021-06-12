#ifndef CENVIODEMENSAJE
#define CENVIODEMENSAJE
#include "ICEnvioDeMensaje.h"

class CEnvioDeMensaje : public ICEnvioDeMensaje{
    private:
        int id;
        int idp;
        string txt;
    public:
        CEnvioDeMensaje();
        list<string> clasesOnLineAsistiendo();
        map<int, DtParticipacion*> selectClase(int);
        void responder(int);
        void ingresarTexto(string);
        void enviarMensaje();
        void cancelar();
        ~CEnvioDeMensaje();

};

#endif