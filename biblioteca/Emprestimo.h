#ifndef EMPRESTIMO_H_INCLUDED
#define EMPRESTIMO_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "us_pub.h"
using namespace std;

class Emprestimo
{
    private:
        int numero;
        Date DataEmprestimo;
        Date DataPrevDevolucao;
        Usuario usuario;
        // vector <ItemEmprestimo> itens;
        static int proximoNumero;
    public:
        //Emprestimo(int n, Date DE, Date PD, Usuario &u);

};


#endif // EMPRESTIMO_H_INCLUDED
