#include <iostream>
#include <string>
#include <vector>
#include "us_pub.h"
#include "livro.h"
#include "Emprestimo.h"
using namespace std;

//construtor
Emprestimo::Emprestimo(Date DP, Usuario u) : usuario(u),DataPrevDevolucao(DP){
    Date atual;
    if (atual < u.DataPenalizacao){throw ErroG("-----Usuario com restricao-----");}
    numero = proximoNumero;
    proximoNumero = proximoNumero + 1;
}
Emprestimo::~Emprestimo()
{
   itens.clear();
}

//adicionar
void Emprestimo::adicionaE(Livro *l){
    l->decrementar(1);
    itens.push_back(ItemEmprestimo(l));
}

//excluir e devolver
void Emprestimo::excluiE(Livro *l){

    l->incrementar(1);
    cout<<"chegcou no excluiE"<<endl;
    for(int i = 0; i < itens.size(); i++){
      if(l == itens[i].livro){
        itens.erase(itens.begin()+i);
      }
    }

}


void Emprestimo::devolver(Livro *l){
    cout<< "chegou no devolver emprestimo";
     Date atual; int x;
     x = (atual -DataPrevDevolucao);
     if(x >=1){usuario.DataPenalizacao = usuario.NewPenalizacao(atual,x);}

    int i = ProcuraItem(l);

     l->incrementar(1);
     itens[i].SetDataDevolucao(atual);
     //cout<< DataPrevDevolucao;
}


void Emprestimo::devolverT(){

   for(int i = 0; i < itens.size(); i++){
        devolver(itens[i].livro);
   }
}

//Procurar
int Emprestimo::ProcuraItem(Livro *l){
    for(int i = 0; i<itens.size();i++){
        if(l->getcod()== itens[i].getCodigo()){return i;}
    }
    return -1;
}

//imprimir
void Emprestimo::PrintEmprestimo(){
    cout<<"Numero: "<< numero <<", data emprestimo: " << DataEmprestimo << ", data prevista de devolucao: " << DataPrevDevolucao <<", usuario: \n    >";
    usuario.Printusuario();
    cout<<"    >Itens desse emprestimo:";
    for(int i = 0; i < itens.size(); i++){
            cout<<"\n\t>>Livro:\n\t\t>>>";
            itens[i].printItemEmprestimo();
    }
    cout<<endl;
}

