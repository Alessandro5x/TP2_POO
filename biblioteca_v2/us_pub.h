#ifndef US_PUB_H
#define US_PUB_H
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Date{
    private:
        int dia;
        int mes;
        int ano;
    public:
        Date(int d, int m, int a) : dia(d), mes(m), ano(a){}
        Date();
        int getDay() const { return dia; }
        int getMonth()const { return mes; }
        int getYear() const { return ano; }
        int calcdias() const ;
        Date &operator= (const Date &a);
        int& operator- (const Date &a);
        Date operator+ (const int &a);
        bool operator< (const Date &a);

        friend ostream& operator<< (ostream &out,const Date& a);
};
class Usuario{

    private:
        string nome;
        string cpf;
        string endereco;
        string fone;

    public:
        Date DataPenalizacao;
        Date NewPenalizacao(Date a, int dias);
        Usuario(string n, string cp, string ende, string fon);
        void Printusuario(){cout<<"nome: "<< nome <<", cpf: "<< cpf <<", endereco: "<< endereco <<", fone: "<< fone << endl;}
        string getCPF(){return cpf;}
        string getName(){ return nome;}
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
