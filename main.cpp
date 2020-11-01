#include <iostream>
#include "ArvoreAVL.h"
#include "NoAVL.h"
#include <cstdlib>
#include <ctime>
#include "time.h"

using namespace std;

int numeroAleatorio(int menor, int maior) {
       return rand()%(maior-menor) + menor;
}

int main()
{
    ArvoreAVL *arvBal = new ArvoreAVL(true);
    ArvoreAVL *arvBB = new ArvoreAVL(false);


    int aleatorio;
    for(int i = 0 ; i < 1000 ; i++)
    {
        aleatorio = numeroAleatorio(1, 1000000);
        arvBal->insere(aleatorio);
        arvBB->insere(aleatorio);
    }

    cout << "Altura da arvore balanceada: " ;
    cout << arvBal->alturaDaArvore() << endl;

    cout << "Altura da arvore binaria de busca: " ;
    cout << arvBB->alturaDaArvore() << endl;


    clock_t ti , tf;
    ti = clock();
    for(int i = 0 ; i < 500 ; i++)
    {
        aleatorio = numeroAleatorio(1, 1000000);
        arvBal->busca(aleatorio);
    }
    tf = clock() - ti;
    cout << "Tempo de busca na arvore balanceada: ";
    cout << (((double)tf)/((double)CLOCKS_PER_SEC/10000)) << endl;


    ti = clock();
    for(int i = 0 ; i < 20000; i++)
    {
        aleatorio = numeroAleatorio(1, 100000);
        arvBB->busca(aleatorio);
    }
    tf = clock() - ti;
    cout << "Tempo de busca na arvore binaria de busca: ";
    cout << (((double)tf)/((double)CLOCKS_PER_SEC/10000)) << endl;


    cout << "Comparacoes da arvore balanceada: " ;
    cout << arvBal->getComparacoes() << endl;

    cout << "Comparacoes da arvore binaria de busca: " ;
    cout << arvBB->getComparacoes() << endl;



    return 0;
}
