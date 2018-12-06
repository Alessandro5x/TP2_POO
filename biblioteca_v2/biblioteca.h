#ifndef biblioteca_H
#define biblioteca_H
#include <iostream>
#include <vector>
#include "livro.h"
#include "us_pub.h"
#include "Emprestimo.h"

using namespace std;

class Biblioteca{
    private:
        vector<Usuario> usuarios;
        vector<Publicacao*> Pub;
        vector<Emprestimo> emprestimos;
    public:
        Biblioteca();
        void adduser(Usuario &use);
        void addpub(Publicacao *pub);
        void addemp(Emprestimo &emp);
        void additememp(Emprestimo emp, ItemEmprestimo item);

        //pesquisas
        int searchuser(Usuario &user);
        int ProcuraCPF(string cpf);
        int searchpub(Publicacao *pub);
        int ProcuraLivro(int cod);
        int searchemp(Emprestimo &emp);
        int ProcuraEmp(int cod);

        //deleta
        void deleteuser(Usuario &use);
        void deletepub(Publicacao* pub);
        void deleteemp(Emprestimo &emp);
        void deleteitememp(Emprestimo emp, ItemEmprestimo item);
        void giveback(Emprestimo emp, Livro liv);// OlHAR A PARADA DA DATA
        void givebackall(Emprestimo &emp);

        //gets
        vector <string> searchtitle(string t);
        vector <int> searchtitle2(string t);
        vector <string> searchautor(string a);// TALVEZ NAO TENHA AUTOR
        vector <int> searchautor2(string a);
        vector <Usuario> getUsuarios();
        vector <Publicacao*> getPublicacoes();
        vector <Emprestimo> getEmprestimos();
        void savefile();
        void readfile();

        //impressoes
        void printtodosusuarios(){for(int i = 0; i < usuarios.size(); i++){usuarios[i].Printusuario(); cout<<"\n";}}
        void PrintTodasPublicacoes(){for(int i = 0; i < Pub.size(); i++){Pub[i]->imprimirPub(); cout<<"\n";}}
        void PrintTodosEmprestimos(){for(int i = 0; i < emprestimos.size(); i++){emprestimos[i].PrintEmprestimo();cout<<"\n";}}


};
#endif // biblioteca.h
