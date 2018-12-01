#include <iostream>
#include <string>
#include "livro.h"
#include "periodicos.h"
#include "excecoes.h"
using namespace std;

int main()
{

    Livro teste(123, "Titulo massa", "Editora Massa", 2019,"Autor bem massa", 42);
    Livro teste2(123, "Titulo massa 2 A vingança", "Editora Massa", 2019,"Autor bem massa");
    periodicos revista(1234, "Revista massa", "Editora Massa", 2019, "janeiro", 33);
    revista.imprimirperiodico();
    teste.imprimirlivro();
    teste2.imprimirlivro();
    //try {
    //    teste.decrementar(43);
   //     } catch (ErroG &e) {e.out();}

    return 0;
}
