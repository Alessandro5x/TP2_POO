#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Interface.h"

using namespace std;

void Interface::Nusuario(){
    string nome, cpf, endereco, fone;
    cout<<"insira o nome:";
    cin>>nome;
    cout<<"insira o cpf:";
    cin>>cpf;
    cout<<"insira o endereco:";
    cin>>endereco;
    cout<<"insira o fone:";
    cin>>fone;
    Usuario U(nome,cpf,endereco,fone);
    B.adduser(U);
}

void Interface::Nlivro(){
    int cod; string tit; string ed; int an; string a; int q;
    cout<<"Insira o codigo: ";
    cin>> cod;
    cout<<"Insira o titulo: ";
    cin>> tit;
    cout<<"Insira a edicao: ";
    cin>> ed;
    cout<<"Insira o ano: ";
    cin>> an;
    cout<<"Insira os autores: ";
    cin>> a;
    cout<<"Insira a quantidade de exemplares: ";
    cin>> q;
    Livro L(cod, tit, ed, an, a, q);
    B.addpub(L);
}

void Interface::NPeriodico(){
    int cod; string tit; string ed; int an; string m; int n;
    cout<<"Insira o codigo: ";
    cin>> cod;
    cout<<"Insira o titulo: ";
    cin>> tit;
    cout<<"Insira a edicao: ";
    cin>> ed;
    cout<<"Insira o ano: ";
    cin>> an;
    cout<<"Insira os mes: ";
    cin>> m;
    cout<<"Insira o numero de edicao: ";
    cin>> n;
    periodicos P(cod, tit, ed, an, m, n);
    B.addpub(P);
}

void Interface::NEmprestimo(){
    string Ucpf; int d,m,a,i;
    cout<<"Insira o CPF do usuario: ";
    cin>> Ucpf;
    cout<<"Insira a data prevista para devolucao: ";
    cin>> d >> m >> a;
    Date D(d,m,a);
    i = B.ProcuraCPF(Ucpf);
    Emprestimo E(D, B.getUsuarios()[i]);
    B.addemp(E);
}

void Interface::NItemEmprestimo(){
    int nE, cl;
    cout<<"Insira o numero do emprestimo: ";
    cin>>nE;
    cout<<"Insira o codigo do livro: ";
    cin>> cl;
}

void Interface::ExcluiUsuario(){

}

void Interface::ExcluiLivro(){

}

void Interface::ExcluiPeriodico(){

}

void Interface::ExcluiEmprestimo(){

}

void Interface::ExcluiItemEmprestimo(){

}

void Interface::DevolverTodosLivros(){

}


void Interface::casos(){
    char a;
    cin >> a;
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
       ExcluiEmprestimo();
    break;

    case 'H':
        ExcluiItemEmprestimo();
    break;

    case 'I':
        cout<<"\npesquisar publicacoes por tittulo"<<endl;
    break;

    case 'J':
        cout<<"\npesquisar livros por autor"<<endl;
    break;

    case 'K':
        Imprimirusuarios();
    break;

    case 'L':
        ListarPublicacoes();
    break;

     case 'M':
        ListarEmprestimos();
    break;

    case 'N':
    exit(0);
    break;
    }
}
