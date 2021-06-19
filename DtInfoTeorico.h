#ifndef DTINFOTEORICO
#define DTINFOTEORICO
#include "DtInfoClase.h"
#include <string>
#include <list>

using namespace std;

class DtInfoTeorico: public DtInfoClase{

    private:
        int cantAsistentes;
    public:
        DtInfoTeorico();
        DtInfoTeorico(int, string, Docente*, int);
        int getCantAsistentes();
        ~DtInfoTeorico();

};

#endif