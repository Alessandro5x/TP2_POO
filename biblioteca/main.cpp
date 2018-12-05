#include <iostream>
#include <string>
#include "livro.h"
#include "periodicos.h"
#include "excecoes.h"
#include "emprestimo.h"
#include "interface.h"
using namespace std;
int Emprestimo::proximoNumero = 0; // descobrir como tirar o static daqui


int main()
{
Biblioteca B;
Interface I(B);
I.menu();
I.casos();
I.Imprimirusuarios();

cout<<endl;

cout<<"FIM DOS TESTES DA INTERFACE--------------------------------------------------------"<<endl;

    Livro teste(1, "Titulo massa", "Editora Massa", 2019,"Autor bem massa", 1);
    Livro teste2(2, "Titulo massa 2 A vingança", "Editora Massa2", 2020,"Autor bem massa2", 2);
    Livro teste3(3, "Titulo massa 3 O chefe final", "Editora Massa3", 2023,"Autor bem massa3", 3);
    Usuario u("a","b","c","d");

    Date D(1,1,1);
    Emprestimo E(D, u);
    E.adicionaE(teste);
    E.adicionaE(teste2);
    E.adicionaE(teste3);
    cout<<"-------imprimindo teste---------"<<endl;
    teste.imprimirlivro();
    cout<<"------------acabou---------------"<<endl;
    E.printemprestimo();
    cout<< "------------excluindo-----------" << endl;
   // E.excluiE(teste2);
    E.devolverT();
    E.printemprestimo();
    //teste2.imprimirlivro();


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
