#ifndef LIVRO_H
#define LIVRO_H
#include <iostream>
#include <string>
#include "excecoes.h"
#include "us_pub.h"

using namespace std;

class livro : Publicacao
{
    private:
        string autores;
        int qtdeExemplares;
    public:
        livro(string a, int q);
        void imprimirlivro(); //TESTE APAGAR DEPOOIS
        void incrementar(int i);
        void decrementar(int d);


};

#endif
