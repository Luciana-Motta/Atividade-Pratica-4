#ifndef NOAVL_H
#define NOAVL_H


class NoAVL
{
    private:
        NoAVL *pai;
        NoAVL *esq; // ponteiro para o filho � esquerda
        int info; // informa��o do n� (int)
        NoAVL *dir; // ponteiro para o filho � direita
        int fb;
        int altura;

    public:
        NoAVL(int val); //construtor e destrutor
        ~NoAVL();
        void setPai(NoAVL *p);
        void setEsq(NoAVL *p); //opera��es setter
        void setInfo(int val);
        void setDir(NoAVL *p);
        void setFb(int val);
         NoAVL* getPai();
        NoAVL* getEsq(); //opera��es getter
        int getInfo();
        NoAVL* getDir();
        int getFb();
        void setAltura(int val);
        int getAltura();


};

#endif // NOAVL_H
