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
        vector<Publicacao> livros;
        vector<Emprestimo> emprestimos;
    public:
        Biblioteca();
        void adduser(Usuario &use);
        void addpub(Publicacao &pub);
        void addemp(Emprestimo &emp);
        //void additememp(Emprestimo emp, ItemEmprestimo item);
        int searchuser(Usuario &user);
        void deleteuser(Usuario &use);
        int searchpub(Publicacao &pub);
        void deletepub(Publicacao &pub);
        //void deleteemp(Emprestimo emp);
        //void deleteitem(Emprestimo emp, ItemEmprestimo item);
        //void giveback(Emprestimo emp);
        vector <Usuario> getUsuarios();
        vector <Publicacao> getPublicacoes();
        vector <Emprestimo> getEmprestimos();


};
#endif // biblioteca.h
