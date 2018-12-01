#ifndef US_PUB_H
#define US_PUB_H
#include<iostream>
#include <string>
using namespace std;

class Usuario{

    private:
        string nome;
        string cpf;
        string endereco;
        string fone;

    public:
        Usuario(string n, string cp, string ende, string fon);
};
class Date{
    private:
        int dia;
        int mes;
        int ano;
};
class Publicacao{
    private:
        int codPublicacao;
        string titulo;
        string editora;
        int ano;

};

#endif // US_PUB_H
