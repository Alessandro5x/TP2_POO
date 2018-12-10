#include<iostream>
#include <fstream>
#include "biblioteca.h"
#include <vector>
#include "us_pub.h"
#include "livro.h"
#include "periodicos.h"
#include "Emprestimo.h"
#include "excecoes.h"

using namespace std;

Biblioteca::Biblioteca(){
    usuarios = {};
    Pub = {};
    emprestimos = {};

}
void Biblioteca::adduser(Usuario &use){
    if((ProcuraCPF(use.getCPF())) == -1){
            usuarios.push_back(use);}
    else{ throw ErroG("-----CPF ja cadastrado-----"); }

}

void Biblioteca::addpub(Publicacao *pub){
    int i = pub->getcod();
    if(ProcuraLivro(i) == -1){
        Pub.push_back(pub);
        }
    else {throw ErroG("-----Codigo ja cadastrado-----");}
}

void Biblioteca::addemp(Emprestimo &emp){emprestimos.push_back(emp);}

//void Biblioteca::additememp(Emprestimo emp, ItemEmprestimo item){emp.adicionaE(item.livro);}

void Biblioteca::setEmpr(int i, Livro*l){
            if (l){
                    if(l->getqtdeExemplares()){
                        emprestimos[i].adicionaE(l);
                        }
                    else throw ErroG("-----Livro sem saldo-----");

            }else{ throw ErroG("------Periodicos nao podem ser emprestados-----");}
}

//procuras
int Biblioteca::searchuser(Usuario &user){

    for(int i = 0; i <= usuarios.size();i++){
        if (user.getCPF() == usuarios[i].getCPF()){
            return i;
    }
 }
 return -1;
}

int Biblioteca::ProcuraCPF(string cpf){

    //if (usuarios.size() == 0)
      //  return 0;
    for(int i = 0; i < usuarios.size();i++){
            if (cpf == usuarios[i].getCPF()){
            return i;
    }
 }
 return -1;
}

int Biblioteca::ProcuraLivro(int cod){
    for(int i = 0; i < Pub.size();i++){
        if (cod == Pub[i]->getcod()){
            return i;
    }
 }
 return -1;
}

int Biblioteca::searchemp(Emprestimo &emp){
    for(int i = 0; i <= emprestimos.size();i++){
        if(emp.getNumero() == emprestimos[i].getNumero()){
            return i;
    }
 }return -1;
}

int Biblioteca::ProcuraEmp(int cod){
    for(int i = 0; i <= emprestimos.size();i++){
        if(cod == emprestimos[i].getNumero()){
            return i;
    }
 }
 return -1;
}
/*
int Biblioteca::searchpub(Publicacao *pub){
     for(int i = 0; i <= Pub.size();i++){
        if(pub->codPublicacao == Pub[i]->codPublicacao){
            return i;
    }else return -1;
}}
*/

vector<int> Biblioteca::searchtitle(string a){
    vector <int> result;
    for (int i = 0;i<Pub.size();i++){
        Livro *l = dynamic_cast<Livro*>(getPublicacoes()[i]);
            if(l && (l->gettitulo().compare(0, a.length(), a) == 0)){
                result.push_back(Pub[i]->getcod());
                        }
                }
        return result;
}

vector<int> Biblioteca::searchautor(string a){
   vector <int> result;

    for (int i = 0;i<Pub.size();i++){
        Livro *l = dynamic_cast<Livro*>(getPublicacoes()[i]);
            if(l && (l->getAutor().compare(0, a.length(), a) == 0)){
                result.push_back(Pub[i]->getcod());
                        }
                }
        return result;
}

bool Biblioteca::itememprestimo(Publicacao *p){

    for(int i = 0; i <emprestimos.size();i++){
            for(int j = 0; j< emprestimos[i].getVecItens().size();j++){
        if (p->getcod()== emprestimos[i].getVecItens()[j].getCodigo())
            return true;
        }}

    return false;
}

//deletes
void Biblioteca::deleteuser(Usuario &use){
    if (searchuser(use) >=0){
    usuarios.erase(usuarios.begin() + searchuser(use));}
    else throw ErroG("-----Usuario com emprestimo-----");
}

void Biblioteca::deleteemp(Emprestimo& emp){
    if (searchemp(emp) >=0){
    emprestimos.erase(emprestimos.begin() + searchemp(emp));
    }
    else throw ErroG("-----Nao existe esse emprestimo-----");
}

void Biblioteca::deleteitememp(Emprestimo emp, ItemEmprestimo item){
        emp.excluiE(item.livro);

}

void Biblioteca::deletepub(Publicacao *pub){
    if(itememprestimo(pub) ==  true){
        throw ErroG("-----Tem emprestimo-----");
    }
    int i = ProcuraLivro(pub->getcod());
    Pub.erase(Pub.begin() + i);
}


/*
void Biblioteca::giveback(Emprestimo emp, Livro liv){
        emp.devolver(liv);
}
*/

//devolve
void Biblioteca::givebackall(Emprestimo &emp){
    emp.devolverT();
}

//GETS

vector<Usuario> Biblioteca::getUsuarios(){

        return usuarios;
}

vector<Publicacao*> Biblioteca::getPublicacoes(){

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
        out << "Publicacoes: " << Pub[i]->gettitulo() << ",";
    }
    for(int i = 0;i < emprestimos.size();i++){
        out << "Emprestimos: " << emprestimos[i].getNumero() << ",";
    }
}
void Biblioteca::readfile(){
    ifstream in("File.txt");
    string a, line;
    while(getline(in,line)){
        a+=line + "\n";
    }
}

//impressoes
void Biblioteca::printtodosusuarios(){
    for(int i = 0; i < usuarios.size(); i++){
            usuarios[i].Printusuario();
            cout<<"\n";
    }
}
void Biblioteca::PrintTodasPublicacoes(){
    for(int i = 0; i < Pub.size(); i++){
            Pub[i]->imprimirPub();
            cout<<"\n";
    }
}

void Biblioteca::PrintLivrosEPeriodicos(){

    for(int i = 0; i < Pub.size(); i++){
            Livro *l = dynamic_cast<Livro*>(Pub[i]);
            if(l){
                l->imprimirlivro();
            }
            else{
                periodicos *p = dynamic_cast<periodicos*>(Pub[i]);
                p->imprimirperiodico();
            }
            cout<<"\n";
    }
}

void Biblioteca::PrintTodosEmprestimos(){
    for(int i = 0; i < emprestimos.size(); i++){
            emprestimos[i].PrintEmprestimo();
            cout<<"\n";
    }
}


