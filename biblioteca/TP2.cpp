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
    imprimirPub();
}

void livro::incrementar(int i){
    qtdeExemplares = qtdeExemplares + i;
}

void livro::decrementar(int d){
    if( qtdeExemplares - d < 0) throw ErroG("\n<ERRO> Decrementacao maior que qtd de exemplares");
    qtdeExemplares = qtdeExemplares - d;
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
ItemEmprestimo::ItemEmprestimo(Livro liv){
    livro = liv;
    dataDevolucao = null;
}
Biblioteca::Biblioteca(){
    usuarios = {};
    livros = {};
    emprestimos = {};

}
void Biblioteca::adduser(Usuario use){ usuarios.push_back(use);}

void Biblioteca::addpub(Publicacao pub){ livros.push_back(pub);}

void Biblioteca::addemp(Emprestimo emp)(Emprestimo emp){ emprestimos.push_back(emp);}

void Biblioteca::additememp(Emprestimo emp, ItemEmprestimo item){emp.itens.push_back(item);}

void Biblioteca::getUsuarios(){

    for(int i=0; i <= usuarios.size();i++){
        cout << usuarios[i] << endl;
    }
}

void Biblioteca::getPublicacoes(){

    for(int i=0; i <= livros.size();i++){
        cout << livros[i] << endl;
    }
}

void Biblioteca::getEmprestimos(){

    for(int i=0; i <= emprestimos.size();i++){
        cout << emprestimos[i] << endl;
    }
}


