#include<iostream>
#include <string>
#include "us_pub.h"
#include <vector>
#include <ctime>
using namespace std;

Usuario::Usuario(string n, string cp, string ende, string fon){
    nome = n;
    cpf = cp;
    endereco = ende;
    fone = fon;
}
Date::Date() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	dia = ltm->tm_mday;
	mes = 1 + ltm->tm_mon;
	ano = 1900 + ltm->tm_year;
}

int Date::calcdias ()const {
    int aux;
    aux = ((dia) + (mes*30) + (ano*365));
    return aux;
}
Date Usuario::NewPenalizacao(Date a, int dias){return a+(dias*3);}

// --------------- SOBRECARGAS----------------

ostream& operator<< (ostream& out,const Date& a){
        out << a.getDay();
        out << "/";
        out << a.getMonth();
        out << "/";
        out << a.getYear();
                return out;
}

Date Date::operator=(const Date &a){

    this->dia = a.dia;
    this->mes = a.mes;
    this->ano = a.ano;
  return *this;

  }
int& Date::operator -(const Date &a){
    int aux,aux1,aux2;
        aux1 = a.calcdias();
        aux = (a.calcdias() - this->calcdias());
    return aux;
}
Date Date::operator+ (const int &a){
    int auxdia = dia;
    int auxmes = mes;
    int auxano = ano;
        if ((dia + a)>30){
            auxmes =  mes+((dia + a)/30);
            auxdia = (dia+a)%30;
            auxano = ano;
        }else {
            auxdia = dia + a;
            auxmes = mes;
            auxano = ano;}
        if (auxmes > 12){
            auxdia = auxdia;
            auxano =  ano + (auxmes/12);
            auxmes = auxmes%12;
        }
        Date d(auxdia,auxmes,auxano);
        return d;
}


bool Date::operator< (const Date &a){
        if (a.calcdias() > calcdias())
            return true;
        else return false;
}


