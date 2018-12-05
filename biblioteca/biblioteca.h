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
        void additememp(Emprestimo emp, ItemEmprestimo item);
        int searchuser(Usuario &user);
        void deleteuser(Usuario &use);
        int searchpub(Publicacao &pub);
        void deletepub(Publicacao &pub);
        int searchemp(Emprestimo &emp);
        void deleteemp(Emprestimo &emp);
        void deleteitememp(Emprestimo emp, ItemEmprestimo item);
        void giveback(Emprestimo emp, Livro liv);// OlHAR A PARADA DA DATA
        void givebackall(Emprestimo &emp);
        vector <string> searchtitle(string t);
        vector <string> searchautor(string a);// TALVEZ NAO TENHA AUTOR
        vector <Usuario> getUsuarios();
        vector <Publicacao> getPublicacoes();
        vector <Emprestimo> getEmprestimos();
        void savefile();
        void readfile();
        void printtodosusuarios(){for(int i = 0; i < usuarios.size(); i++){usuarios[i].Printusuario(); cout<<"\n";}}


};
#endif // biblioteca.h
