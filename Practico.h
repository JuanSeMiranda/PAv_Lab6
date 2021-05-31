#ifndef PRACTICO
#define PRACTICO
#include "clase.h"

class Practico : public Clase{
    public:
        Practico();
        Practico(int, string, DtTimeStamp, DtTimeStamp, string);
        ~Practico();
};

#endif