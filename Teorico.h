#ifndef TEORICO_H
#define TEORICO_H
#include "Clase.h"

class Teorico : public Clase{
    private:
        int cantAsistentes; //atributo calculado
    public:
        Teorico();
        Teorico(int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*, int);
        void setCantAsistentes(int);
        int getCantAsistentes();
        DtInfoTeorico* getDtInfoTeorico();
        void agregarAsistente();

        ~Teorico();
};

#endif