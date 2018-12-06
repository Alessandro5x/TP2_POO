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
int Date::calcdias(){
    int aux;
    aux = ((getDay()) + (getMonth()*30) + (getYear()*365));
    return aux;
}
// ----------- SOBRECARGAS----------

ostream& operator<< (ostream& out,const Date& a){
        out << a.getDay();
        out <<endl;
        out << a.getMonth();
        out << endl;
        out << a.getYear();
        out <<endl;
                return out;
}
int& Date::operator -(const Date &a){
    int aux;
        aux = (a.calcdias() - calcdias());
    return aux;
}
Date &Date::operator+ (const Date &a, int dias){
    int diaproxmes
        if ((dias + getDay())>30){
            diaproxmes = ((dias+getDay())%30);
            if (diaproxmes >30){
                 getMonth() = (getMonth() +diaproxmes);
            }
        }
        if((getMonth()+admes) >12){
            adano = (getMonth()+admes)%12;
        }
}

bool Date::operator <(const Date &a){
        if (a.calcdias() > calcdias())
            return true;
        else return false;
}


