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

        //set
        SetDataDevolucao(Date D){dataDevolucao = D;}

        //gets
        int getCodigo(){return livro->getcod();}

        //imprimir
        void printItemEmprestimo(){cout<<"Data de devolucao: "<<dataDevolucao<<", "; livro->imprimirlivro();}
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
       Emprestimo(Date DP, Usuario u);
       ~Emprestimo();

       void adicionaE(Livro *l);
       void excluiE(Livro *l);

       void devolver(Livro *l);
       void devolverT();

       void PrintEmprestimo();
       void PrintItem(int i){itens[i].printItemEmprestimo();}

       int ProcuraItem(Livro *l);

       //gets
       int getNumero(){return numero;}
       vector <ItemEmprestimo> getVecItens(){return itens;}

};



#endif // EMPRESTIMO_H_INCLUDED
