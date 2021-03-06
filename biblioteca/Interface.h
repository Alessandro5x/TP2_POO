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
    char c;
    Biblioteca B;
    public:
        Interface(Biblioteca b) : B(b){}
        void menu(){
            cout<< "Aperte" << "\nA. Para cadastrar um novo usuario\nB. Para cadastrar um novo livro\nC. Para cadastrar um novo periodico\nD. Para cadastrar um novo emprestimo\nE. Para inserir um novo item de emprestimo\nF. Para excluir um usuario\nG. Para excluir um emprestimo\nH. Para excluir um item de emprestimo\nI. Para pesquisar publicacoes por titulo\nJ. Pesquisar livros por autor\nK. Listar todos os usuarios\nL. Listar todas as publicacoes\nM. Listar todos emprestimos e seus itens\nN. Sair do programa.\n";
            }
        void casos();
        void Nusuario();
        void Imprimirusuarios(){B.printtodosusuarios();}

};


#endif // INTERFACE_H_INCLUDED
