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
        //construtores
        Livro(int cod, string tit, string ed, int an, string a, int q) : Publicacao(cod, tit, ed, an), autores(a), qtdeExemplares(q){}
        Livro(int cod, string tit, string ed, int an, string a) : Publicacao(cod, tit, ed, an), autores(a){ qtdeExemplares = 0; }

        //incrementacao e decrementacao
        void incrementar(int i);
        void decrementar(int d);

        //sobrecarga do ==
        bool operator== (const Livro &L);

        //funcao virtual
        virtual string getAutor()const{return autores;}

        //imprimir
        void imprimirlivro();
};

#endif
