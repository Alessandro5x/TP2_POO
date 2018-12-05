#include<iostream>
#include "biblioteca.h"
#include <vector>

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
