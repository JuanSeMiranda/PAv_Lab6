#ifndef INSTANCIACLSE
#define INSTANCIACLSE

class DtInstanciaClase{
    private:
        bool teorico;
        bool practico;
        bool monitoreo;
    public:
        DtInstanciaClase();
        DtInstanciaClase(bool, bool, bool);
        bool getTeorico();
        bool getPractico();
        bool getMonitoreo();
        ~DtInstanciaClase();

};

#endif