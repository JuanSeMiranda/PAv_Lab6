#ifndef ASIGNATURA
#define ASIGNATURA
#include <string>
#include <map>
using namespace std;

class Asignatura{
    private:
        string codigo;
        string nombre;
        map <int, Asignatura> clases; //ni puta idea que hicieron
    public:
        Asignatura();
        Asignatura(string, string, map<int,Asignatura>);
        void setCodigo(string);
        void setNombre(string);
        void setClases(map<int,Asignatura>);//no en cpp
        string getCodigo();
        string getNombre();
        map<int,Asignatura> getClases();

        ~Asignatura();
};

#endif