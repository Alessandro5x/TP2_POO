#include <iostream>
#include <string>
#include "livro.h"
#include "periodicos.h"
#include "excecoes.h"
#include "emprestimo.h"
#include "interface.h"
using namespace std;
int Emprestimo::proximoNumero = 1; // descobrir como tirar o static daqui

int main()
{

    Biblioteca B;
    Interface I(B);
    int y = 0;
    while(y == 0){
        I.menu();
        I.casos();
    }

    return 0;
}
