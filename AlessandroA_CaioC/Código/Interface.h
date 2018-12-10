#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Emprestimo.h"
#include "livro.h"
#include "us_pub.h"
#include "periodicos.h"
#include "biblioteca.h"

using namespace std;

class Interface{
    Biblioteca B;
    public:
        Interface(Biblioteca b) : B(b){}
       void menu(){
            cout<< "\n---------------------------------------------\nMENU>Aperte" << "\nA. Para cadastrar um novo usuario\nB. Para cadastrar um novo livro\nC. Para cadastrar um novo periodico\nD. Para cadastrar um novo emprestimo\nE. Para inserir um novo item de emprestimo\nF. Para excluir um usuario\nG. Para excluir um livro\nH. Para excluir um periodico\nI. Para excluir um emprestimo\nJ. Para excluir um item de emprestimo\nK. Devolver todos os livros do emprestimo\nL. Devolver um livro do emprestimo\nM. Para pesquisar publicacoes por titulo\nN. Pesquisar livros por autor\nO. Listar todos os usuarios\nP. Listar todas as publicacoes\nQ. Listar todos emprestimos e seus itens\nR. Sair do programa.\n";
            }
        void casos();
        void Nusuario();
        void Nlivro();
        void NPeriodico();
        void NEmprestimo();
        void NItemEmprestimo();
        void ExcluiUsuario();
        void ExcluiLivro();
        void ExcluiPeriodico();
        void ExcluiEmprestimo();
        void ExcluiItemEmp();
        void DevolverTodosLivros();
        void DevolverUmLivro();
        void Menu_main();

        void PublicacoesPorTitulo();
        void LivrosPorAutor();

        //IMPRESSOES
        void ListarUsuarios(){cout<< "\nTodos usuarios:\n"; B.printtodosusuarios();}
        void ListarPublicacoes(){cout<< "\nPublicacoes:\n"; B.PrintLivrosEPeriodicos();} //B.PrintTodasPublicacoes();}
        void ListarEmprestimos(){cout<<"\nEmprestimos:\n"; B.PrintTodosEmprestimos();}

};


#endif // INTERFACE_H_INCLUDED
