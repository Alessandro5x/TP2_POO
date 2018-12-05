#include<iostream>
#include <string>
#include "us_pub.h"
#include <vector>
using namespace std;

Usuario::Usuario(string n, string cp, string ende, string fon){
    nome = n;
    cpf = cp;
    endereco = ende;
    fone = fon;
}

/*
Usuario::Usuario(const Usuario &U){

    this->nome = U.nome;
    this->cpf = U.cpf;
    this->endereco = U.endereco;
    this->fone = U.fone;

}

Usuario &Usuario::operator=(const Usuario &u){

    this->nome = u.nome;
    this->cpf = u.cpf;
    this->endereco = u.endereco;
    this->fone = u.fone;

   return *this;

}
*/

/*
Publicacao::Publicacao(const Publicacao &P){
    codPublicacao = P.codPublicacao;
    titulo = P.titulo;
    editora = P.editora;
    ano = P.ano;

}
*/
