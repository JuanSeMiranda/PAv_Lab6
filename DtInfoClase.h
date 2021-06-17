#ifndef DTINFOCLASE
#define DTINFOCLASE
#include <string>
#include <list>

using namespace std;

Class DtInfoClase{

    private:
        int id;
        string nombre;
        list<string> docentes;

    public:
        DtInfoClase();
        DtInfoClase(int, string);
        int getId();
        string getNombre();

        void agregarDocente(Docente*);
        ~DtInfoClase();

};



#endif
