#include <iostream>
#include <string>
#include <vector>
#include "us_pub.h"
#include "livro.h"
#include "Emprestimo.h"
using namespace std;

Emprestimo::Emprestimo(Date DP, const Usuario &u) : usuario(u),DataPrevDevolucao(DP){
    numero = proximoNumero;
    /*data emprestimo = do sistema;*/

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
      if(l == itens[i].getL()){
        itens.erase(itens.begin()+i);
      }
    }

}
void Emprestimo::devolver(Livro &l){
     l.incrementar(1);
    //DataPrevDevolucao = data de agora
}
void Emprestimo::devolverT(){
   for(int i = 0; i < itens.size(); i++){
        //Livro l = itens[i].getL();
        //devolver(l);
   }
}
