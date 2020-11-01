#include "ArvoreAVL.h"
#include "NoAVL.h"
#include "stdlib.h"
#include <iostream>

using namespace std;

ArvoreAVL::ArvoreAVL(bool b)
{
    raiz = NULL;
    balanceada = b;
    comparacoes = 0;
}

ArvoreAVL::~ArvoreAVL()
{
    raiz = libera(raiz);
}

int ArvoreAVL::getComparacoes()
{
    return comparacoes;
}

NoAVL* ArvoreAVL::libera(NoAVL *p)
{
    if (p != NULL)
    {
        p->setEsq( libera(p->getEsq()));
        p->setDir( libera(p->getDir()));
        delete p;
        p = NULL;
    }
        return NULL;
}

void ArvoreAVL::imprime()
{
    auxImprime(raiz);
}

void ArvoreAVL:: auxImprime(NoAVL *p)
{
    if(p != NULL)
    {
        cout << p->getInfo() << endl;
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}

int ArvoreAVL::getRaiz()
{
    if(raiz != NULL) //ou if(!vazia())
        return raiz->getInfo();
    else
    {
        cout << "Árvora vazia!" << endl;
        exit(1);
    }
}

bool ArvoreAVL::vazia()
{
    return raiz == NULL;
}


NoAVL* ArvoreAVL::auxBusca(NoAVL *p, int ch)
{
    comparacoes++;
    if (p->getInfo() == ch)
        return p;

    if(p->getInfo() > ch)
    {
        if(p->getEsq() == NULL)
            return p;
        return auxBusca(p->getEsq() , ch);
    }
    else
    {
        if(p->getDir() == NULL)
            return p;
        return auxBusca(p->getDir() , ch);
    }
}

NoAVL* ArvoreAVL::busca(int val)
{
    if(vazia())
        return NULL;
    return auxBusca(raiz, val);
}

NoAVL* ArvoreAVL::verificaBalanceamento(NoAVL *p)
{
    while(p != NULL)
    {
        if(p->getFb() == -2 || p->getFb() == 2)
        {
            return p;
        }
        p = p->getPai();
    }
    return p;
}

void ArvoreAVL::atualizaAltura(NoAVL *p)
{
    int dir, esq;
    while(p != NULL)
    {
        if(p->getDir() == NULL)
            dir = -1;
        else
            dir = p->getDir()->getAltura();

        if(p->getEsq() == NULL)
            esq = -1;
        else
            esq = p->getEsq()->getAltura();

        if(esq > dir)
        {
            p->setAltura(esq + 1);
        }
        else
        {
            p->setAltura(dir + 1);
        }

        p->setFb(dir - esq);

        p = p->getPai();
    }
}

void ArvoreAVL::balancear(NoAVL *p)
{
    NoAVL *q;
    if (p->getFb() == 2)
    {
        q = p->getDir();
        if(q->getFb() == 1)
        {
            rotacaoSimplesEsquerda(p);
        }
        else
        {
            rotacaoDuplaEsquerda(p);
        }
    }
    else
    {
        q = p->getEsq();
        if(q->getFb() == -1)
        {
            rotacaoSimplesDireita(p);
        }
        else
        {
            rotacaoDuplaDireita(p);
        }
    }

}

void ArvoreAVL::insere(int val)
{
    NoAVL *novo = new NoAVL(val);
    NoAVL *p = busca(val);

    if(p == NULL)
    {
        raiz = novo;
    }
    else if(p->getInfo() == val)
    {
        cout << "Valor ja presente na arvore" << endl;
    }
    else if(p->getInfo() > val)
    {
        novo->setPai(p);
        p->setEsq(novo);
    }
    else if(p->getInfo() < val)
    {
        novo->setPai(p);
        p->setDir(novo);
    }

    atualizaAltura(novo);
    if(balanceada)
    {
        p = verificaBalanceamento(novo);
        while(p != NULL)
        {
            balancear(p);
            p = verificaBalanceamento(p);
        }
    }
}


void ArvoreAVL::rotacaoSimplesEsquerda(NoAVL *p)
{

    NoAVL *q = p->getDir();
    if(p->getPai() == NULL)
        raiz = q;

    q->setPai(p->getPai());
    p->setPai(q);
    if(q->getEsq() != NULL)
    {
        q = q->getEsq();
        q->setPai(p);
        p->setDir(q);
        q = p->getPai();
    }
    else
        p->setDir(NULL);

    q->setEsq(p);

    if(q->getPai() != NULL)
    {
        p = q->getPai();
        if(p->getInfo() > q->getInfo())
            p->setEsq(q);
        else
            p->setDir(q);
    }

    atualizaAltura(q->getEsq());
}

void ArvoreAVL::rotacaoSimplesDireita(NoAVL *p)
{

    NoAVL *q = p->getEsq();
    if(p->getPai() == NULL)
        raiz = q;

    q->setPai(p->getPai());
    p->setPai(q);
    if(q->getDir() != NULL)
    {
        q = q->getDir();
        q->setPai(p);
        p->setEsq(q);
        q = p->getPai();
    }
    else
        p->setEsq(NULL);

    q->setDir(p);

    if(q->getPai() != NULL)
    {
        p = q->getPai();
        if(p->getInfo() > q->getInfo())
            p->setEsq(q);
        else
            p->setDir(q);
    }

    atualizaAltura(q->getDir());

}

void ArvoreAVL::rotacaoDuplaEsquerda(NoAVL *p)
{
    cout << "Dupla Esquerda" << endl;

    rotacaoSimplesDireita(p->getDir());
    rotacaoSimplesEsquerda(p);
}

void ArvoreAVL::rotacaoDuplaDireita(NoAVL *p)
{
    rotacaoSimplesEsquerda(p->getEsq());
    rotacaoSimplesDireita(p);
}

void ArvoreAVL::remover(int val)
{
    NoAVL *p = busca(val);
    if(p == NULL)
    {
        cout << "Arvore Vazia" << endl;
        exit(1);
    }
    if(p->getInfo() != val)
    {
        cout << "Valor não encontrado" << endl;
        exit(1);
    }

    int altDir , altEsq;
    if(p->getDir() == NULL)
        altDir = -1;
    else
        altDir = p->getDir()->getAltura();

    if(p->getEsq() == NULL)
        altEsq = -1;
    else
        altEsq = p->getEsq()->getAltura();

    if(p->getAltura() == 0)
    {
        if(p->getPai() == NULL)
        {
            raiz = NULL;
            delete p;
            exit(1);
        }
        NoAVL *q = p->getPai();
        if(q->getInfo() > val)
            q->setEsq(NULL);
        else
            q->setDir(NULL);

        delete p;
        atualizaAltura(q);
        q = verificaBalanceamento(q);
    }
    else if(altDir > altEsq)
    {
        NoAVL *q = p->getDir();
        NoAVL *filhoEsq = p->getEsq();
        NoAVL *pai = p->getPai();

        while (q->getEsq() != NULL)
            q = q->getEsq();

        q->setEsq(filhoEsq);
        if(filhoEsq != NULL)
            filhoEsq->setPai(q);
        q = p->getDir();

        q->setPai(pai);
        if(pai == NULL)
            raiz = q;
        else if(pai->getInfo() > q->getInfo())
            pai->setEsq(q);
        else
            pai->setDir(q);

        delete p;
        atualizaAltura(filhoEsq);
        q = verificaBalanceamento(filhoEsq);
        while(q != NULL)
        {
           balancear(q);
           q = verificaBalanceamento(q);
        }
    }
    else
    {
        NoAVL *q = p->getEsq();
        NoAVL *filhoDir = p->getDir();
        NoAVL *pai = p->getPai();

        while (q->getDir() != NULL)
            q = q->getDir();

        q->setDir(filhoDir);
        if(filhoDir!= NULL)
            filhoDir->setPai(q);
        q = p->getEsq();

        q->setPai(pai);
        if(pai == NULL)
            raiz = q;
        else if(pai->getInfo() > q->getInfo())
            pai->setEsq(q);
        else
            pai->setDir(q);

        delete p;
        atualizaAltura(filhoDir);
        q = verificaBalanceamento(filhoDir);
        while(q != NULL)
        {
           balancear(q);
           q = verificaBalanceamento(q);
        }
    }
}

int ArvoreAVL::alturaDaArvore()
{
    return raiz->getAltura();
}






