#ifndef EXCECOES_H_INCLUDED
#define EXCECOES_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class ErroG{
    string tipo_erro;
    public:
    ErroG(const string &tp): tipo_erro(tp){};
    void out(){cout << tipo_erro;};
};


#endif // EXCECOES_H_INCLUDED
