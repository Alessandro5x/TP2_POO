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

