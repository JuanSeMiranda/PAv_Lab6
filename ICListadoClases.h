#ifndef ICLISTADOCLASES
#define ICLISTADOCLASES

class ICListadoClases{
    public:
        virtual list<string> asignaturasAsignadas()=0;
        virtual DtInfoClase* selectAsignatura(string)=0;
};



#endif
