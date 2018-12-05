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

void Emprestimo::adicionaE(Livro &l){
    l.decrementar(1);

    //itens.push_back(l);
}

void Emprestimo::excluiE(Livro &l){
    l.incrementar(1);

}
void Emprestimo::devolver(Livro &l){

}
void Emprestimo::devolverT(){

}
