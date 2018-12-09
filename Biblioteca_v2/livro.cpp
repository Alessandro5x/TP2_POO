#include <iostream>
#include <string>
#include "livro.h"
#include "excecoes.h"
#include "us_pub.h"
using namespace std;

void Livro::imprimirlivro(){
    cout<< "autores: " << autores << ", Quantidade:" << qtdeExemplares << ", ";
    imprimirPub();
}

void Livro::incrementar(int i){
    qtdeExemplares = qtdeExemplares + i;
}

void Livro::decrementar(int d){
    if( qtdeExemplares - d < 0) throw ErroG("\n<ERRO> Decrementacao maior que qtd de exemplares");
    qtdeExemplares = qtdeExemplares - d;
}

bool Livro::operator ==(const Livro&a){
    if(this->autores != a.autores || this->getcod() != a.getcod() || this->getano() != a.getano() || this->gettitulo() != a.gettitulo()){
       return false;
    }
    return true;
}
