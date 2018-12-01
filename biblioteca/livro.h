#ifndef LIVRO_H
#define LIVRO_H
#include <iostream>
#include <string>
#include "excecoes.h"
#include "us_pub.h"

using namespace std;

class Livro : public Publicacao
{
    private:
        string autores;
        int qtdeExemplares;
    public:
        Livro(int cod, string tit, string ed, int an, string a, int q) : Publicacao(cod, tit, ed, an), autores(a), qtdeExemplares(q){}
        Livro(int cod, string tit, string ed, int an, string a) : Publicacao(cod, tit, ed, an), autores(a){ qtdeExemplares = 0; }
        void imprimirlivro(); //TESTE APAGAR DEPOOIS
        void incrementar(int i);
        void decrementar(int d);

};

#endif
