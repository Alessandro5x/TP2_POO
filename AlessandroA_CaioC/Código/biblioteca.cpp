#include<iostream>
#include <fstream>
#include <stdlib.h>
#include "biblioteca.h"
#include <vector>
#include <sstream>
#include "us_pub.h"
#include "livro.h"
#include "periodicos.h"
#include "Emprestimo.h"
#include "excecoes.h"

using namespace std;

Biblioteca::Biblioteca(){
    usuarios = {};
    Pub = {};
    emprestimos = {};

}
void Biblioteca::adduser(Usuario &use){
    if((ProcuraCPF(use.getCPF())) == -1){
            usuarios.push_back(use);}
    else{ throw ErroG("-----CPF ja cadastrado-----"); }

}

void Biblioteca::addpub(Publicacao *pub){
    int i = pub->getcod();
    if(ProcuraLivro(i) == -1){
        Pub.push_back(pub);
        }
    else {throw ErroG("-----Codigo ja cadastrado-----");}
}

void Biblioteca::addemp(Emprestimo &emp){emprestimos.push_back(emp);}

void Biblioteca::setEmpr(int i, Livro*l){
            if (l){
                    if(l->getqtdeExemplares()){
                        emprestimos[i].adicionaE(l);
                        }
                    else throw ErroG("-----Livro sem saldo-----");

            }else{ throw ErroG("------Periodicos nao podem ser emprestados-----");}
}

//procuras
int Biblioteca::searchuser(Usuario &user){

    for(int i = 0; i <= usuarios.size();i++){
        if (user.getCPF() == usuarios[i].getCPF()){
            return i;
    }
 }
 return -1;
}

int Biblioteca::ProcuraCPF(string cpf){

    //if (usuarios.size() == 0)
      //  return 0;
    for(int i = 0; i < usuarios.size();i++){
            if (cpf == usuarios[i].getCPF()){
            return i;
    }
 }
 return -1;
}

int Biblioteca::ProcuraLivro(int cod){
    for(int i = 0; i < Pub.size();i++){
        if (cod == Pub[i]->getcod()){
            return i;
    }
 }
 return -1;
}

int Biblioteca::searchemp(Emprestimo &emp){
    for(int i = 0; i <= emprestimos.size();i++){
        if(emp.getNumero() == emprestimos[i].getNumero()){
            return i;
    }
 }return -1;
}

int Biblioteca::ProcuraEmp(int cod){
    for(int i = 0; i <= emprestimos.size();i++){
        if(cod == emprestimos[i].getNumero()){
            return i;
    }
 }
 return -1;
}


vector<int> Biblioteca::searchtitle(string a){
    vector <int> result;
    for (int i = 0;i<Pub.size();i++){
        Livro *l = dynamic_cast<Livro*>(getPublicacoes()[i]);
            if(l && (l->gettitulo().compare(0, a.length(), a) == 0)){
                result.push_back(Pub[i]->getcod());
                        }
                }
        return result;
}

vector<int> Biblioteca::searchautor(string a){
   vector <int> result;

    for (int i = 0;i<Pub.size();i++){
        Livro *l = dynamic_cast<Livro*>(getPublicacoes()[i]);
            if(l && (l->getAutor().compare(0, a.length(), a) == 0)){
                result.push_back(Pub[i]->getcod());
                        }
                }
        return result;
}
// Validação

bool Biblioteca::itememprestimo(Publicacao *p){

    for(int i = 0; i <emprestimos.size();i++){
            for(int j = 0; j< emprestimos[i].getVecItens().size();j++){
        if (p->getcod()== emprestimos[i].getVecItens()[j].getCodigo())
            return true;
        }}

    return false;
}
bool Biblioteca::validaProcura(int cod){
    if(this->ProcuraLivro(cod)  == -1){
        throw ErroG("-----Publicacao nao encontrada-----");
    }  else true;
}

bool Biblioteca::validaProcuraCPF(string cpf){
    if(this->ProcuraCPF(cpf) == -1){
        throw ErroG("-----CPF invalido-------");
    } else true;
}

//deletes
void Biblioteca::deleteuser(Usuario &use){
    if (searchuser(use) >=0){
    usuarios.erase(usuarios.begin() + searchuser(use));}
    else throw ErroG("-----Usuario com emprestimo-----");
}

void Biblioteca::deleteemp(Emprestimo& emp){
    if (searchemp(emp) >=0){
    emprestimos.erase(emprestimos.begin() + searchemp(emp));
    }
    else throw ErroG("-----Nao existe esse emprestimo-----");
}

void Biblioteca::deleteitememp(Emprestimo emp, ItemEmprestimo item){
        emp.excluiE(item.livro);

}

void Biblioteca::deletepub(Publicacao *pub){
    if(itememprestimo(pub) ==  true){
        throw ErroG("-----Tem emprestimo-----");
    }
    int i = ProcuraLivro(pub->getcod());
    Pub.erase(Pub.begin() + i);
}



//GETS

vector<Usuario> Biblioteca::getUsuarios(){

        return usuarios;
}

vector<Publicacao*> Biblioteca::getPublicacoes(){

    return Pub;
}

vector<Emprestimo> Biblioteca::getEmprestimos(){

    return emprestimos;
}

//impressoes
void Biblioteca::printtodosusuarios(){
    for(int i = 0; i < usuarios.size(); i++){
            usuarios[i].Printusuario();
            cout<<"\n";
    }
}
void Biblioteca::PrintTodasPublicacoes(){
    for(int i = 0; i < Pub.size(); i++){
            Pub[i]->imprimirPub();
            cout<<"\n";
    }
}

void Biblioteca::PrintLivrosEPeriodicos(){

    for(int i = 0; i < Pub.size(); i++){
            Livro *l = dynamic_cast<Livro*>(Pub[i]);
            if(l){
                l->imprimirlivro();
            }
            else{
                periodicos *p = dynamic_cast<periodicos*>(Pub[i]);
                p->imprimirperiodico();
            }
            cout<<"\n";
    }
}

void Biblioteca::PrintTodosEmprestimos(){
    for(int i = 0; i < emprestimos.size(); i++){
            emprestimos[i].PrintEmprestimo();
            cout<<"\n";
    }
}

//-------------------------Arquivos----------------------------------------------------------

void Biblioteca::savefile(){
    ofstream out("Usuarios.txt");
    ofstream Publi("Publicacoes.txt");
    ofstream Empre("Emprestimos.txt");
    for(int i = 0;i < usuarios.size();i++){
        out << usuarios[i].getName() << ";" << usuarios[i].getCPF()<< ";" ;
        out << usuarios[i].getEnd() << ";" << usuarios[i].getFone();
        out<<"\n";
    }
    for(int i = 0;i < Pub.size();i++){
        Livro *l = dynamic_cast<Livro*>(Pub[i]);
        if(l){
        Publi<<"l"<<";"<<Pub[i]->getcod() << ";"<< Pub[i]->gettitulo() << ";" << Pub[i]->geted();
        Publi<< ";" <<Pub[i]->getano()<<";"<<l->getAutor()<<";"<<l->getqtdeExemplares();
        Publi<<"\n";
        }
        else{
        periodicos *p = dynamic_cast<periodicos*>(Pub[i]);
        Publi<<"p"<<";"<<Pub[i]->getcod() << ";"<< Pub[i]->gettitulo() << ";" << Pub[i]->geted();
        Publi<< ";" << Pub[i]->getano()<<";"<<p->getMes()<<";"<<p->getnumEdicao();
        Publi<<"\n";
        }
    }
    for(int i = 0;i < emprestimos.size();i++){
        Empre << emprestimos[i].getDia() << ";" << emprestimos[i].getMes() << ";" ;
        Empre << emprestimos[i].getAno() << ";" << emprestimos[i].getCPFU();
        Empre<<"\n";
    }
}

void Biblioteca::readfile(){
    ifstream usuario("Usuarios.txt");
    ifstream pub("Publicacoes.txt");
    ifstream perio("Periodicos.txt");
    ifstream emp("Emprestimos.txt");
    string a,linestream,b,linestream1;

    if (usuario.is_open()) {
        string line;
        while(getline(usuario, line)){
                stringstream linestream(line);
                //variaveis:
                string nome;
                string cpf;
                string endereco;
                string fone;

                //pegando do arquivo:
                getline(linestream, nome, ';');
                getline(linestream, cpf, ';');
                getline(linestream, endereco, ';');
                getline(linestream, fone, ';');
                Usuario U(nome, cpf, endereco, fone);
                //adicionando na biblioteca:
                adduser(U);
         }

    }

    if (pub.is_open()) {
        string line;
        while(getline(pub, line)){
            stringstream linestream(line);

                //variaveis:
				string l_ou_p; //escolher se vai ser periodico ou livro
				string scodigo;
				int codigo;
				string titulo;
				string editora;
				string sano;
				int ano;
				//informacao de livro
				string autores;
				string sqt_exemp;
				int qt_exemp;
				//informacao de periodico
				string mes;
				string snedicao;
				int nedicao;

				//lendo o arquivo e guardando nas strings

				getline(linestream, l_ou_p, ';');
				string comparal; comparal = 'l';
				string comparap; comparap = 'p';

				//caso for livro
				if(l_ou_p.compare(comparal) == 0){

                    getline(linestream, scodigo, ';');
                    stringstream Tcodigo(scodigo);
                    Tcodigo >> codigo;
                    getline(linestream, titulo, ';');
                    getline(linestream, editora, ';');
                    getline(linestream, sano, ';');
                    stringstream Tano(sano);
                    Tano >> ano;

                    getline(linestream, autores, ';');
                    getline(linestream, sqt_exemp, ';');
                    stringstream Tqt_exemp(sqt_exemp);
                    Tqt_exemp >> qt_exemp;

                    addpub(new Livro(codigo, titulo, editora, ano, autores, qt_exemp));
				}

				//caso for periodico

				else if(l_ou_p.compare(comparap) == 0){
                    getline(linestream, scodigo, ';');
                    stringstream Tcodigo(scodigo);
                    Tcodigo >> codigo;
                    getline(linestream, titulo, ';');
                    getline(linestream, editora, ';');
                    getline(linestream, sano, ';');
                    stringstream Tano(sano);
                    Tano >> ano;

                    getline(linestream, mes, ';');
                    getline(linestream, snedicao, ';');
                    stringstream Tnedicao(snedicao);
                    Tnedicao >> nedicao;
                    addpub(new periodicos(codigo, titulo, editora, ano, mes, nedicao));

			}
		}
    }



    if (emp.is_open()) {
        string line;
        while(getline(emp, line)){
                stringstream linestream(line);
                //variaveis
                string cpf;
                string sdia, smes, sano;
                int dia, mes, ano;

                //pegando do arquivo
                getline(linestream, sdia, ';');
                stringstream Tdia(sdia);
                Tdia >> dia;

                getline(linestream, smes, ';');
                stringstream Tmes(smes);
                Tmes >> mes;

                getline(linestream, sano, ';');
                stringstream Tano(sano);
                Tano>>ano;

                getline(linestream, cpf, ';');
                try{
                Date data(dia,mes,ano);
                data.validadata();
                int i = ProcuraCPF(cpf);
                Emprestimo E(data, getUsuarios()[i]);
                addemp(E);
                }catch(ErroG &E){
                E.out();
                system("pause");
                }
            }
     }
}



