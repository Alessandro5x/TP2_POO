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
        vector<Publicacao> Pub;
        vector<Emprestimo> emprestimos;
    public:
        Biblioteca();
        void adduser(Usuario &use);
        void addpub(Publicacao &pub);
        void addemp(Emprestimo &emp);
        //void additememp(Emprestimo emp, ItemEmprestimo item);

        //pesquisas
        int searchuser(Usuario &user);
        int ProcuraCPF(string cpf);
        int searchpub(Publicacao &pub);
        int ProcuraEmp(int n);

        //deleta
        void deleteuser(Usuario &use);
        void deletepub(Publicacao &pub);
        //void deleteemp(Emprestimo emp);
        //void deleteitem(Emprestimo emp, ItemEmprestimo item);
        //void giveback(Emprestimo emp);

        //gets
        vector <Usuario> getUsuarios();
        vector <Publicacao> getPublicacoes();
        vector <Emprestimo> getEmprestimos();

        //impressoes
        void printtodosusuarios(){for(int i = 0; i < usuarios.size(); i++){usuarios[i].Printusuario(); cout<<"\n";}}
        void PrintTodasPublicacoes(){for(int i = 0; i < Pub.size(); i++){Pub[i].imprimirPub(); cout<<"\n";}}
        void PrintTodosEmprestimos(){for(int i = 0; i < emprestimos.size(); i++){emprestimos[i].PrintEmprestimo();cout<<"\n";}}


};
#endif // biblioteca.h
