#include <iostream>
#include <string>
#include "livro.h"
#include "periodicos.h"
#include "excecoes.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    livro teste("Autor bem massa", 42);
    periodicos revista("janeiro", 33);
    revista.imprimirperiodico();
    teste.imprimirlivro();
    try {
        teste.decrementar(43);
        } catch (ErroG &e) {e.out();}

    return 0;
}
