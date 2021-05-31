#ifndef TEORICO_H
#define TEORICO_H

class Teorico{
    private:
        int cantAsistentes; //atributo calculado
    public:
        Teorico();
        Teorico(int);
        void setCantAsistentes(int);
        int getCantAsistentes();

        ~Teorico();
};

#endif