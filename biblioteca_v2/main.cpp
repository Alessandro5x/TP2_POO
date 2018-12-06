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
    /*
    Biblioteca B;
    Interface I(B);
    int y = 0;
    while(y == 0){
        I.menu();
        I.casos();
    }
*/

//Date D;
//D.printD();
cout<<endl;

//cout<<"FIM DOS TESTES DA INTERFACE--------------------------------------------------------"<<endl;

    Livro teste(1, "Titulo massa", "Editora M", 2019,"Autor1", 1);
    Livro teste2(2, "Titulo massa 2", "Editora M2", 2020,"Autor2", 2);
    Livro teste3(3, "Titulo massa 3", "Editora M3", 2023,"Autor3", 3);
    periodicos testeP1(5, "Per 1", "Ed P1", 2201, "jan", 1);
    periodicos testeP2(6, "Per 2", "Ed P2", 2202, "fev", 2);

    Usuario u("a","b","c","d");

    Date D(1,1,1);
    Emprestimo E(D, u);
    E.adicionaE(teste);
    E.adicionaE(teste2);
    E.adicionaE(teste3);
    //cout<<"-------imprimindo teste---------"<<endl;
    //teste.imprimirlivro();
    //cout<<"------------acabou---------------"<<endl;
    E.PrintEmprestimo();
   // cout<< "------------excluindo-----------" << endl;
   // E.excluiE(teste2);
   // E.devolverT();
   // E.PrintEmprestimo();
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
