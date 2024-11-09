#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <string>
#include <list>
#include <cctype>
#include <fstream> 
#include "Livro.h"
#include "Leitor.h"
#include "Emprestimo.h"
#include "LivroGenerico.h"
#include "LivroCientifico.h"
#include "LivroFiccao.h"
#include "LivroEducativo.h"
#include "Jornal.h"
#include "Revista.h"
#include "Uteis.h"


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
		bool load_file(string nf);
		bool save_file(string nf);
		void RelatorioCategorias();
		void Sistema_Not_atraso();
		void AlterarLivro();
		// Vai mostrar todos os livros dependendo do tipo que colocar na main quando se chama a funcao
		template <typename T>
		void listagem_livros()
		{
			for (list<Livro*>::iterator it = Livros.begin(); it != Livros.end(); ++it)
			{
				// dynaminc_cast metodo de polimorfismo para saber o tipo de livro
				if (dynamic_cast<T*>(*it)) {
					(*it)->Show();
					cout << "-------------------------------------" << endl;
				}
			}
		};
};

#endif 



