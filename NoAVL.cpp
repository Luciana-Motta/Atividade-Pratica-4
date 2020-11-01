#include "NoAVL.h"
#include <iostream>

using namespace std;

NoAVL::NoAVL(int val)
{
    pai = NULL;
    esq = NULL;
    dir = NULL;
    info = val;
    altura = 0;
}

NoAVL::~NoAVL()
{
    //dtor
}

void NoAVL::setPai(NoAVL *p)
{
    pai = p;
}

void NoAVL::setEsq(NoAVL *p)
{
    esq = p;
}

void NoAVL::setInfo(int val)
{
    info = val;
}

void NoAVL::setFb(int val)
{
    fb = val;
}

void NoAVL::setDir(NoAVL *p)
{
    dir = p;
}

NoAVL* NoAVL::getPai()
{
    return pai;
}

NoAVL* NoAVL::getEsq()
{
    return esq;
}

int NoAVL::getInfo()
{
    return info;
}

NoAVL* NoAVL::getDir()
{
    return dir;
}

int NoAVL::getFb()
{
    return fb;
}

void NoAVL::setAltura(int val)
{
    altura = val;
}

int NoAVL::getAltura()
{
    return altura;
}

