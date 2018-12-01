#include <iostream>
#include <string>
#include "livro.h"
#include "excecoes.h"
#include "us_pub.h"
using namespace std;

void livro::imprimirlivro(){
    cout<< "autores: " << autores << "| Quantidade:" << qtdeExemplares << endl;
    imprimirPub();
}

void livro::incrementar(int i){
    qtdeExemplares = qtdeExemplares + i;
}

void livro::decrementar(int d){
    if( qtdeExemplares - d < 0) throw ErroG("\n<ERRO> Decrementacao maior que qtd de exemplares");
    qtdeExemplares = qtdeExemplares - d;
}
