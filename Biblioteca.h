#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <string>
#include <list>
#include "Livro.h"
#include "Leitor.h"
#include "Emprestimo.h"
#include "LivroGenerico.h"
#include "LivroCientifico.h"
#include "LivroFiccao.h"
using namespace std;

class Biblioteca
{
	string NOME;
	list<Livro*> Livros;
	list<Leitor*> Leitores;
	list<Emprestimo*> Emprestimos;
	public:
		Biblioteca(string _nome);
		virtual ~Biblioteca();
		Livro* Add_Livros();
		Leitor* Add_Leitores();
		bool Add_Livro(Livro* L);
		bool Add_Leitor(Leitor* P);
		void Add_Emprestimo();
		bool load(string nf);
		bool save(string nf);
		void RelatorioCategoria(string cat);
		void Sistema_Not_atraso();
		void listagem_livros();
};

#endif 



