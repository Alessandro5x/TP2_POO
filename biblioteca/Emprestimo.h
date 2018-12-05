#ifndef EMPRESTIMO_H_INCLUDED
#define EMPRESTIMO_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "us_pub.h"
#include "livro.h"

using namespace std;

class ItemEmprestimo{
    private:
        Date dataDevolucao;
        Livro livro;
    public:
        ItemEmprestimo(Livro &L) : livro(L){}

};


class Emprestimo
{
    private:
        int numero;
        Date DataEmprestimo;
        Date DataPrevDevolucao;
        Usuario usuario;
        vector <ItemEmprestimo> itens;
        static int proximoNumero;
    public:
       Emprestimo(Date DP, const Usuario &u);
       void adicionaE(Livro &l);
       void excluiE(Livro &l);
       void devolver(Livro &l);
       void devolverT();
};



#endif // EMPRESTIMO_H_INCLUDED
