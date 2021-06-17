#ifndef DTINFOTEORICO
#define DTINFOTEORICO
#include "DtInfoClase.h"
#include <string>
#include <list>

using namespace std;

Class DtInfoTeorico: public DtInfoClase{

    private:
        int cantAsistentes;

    public:
        DtInfoTeorico();
        DtInfoTeorico(int, string, int);
        int getCantAsistentes();
        ~DtInfoTeorico();

};

#endif


