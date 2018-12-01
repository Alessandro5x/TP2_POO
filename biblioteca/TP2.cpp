#include<iostream>
#include "TP2.h"
#include <vector>

using namespace std;

Usuario::Usuario(string n, string cp, string ende, string fon){
    nome = n;
    cpf = cp;
    endereco = ende;
    fone = fon;
}
livro::livro(string a, int q)
{
    autores = a;
    qtdeExemplares = q;
}


void livro::imprimirlivro(){
    cout<< "autores: " << autores << "| Quantidade:" << qtdeExemplares << endl;
}

void livro::incrementar(int i){
    qtdeExemplares = qtdeExemplares + i;
}

void livro::decrementar(int d){
    if( qtdeExemplares - d < 0) throw ErroG("\n<ERRO> Decrementacao maior que qtd de exemplares");
    qtdeExemplares = qtdeExemplares - d;
}
ItemEmprestimo::ItemEmprestimo(livro liv){
    livro = liv;
    dataDevolucao = null;
}
Biblioteca::Biblioteca(){
    usuarios = {};
    livros = {};
    emprestimos = {};

}
Biblioteca::Biblioteca(Usuario use){ usuarios.push_back(use);}

Biblioteca::Biblioteca(Publicacao pub){ livros.push_back(pub);}

Biblioteca::Biblioteca(ItemEmprestimo item){ emprestimos.push_back(item);}



