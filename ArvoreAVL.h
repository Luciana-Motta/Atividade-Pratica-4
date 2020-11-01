#ifndef ARVOREAVL_H
#define ARVOREAVL_H
#include "NoAVL.h"


class ArvoreAVL
{
    private:
        NoAVL *raiz; // ponteiro para o nó raiz da árvore
        bool balanceada;
        int comparacoes;

        void auxImprime(NoAVL *p);
        NoAVL *auxBusca(NoAVL *p, int ch);
        NoAVL *libera(NoAVL *p);
        void escolheRotacao(NoAVL *p);
        void atualizaFatorBalanceamento(NoAVL *p);
        void atualizaAltura(NoAVL *p);
        void rotacaoSimplesEsquerda(NoAVL *P);
        void rotacaoSimplesDireita(NoAVL *p);
        void rotacaoDuplaEsquerda(NoAVL *p);
        void rotacaoDuplaDireita(NoAVL *P);
        NoAVL* verificaBalanceamento(NoAVL *p);
        void balancear(NoAVL *p);

    public:
        ArvoreAVL(bool balanceada);
        ~ArvoreAVL();

        int getComparacoes();
        void imprime();
        int getRaiz();
        bool vazia();
        NoAVL *busca(int val);
        void insere(int val);
        void setAturaEsq(int altura);
        void setAlutraDir(int altura);
        void remover(int val);
        int alturaDaArvore();

};

#endif // ARVOREAVL_H
