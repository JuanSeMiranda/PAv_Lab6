#ifndef TEORICO_H
#define TEORICO_H
#include "Clase.h"




class Teorico : public Clase{
    protected:
        int cantAsistentes; //atributo calculado
    public:
        Teorico();
        Teorico(int, int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*);
        void setCantAsistentes(int);
        int getCantAsistentes();
        DtInfoTeorico* getDtInfoTeorico();
        void agregarAsistente();

        ~Teorico();
};

#endif