#ifndef TP2_H
#define TP2_H
#include <iostream>
#include <vector>

class Usuario{

    private:
        string nome;
        string cpf;
        string endereco;
        string fone;

    public:
        Usuario(string n, string cp, string ende, string fon);
};
class Date{
    private:
        int dia;
        int mes;
        int ano;
};
class Publicacao{
    private:
        int codPublicacao;
        string titulo;
        string editora;
        int ano;

};
class ItemEmprestimo{
    private:
        Date dataDevolucao;
        livro livro;
    public:
        ItemEmprestimo(livro liv);
};
class livro : Publicacao
{
    private:
        string autores;
        int qtdeExemplares;
    public:
        livro(string a, int q);
        void imprimirlivro(); //TESTE APAGAR DEPOOIS
        void incrementar(int i);
        void decrementar(int d);
};
class Biblioteca{
    private:
        vector<Usuario> usuarios;
        vector<Publicacao> livros;
        vector<ItemEmprestimo> emprestimos;
    public:
        Biblioteca();
        Biblioteca(Usuario use);
        Biblioteca(Publicacao pub);
        Biblioteca(ItemEmprestimo Item);



};

#endif // TP2_H
