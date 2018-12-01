#ifndef TP2_H
#define TP2_H
#include <iostream>
#include <vector>
using namespace std;

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
class Livro : public Publicacao
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

class ItemEmprestimo{
    private:
        Date dataDevolucao;
        Livro livro;
    public:
        ItemEmprestimo(Livro liv);
};

class Emprestimo
{
    private:
        int numero;
        Date DataEmprestimo;
        Date DataPrevDevolucao;
        Usuario usuario;
        vector <ItemEmprestimo> itens;
        static int proximoNumero;
    public:
        //Emprestimo(int n, Date DE, Date PD, Usuario &u);

};

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

#endif // TP2_H
