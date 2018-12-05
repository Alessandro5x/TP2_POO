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

void Interface::casos(){
    char a;
    cin >> a;
    switch(a){
    case 'A':
        Nusuario();
    break;

    case 'B':

    break;

    case 'C':

    break;

    case 'D':

    break;

    case 'E':

    break;

    case 'F':

    break;

    case 'G':

    break;

    case 'H':

    break;

    case 'I':

    break;

    case 'J':

    break;

    case 'K':
        Imprimirusuarios();
    break;

    case 'L':

    break;

     case 'M':

    break;

    case 'N':
    exit(0);
    break;
    }
}
