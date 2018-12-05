#ifndef biblioteca_H
#define biblioteca_H
#include <iostream>
#include <vector>
using namespace std;

class Biblioteca{
    private:
        vector<Usuario> usuarios;
        vector<Publicacao> livros;
        vector<ItemEmprestimo> emprestimos;
    public:
        Biblioteca();
        void adduser(Usuario use);
        void addpub(Publicacao pub);
        void addemp(Emprestimo emp);
        void additememp(Emprestimo emp, ItemEmprestimo item);
        //void deleteuser(Usuario use);
        //void deletepub(Publicacao pub);
        //void deleteemp(Emprestimo emp);
        //void deleteitem(Emprestimo emp, ItemEmprestimo item);
        //void giveback(Emprestimo emp);
        void getUsuarios();
        void getPublicacoes();
        void getEmprestimos();




};
#endif // biblioteca.h
