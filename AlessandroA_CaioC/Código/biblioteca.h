#ifndef biblioteca_H
#define biblioteca_H
#include <iostream>
#include <vector>
#include "livro.h"
#include "us_pub.h"
#include "periodicos.h"
#include "Emprestimo.h"

using namespace std;

class Biblioteca{
    private:
        vector<Usuario> usuarios;
        vector<Publicacao*> Pub;
        vector<Emprestimo> emprestimos;
    public:

        Biblioteca();

        //funcoes gerais
        void adduser(Usuario &use);
        void addpub(Publicacao *pub);
        void addemp(Emprestimo &emp);

        //funcoes sendo utilizadas na interface
        void setEmpr(int i, Livro*l); //seta um livro no emprestimo escolhido
        void DevolverTudo(int i){emprestimos[i].devolverT();}      //Devolve todos livros no emprestimo escolhido
        void DevolverUm(int i, Livro *l){emprestimos[i].devolver(l);} //Devolve 1 livro no emprestimo escolhido

        //pesquisas
        int searchuser(Usuario &user);
        int searchemp(Emprestimo &emp);
        bool itememprestimo(Publicacao *p);

        //pesquisas sendo utilizadas na interface
        int ProcuraLivro(int cod); //retorta a posicao i da localizacao do livro no vetor publicacao
        int ProcuraEmp(int cod);   // retorta a posicao i do emprestimo na lista de emprestimos
        int ProcuraCPF(string cpf); //retorna a posicao i do usuario na lista de usuarios

        //deleta
        void deleteuser(Usuario &use);
        void deletepub(Publicacao *pub);
        void deleteemp(Emprestimo &emp);
        void deleteitememp(Emprestimo emp, ItemEmprestimo item);
        void DeletaItemEmprestimo(int i, Livro *l){emprestimos[i].excluiE(l);} //recebe posicao do emprestimo e o livro i para deletar o item.

        //gets
        vector <int> searchtitle(string a);
        vector <int> searchautor(string a);
        vector <Usuario> getUsuarios();
        vector <Publicacao*> getPublicacoes();
        vector <Emprestimo> getEmprestimos();
        void savefile();
        void readfile();

        //impressoes
        void printtodosusuarios();
        void PrintTodasPublicacoes();
        void PrintTodosEmprestimos();
        void PrintLivrosEPeriodicos();

        //validação
        bool validaProcura(int cod);
        bool validaProcuraCPF(string cpf);

};
#endif // biblioteca.h
