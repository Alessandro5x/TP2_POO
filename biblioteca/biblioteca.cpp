#include<iostream>
#include "biblioteca.h"
#include <vector>
#include "us_pub.h"
#include "livro.h"
#include "Emprestimo.h"

Biblioteca::Biblioteca(){
    usuarios = {};
    livros = {};
    emprestimos = {};

}
void Biblioteca::adduser(Usuario &use){ usuarios.push_back(use);}

void Biblioteca::addpub(Publicacao &pub){ livros.push_back(pub);}

void Biblioteca::addemp(Emprestimo &emp){ emprestimos.push_back(emp);}

// void Biblioteca::additememp(Emprestimo emp, ItemEmprestimo item){itens.push_back(item);}

int Biblioteca::searchuser(Usuario &user){

    for(int i = 0; i <= usuarios.size();i++){
        if (user.getCPF() == usuarios[i].getCPF()){
            return i;
    }else return -1;
}}

void Biblioteca::deleteuser(Usuario &use){
    if (searchuser(use) >=0){
    usuarios.erase(usuarios.begin() + searchuser(use));}
    else throw "Usuario com emprestimo";
}/*
int Biblioteca::searchpub(Publicacao& pub){
     for(int i = 0; i <= emprestimos.size();i++){
        if(pub == itens[i].getL()){
            return i;
    }else return -1;
}}


void Biblioteca::deletepub(Publicacao& pub){
    if()

}*/

vector<Usuario> Biblioteca::getUsuarios(){

        return usuarios;
}

vector<Publicacao> Biblioteca::getPublicacoes(){

    return livros;
}

vector<Emprestimo> Biblioteca::getEmprestimos(){

    return emprestimos;
}
