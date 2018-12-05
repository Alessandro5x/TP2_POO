#ifndef US_PUB_H
#define US_PUB_H
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Usuario{

    private:
        string nome;
        string cpf;
        string endereco;
        string fone;

    public:
        Usuario(string n, string cp, string ende, string fon);
        //Usuario(const Usuario& U);
        //Usuario &operator= (const Usuario &u);
        void Printusuario(){cout<< nome <<", "<< cpf <<", "<< endereco <<", "<< fone << endl;}
        string getCPF(){return cpf;}
};
class Date{
    private:
        int dia;
        int mes;
        int ano;
    public:
        Date(int d = 0, int m = 0, int a = 0) : dia(d), mes(m), ano(a){}
};
class Publicacao{
    private:
        int codPublicacao;
        string titulo;
        string editora;
        int ano;
    public:
        Publicacao(int cod, string tit, string ed, int an) : codPublicacao(cod), titulo(tit), editora(ed), ano(an){}
        void imprimirPub(){cout << "codigo publicacao: " << codPublicacao << ", titulo: " << titulo << ", editora: " << editora << ", ano: " << ano << endl;}
        //Publicacao(const Publicacao& P);
        int getcod()const{return codPublicacao;}
        string gettitulo()const{return titulo;}
        int getano() const{return ano;}
        string geted() const{return editora;}
};


#endif // US_PUB_H
