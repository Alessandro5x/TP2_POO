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
    Interface menu(B);
    menu.Menu_main();
    return 0;
}
