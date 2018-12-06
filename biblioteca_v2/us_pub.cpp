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
// ----------- SOBRECARGAS----------
/*
ostream& operator<< (ostream& out,const Date& a){
        out << a.getDay();
        out <<endl;
        out << a.getMonth();
        out << endl;
        out << a.getYear();
        out <<endl;
                return out;
}*/

Date &Date::operator=(const Date &a){

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
}/*
Date &Date::operator+ (const Date &a){
    Date d;
    int diaproxmes;
        if ((a.dia + this->dia)>30){
            diaproxmes = ((dia+getDay())%30);
            if (diaproxmes >30){
                 getMonth() = (getMonth() +diaproxmes);
            }
        }
        if((getMonth()+admes)> 12){
            adano = (getMonth()+admes)%12;
        }
}*/

bool Date::operator< (const Date &a){
        if (a.calcdias() > calcdias())
            return true;
        else return false;
}


