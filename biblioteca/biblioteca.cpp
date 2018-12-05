#include<iostream>
#include <fstream>
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

void Biblioteca::additememp(Emprestimo emp, ItemEmprestimo item){emp.adicionaE(item.livro);}

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
}
/*
int Biblioteca::searchpub(Publicacao& pub){
     for(int i = 0; i <= livros.size();i++){
        if(pub.codPublicacao == livros[i].codPublicacao){
            return i;
    }else return -1;
}}

/*
void Biblioteca::deletepub(Publicacao& pub){
    if()

}*/
int Biblioteca::searchemp(Emprestimo &emp){
    for(int i = 0; i <= emprestimos.size();i++){
        if(emp.getNumero() == emprestimos[i].getNumero()){
            return i;
    }else return -1;
}}
void Biblioteca::deleteemp(Emprestimo& emp){
    if (searchemp(emp) >=0){
    emprestimos.erase(emprestimos.begin() + searchemp(emp));}
    else throw "Nao existe esse emprestimo";
}
void Biblioteca::deleteitememp(Emprestimo emp, ItemEmprestimo item){
        emp.excluiE(item.livro);

}
void Biblioteca::giveback(Emprestimo emp, Livro liv){
        emp.devolver(liv);
}
void Biblioteca::givebackall(Emprestimo &emp){
    emp.devolverT();
}
vector<string> Biblioteca::searchtitle(string t){
    vector <string> result;
    int aux=-1;
    for (int i = 0;i<livros.size();i++){
        aux = livros[i].gettitulo().compare(t);
        if(aux==t.size()-1){
            result.push_back(livros[i].gettitulo());
        }
        return result;
    }
}
vector<string> Biblioteca::searchautor(string a){
    vector <string> result;
    int aux=-1;
    for (int i = 0;i<livros.size();i++){
        aux = livros[i].getAutor().compare(a);
        if(aux==a.size()-1){
            result.push_back(livros[i].getAutor());
        }
        return result;
    }
}

vector<Usuario> Biblioteca::getUsuarios(){

        return usuarios;
}

vector<Publicacao> Biblioteca::getPublicacoes(){

    return livros;
}

vector<Emprestimo> Biblioteca::getEmprestimos(){

    return emprestimos;
}
void Biblioteca::savefile(){
    ofstream out("File.txt");
    for(int i = 0;i < usuarios.size();i++){
        out << "Usuarios: " << usuarios[i].getName() << ";";
    }
    for(int i = 0;i < livros.size();i++){
        out << "livros: " << livros[i].gettitulo() << ",";
    }
    for(int i = 0;i < emprestimos.size();i++){
        out << "Emprestimos: " << emprestimos[i].getNumero() << ",";
    }
}
void Biblioteca::readfile(){
    ifstream in("File.txt");
    string s, line;
    while(getline(in,line)){
        s+=line + "\n";
    }
}


