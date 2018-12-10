#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Interface.h"

using namespace std;


void Interface::Menu_main(){
    Interface I(B);
    int y = 0;
    while(y == 0){
        I.menu();
        I.casos();
    }
}

void Interface::Nusuario(){
    string nome, cpf, endereco, fone;

    cout<<"insira o nome:";
    getline(cin, nome);

    cout<<"insira o cpf:";
    getline(cin, cpf);

    cout<<"insira o endereco:";
    getline(cin, endereco);

    cout<<"insira o fone:";
    getline(cin, fone);

    try{
    Usuario U(nome,cpf,endereco,fone);
    B.adduser(U);
    }catch(ErroG &E){
        E.out();
        system("pause");
    }
}

void Interface::Nlivro(){
    int cod; string tit; string ed; int an; string a; int q;
    cout<<"Insira o codigo: ";
    cin>> cod;
    cin.ignore();

    cout<<"Insira o titulo: ";
    getline(cin, tit);

    cout<<"Insira a editora: ";
    getline(cin,ed);

    cout<<"Insira o ano: ";
    cin>> an;
    cin.ignore();

    cout<<"Insira os autores: ";
    getline(cin,a);

    cout<<"Insira a quantidade de exemplares: ";
    cin>> q;
    cin.ignore();

    try{
    B.addpub(new Livro(cod, tit, ed, an, a, q));
    }catch (ErroG &E){
        E.out();
        system("pause");
    }
}

void Interface::NPeriodico(){
    int cod; string tit; string ed; int an; string m; int n;
    cout<<"Insira o codigo: ";
    cin>> cod;
    cin.ignore();

    cout<<"Insira o titulo: ";
    getline(cin, tit);

    cout<<"Insira a editora: ";
    getline(cin, ed);

    cout<<"Insira o ano: ";
    cin>> an;
    cin.ignore();

    cout<<"Insira os mes: ";
    getline(cin, m);

    cout<<"Insira o numero de edicao: ";
    cin>> n;
    cin.ignore();

    B.addpub(new periodicos(cod, tit, ed, an, m, n));
}

void Interface::NEmprestimo(){
    string Ucpf; int d,m,a,i;
    cout<<"Insira o CPF do usuario: ";
    getline(cin, Ucpf);

    cout<<"Insira a data prevista para devolucao:\n";
    cout<<"Dia: ";
    cin>> d;

    cout<<"mes: ";
    cin>> m;

    cout<<"ano: ";
    cin>>a;
    cin.ignore();

    try{ //Erro para ver se o cara tem data de penalização OK Erro se setar data anterior da atual
        Date D(d,m,a);
        D.validadata();
    i = B.ProcuraCPF(Ucpf);
        Emprestimo E(D, B.getUsuarios()[i]);
    B.addemp(E);
    }catch(ErroG &E){
        E.out();
        system("pause");
    }
}

void Interface::NItemEmprestimo(){
    int nE,cl,i,j;
    cout<<"Insira o numero do emprestimo: ";
    cin>>nE;
    //cin.ignore();

    cout<<"Insira o codigo do livro: ";
    cin>> cl;
    cin.ignore();

    try{ //  Erro  para ver se é periodico

    // Ver o saldo do livro
    j = B.ProcuraLivro(cl);
    i = B.ProcuraEmp(nE);
    Livro *l = dynamic_cast<Livro*>(B.getPublicacoes()[j]);
    B.setEmpr(i,l);
        }catch(ErroG &E){
            E.out();
            system("pause");
    }
}

void Interface::ExcluiUsuario(){
    string cpf; int i;

    cout<<"Escolha o CPF do usuario a ser deletado: ";
    getline(cin, cpf);

    i = B.ProcuraCPF(cpf);
    try{

    B.deleteuser(B.getUsuarios()[i]);
    }catch(ErroG &E){
        E.out();
        system("pause");

    }

}

void Interface::ExcluiLivro(){
    int cod, i;

    cout<<"Escolha o codigo do livro a ser excluido: ";
    cin>>cod;
    cin.ignore();

    i = B.ProcuraLivro(cod);
    try{ //  Erro se o livro ja foi emprestado
    B.deletepub(B.getPublicacoes()[i]);
    }catch(ErroG &E){
        E.out();
        system("pause");
    }
}

void Interface::ExcluiPeriodico(){
    int cod, i;

    cout<<"Escolha o codigo do periodico a ser excluido: ";
    cin>>cod;
    cin.ignore();

    i = B.ProcuraLivro(cod);
    B.deletepub(B.getPublicacoes()[i]);
}

void Interface::ExcluiEmprestimo(){
    int nE, i;

    cout<<"Insira o numero do emprestimo: ";
    cin>>nE;
    cin.ignore();

    i = B.ProcuraEmp(nE);
    try{
    B.deleteemp(B.getEmprestimos()[i]);
    } catch (ErroG &E){
        E.out();
        system("pause");
    }
}

void Interface::ExcluiItemEmp(){
    int nE, cod, i;

    cout<<"Insira o numero do emprestimo: ";
    cin>>nE;
    cin.ignore();

    cout<<"Insira o codigo do livro a ser excluido: ";
    cin>> cod;
    cin.ignore();

    i = B.ProcuraLivro(cod);
    Livro *l = dynamic_cast<Livro*>(B.getPublicacoes()[i]);
    B.DeletaItemEmprestimo(B.ProcuraEmp(nE), l);
}

void Interface::DevolverTodosLivros(){
    int nE, i;

    cout<<"Insira o numero do emprestimo: ";
    cin>>nE;
    cin.ignore();

    i = B.ProcuraEmp(nE);
    B.DevolverTudo(i);
}

void Interface::DevolverUmLivro(){
    int nE, i,j, cod;

    cout<<"Insira o numero do emprestimo: ";
    cin>>nE;
    cin.ignore();

    cout<<"Insira o codigo do livro: ";
    cin>>cod;
    cin.ignore();

    i = B.ProcuraLivro(cod);
    Livro *l = dynamic_cast<Livro*>(B.getPublicacoes()[i]);
   /* if(l){
        cout<<"foi"<<endl;
    }
    else{
        cout<<"foi nao"<<endl;
    }*/
    j = B.ProcuraEmp(nE);
    B.DevolverUm(j,l);
}

void Interface::PublicacoesPorTitulo(){
    string s;
    vector <int> v;
    cout<<"Entre com o titulo: ";
    getline(cin, s);
    //cin>>s;
    v = B.searchtitle(s);
    for(int i = 0; i < v.size(); i++){
        for(int j = 0 ; j<B.getPublicacoes().size(); j++){
            Livro *l = dynamic_cast<Livro*>(B.getPublicacoes()[j]);
            if(v[i] == l->getcod()){l->imprimirlivro();}
        }
    }
}

void Interface::LivrosPorAutor(){
     string s;
    vector <int> v;
    cout<<"Entre com o autor: ";
    getline(cin, s);

    v = B.searchautor(s);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0 ; j<B.getPublicacoes().size(); j++){
            Livro *l = dynamic_cast<Livro*>(B.getPublicacoes()[j]);
            if(v[i] == l->getcod()){l->imprimirlivro();}
        }
    }
}


void Interface::casos(){
    char a;
    string b;
    getline(cin, b);
    a = b[0];
    switch(a){
    case 'A':
        Nusuario();
    break;

    case 'B':
        Nlivro();
    break;

    case 'C':
        NPeriodico();
    break;

    case 'D':
        NEmprestimo();
    break;

    case 'E':
        NItemEmprestimo();
    break;

    case 'F':
        ExcluiUsuario();
    break;

    case 'G':
       ExcluiLivro();
    break;

    case 'H':
        ExcluiPeriodico();
    break;

    case 'I':
        ExcluiEmprestimo();
    break;

    case 'J':
        ExcluiItemEmp();
    break;

    case 'K':
        DevolverTodosLivros();
    break;

    case 'L':
        DevolverUmLivro();
    break;

     case 'M':
        PublicacoesPorTitulo();
    break;

    case 'N':
        LivrosPorAutor();
    break;

    case 'O':
        ListarUsuarios();
    break;

    case 'P':
        ListarPublicacoes();
    break;

    case 'Q':
        ListarEmprestimos();
    break;

    case 'R':
        exit(0);
    break;

    }
}
