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
        void Printusuario(){cout<<"nome: "<< nome <<", cpf: "<< cpf <<", endereco: "<< endereco <<", fone: "<< fone << endl;}
        string getCPF(){return cpf;}
        string getName(){ return nome;}
};
class Date{
    private:
        int dia;
        int mes;
        int ano;
    public:
        Date(int d = 0, int m = 0, int a = 0) : dia(d), mes(m), ano(a){}
        Date();
        int getDay() { return dia; };
        int getMonth() { return mes; };
        int getYear() { return ano; }
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

        //gets
        int getcod()const{return codPublicacao;}
        string gettitulo()const{return titulo;}
        int getano() const{return ano;}
        string geted() const{return editora;}
        virtual string getAutor(){return "1";}
};


#endif // US_PUB_H
