#include <iostream>
#include <string>
#include <vector>
#include "us_pub.h"
#include "livro.h"
#include "Emprestimo.h"
using namespace std;

Emprestimo::Emprestimo(Date DP, const Usuario &u) : usuario(u),DataPrevDevolucao(DP){
    numero = proximoNumero;
    proximoNumero = proximoNumero + 1;
}
Emprestimo::~Emprestimo()
{
   itens.clear();
}

void Emprestimo::adicionaE(Livro &l){
    l.decrementar(1);
    itens.push_back(ItemEmprestimo(l));
}

void Emprestimo::excluiE(Livro &l){

    l.incrementar(1);

    for(int i = 0; i < itens.size(); i++){
      if(l == itens[i].livro){
        itens.erase(itens.begin()+i);
      }
    }

}
void Emprestimo::devolver(Livro &l){
    Date d;
    int x;
    if (DataPrevDevolucao < d){
           x =  d-DataPrevDevolucao;
    } x = x*3;
    Date legal;
    legal = d + x;
     l.incrementar(1);
    //DataPrevDevolucao = data de agora
}
void Emprestimo::devolverT(){
   for(int i = 0; i < itens.size(); i++){
        itens[i].livro.incrementar(1);
        //devolver(l);
   }
}

void Emprestimo::PrintEmprestimo(){
    cout<<"Numero: "<< numero <<", data emprestimo: " <<"fazer" << ", data prevista de devolucao: " << "a fazer"<<", usuario: \n    >";
    usuario.Printusuario();
    cout<<"    >Itens desse emprestimo:";
    for(int i = 0; i < itens.size(); i++){
            cout<<"\n\t>>Livro:\n\t\t>>>";
            itens[i].printItemEmprestimo();
    }
    cout<<endl;
}
/*

Livro Emprestimo::EncontraL(int cod){
    for(int i = 0; i < itens.size(); i++){
      if(cod == itens[i].livro.getcod()){
        return (itens[i].livro);
      }
    }
}
*/
