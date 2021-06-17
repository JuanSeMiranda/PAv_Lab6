#ifndef CLISTADOCLASES
#define CLISTADOCLASES
#include "DtInfoClase"
#include <string>
#include <list>


using namespace std;

class CListadoClases: public ICListadoClases{
    public:
        CListadoClases();
        list<string> asignaturasAsignadas(string);
        map<int, DtInfoClase*> selectAsignatura(string);
        ~CListadoClases();
}

};






#endif
