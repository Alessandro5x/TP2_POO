#include<iostream>
#include <fstream>
#include "biblioteca.h"
#include <vector>
#include "us_pub.h"
#include "livro.h"
#include "Emprestimo.h"

using namespace std;

Biblioteca::Biblioteca(){
    usuarios = {};
    Pub = {};
    emprestimos = {};

}
void Biblioteca::adduser(Usuario &use){ usuarios.push_back(use);}

void Biblioteca::addpub(Publicacao &pub){ Pub.push_back(pub);}

void Biblioteca::addemp(Emprestimo &emp){ emprestimos.push_back(emp);}

void Biblioteca::additememp(Emprestimo emp, ItemEmprestimo item){emp.adicionaE(item.livro);}

//procuras
int Biblioteca::searchuser(Usuario &user){

    for(int i = 0; i <= usuarios.size();i++){
        if (user.getCPF() == usuarios[i].getCPF()){
            return i;
    }else return -1;
 }
}

int Biblioteca::ProcuraCPF(string cpf){
    for(int i = 0; i <= usuarios.size();i++){
        if (cpf == usuarios[i].getCPF()){
            return i;
    }else return -1;
 }
}

int Biblioteca::ProcuraLivro(int cod){
    for(int i = 0; i <= Pub.size();i++){
        if (cod == Pub[i].getcod()){
            return i;
    }else return -1;
 }
}

int Biblioteca::searchemp(Emprestimo &emp){
    for(int i = 0; i <= emprestimos.size();i++){
        if(emp.getNumero() == emprestimos[i].getNumero()){
            return i;
    }else return -1;
 }
}

int Biblioteca::ProcuraEmp(int cod){
    for(int i = 0; i <= emprestimos.size();i++){
        if(cod == emprestimos[i].getNumero()){
            return i;
    }else return -1;
 }
}

vector<string> Biblioteca::searchtitle(string t){
    vector <string> result;
    int aux=-1;
    for (int i = 0;i<Pub.size();i++){
        aux = Pub[i].gettitulo().compare(t);
        if(aux==t.size()-1){
            result.push_back(Pub[i].gettitulo());
        }
        return result;
    }
}

//deletes
void Biblioteca::deleteuser(Usuario &use){
    if (searchuser(use) >=0){
    usuarios.erase(usuarios.begin() + searchuser(use));}
    else throw "Usuario com emprestimo";
}

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


/*
int Biblioteca::ProcuraEmp(int n){
     for(int i = 0; i <= emprestimos.size();i++){
        if (cpf == emprestimos[i].getCPF()){
            return i;
    }else return -1;
 }
}
*/
/*
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

    return Pub;
}

vector<Emprestimo> Biblioteca::getEmprestimos(){

    return emprestimos;
}

//Arquivos

void Biblioteca::savefile(){
    ofstream out("File.txt");
    for(int i = 0;i < usuarios.size();i++){
        out << "Usuarios: " << usuarios[i].getName() << ";";
    }
    for(int i = 0;i < Pub.size();i++){
        out << "Publicacoes: " << Pub[i].gettitulo() << ",";
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


