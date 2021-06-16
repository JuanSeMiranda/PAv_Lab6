#ifndef TEORICO_H
#define TEORICO_H
#include "Clase.h"

class Teorico : public Clase{
    private:
        int cantAsistentes; //atributo calculado
    public:
        Teorico();
        Teorico(int, int, string, DtTimeStamp*, DtTimeStamp*, string, Docente*);
        void setCantAsistentes(int);
        int getCantAsistentes();

        ~Teorico();
};

#endif