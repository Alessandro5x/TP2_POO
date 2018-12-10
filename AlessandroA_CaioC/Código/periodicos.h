#ifndef PERIODICOS_H_INCLUDED
#define PERIODICOS_H_INCLUDED
#include <iostream>
#include <string>
#include "us_pub.h"
using namespace std;

class periodicos : public Publicacao
{
      private:
        string mes;
        int numEdicao;
    public:
        periodicos(int cod, string tit, string ed, int an, string m, int n) : Publicacao(cod, tit, ed, an), mes(m), numEdicao(n){};
        void imprimirperiodico() {cout<< "Mes: " << mes << " Numero edicao:" << numEdicao <<", "; imprimirPub();}
        string getMes(){return mes;}
        int getnumEdicao(){return numEdicao;}
};


#endif // PERIODICOS_H_INCLUDED
