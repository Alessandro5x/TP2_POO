#include <iostream>
#include <string>
#include "livro.h"
#include "periodicos.h"
#include "excecoes.h"
#include "emprestimo.h"
using namespace std;
int Emprestimo::proximoNumero = 0; // descobrir como tirar o static daqui


int main()
{


    Livro teste(123, "Titulo massa", "Editora Massa", 2019,"Autor bem massa", 42);
    Livro teste2(123, "Titulo massa 2 A vingança", "Editora Massa2", 2020,"Autor bem massa2", 10);
    Usuario u("a","b","c","d");
    Date D(1,1,1);
    Emprestimo E(D, u);
    E.adicionaE(teste);
    E.adicionaE(teste2);
    E.printemprestimo();


 /*
   periodicos revista(1234, "Revista massa", "Editora Massa", 2019, "janeiro", 33);
    revista.imprimirperiodico();
    teste.imprimirlivro();
    teste2.imprimirlivro();
    //try {
    //    teste.decrementar(43);
   //     } catch (ErroG &e) {e.out();}
*/


    return 0;
}
