#ifndef PERIODICOS_H_INCLUDED
#define PERIODICOS_H_INCLUDED
#include <iostream>
#include <string>
#include "us_pub.h"
using namespace std;

class periodicos : Publicacao
{
      private:
        string mes;
        int numEdicao;
    public:
        periodicos(string m, int n) : mes(m), numEdicao(n){};
        void imprimirperiodico() {cout<< "Mes: " << mes << " | Numero edicao:" << numEdicao << endl;}
};


#endif // PERIODICOS_H_INCLUDED
