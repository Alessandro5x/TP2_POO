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
Date::Date() {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	day = ltm->tm_mday;
	month = 1 + ltm->tm_mon;
	year = 1900 + ltm->tm_year;
}
