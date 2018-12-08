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
    public:
        Livro *livro;
        ItemEmprestimo(Livro *L) : livro(L),dataDevolucao(0,0,0){};
        void printItemEmprestimo(){livro->imprimirlivro();}

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
       ~Emprestimo();

       void adicionaE(Livro *l);
       void excluiE(Livro *l);

       void devolver(Livro *l);
       void devolverT();

       void PrintEmprestimo();
       void PrintItem(int i){itens[i].printItemEmprestimo();}

       //gets
       getNumero(){return numero;}
};



#endif // EMPRESTIMO_H_INCLUDED
