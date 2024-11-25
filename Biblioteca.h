#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <string>
#include <list>
#include <cctype>
#include <fstream> 
#include "Emprestimo.h"
#include "Uteis.h"
#include "Livro.h"
#include "Leitor.h"
#include "LivroGenerico.h"
#include "LivroCientifico.h"
#include "LivroFiccao.h"
#include "LivroEducativo.h"
#include "Jornal.h"
#include "Revista.h"
#include "Estudante.h"
#include "Professor.h"
#include "LeitorComum.h"
#include "Senior.h"
using namespace std;

class Biblioteca
{
	string NOME;
	list<Livro*> Livros;
	list<Leitor*> Leitores;
	list<Emprestimo*> Emprestimos;
	list<Emprestimo*> Reservas;

	public:
		Biblioteca(string _nome);
		virtual ~Biblioteca();
		//LIVRO
		Livro* Add_Livros();
		bool Add_Livro(Livro* L);
		void AlterarLivro(Livro* L);
		void RemoverLivro(Livro* L);


		//LEITOR
		Leitor* Add_Leitores();
		bool Add_Leitor(Leitor* P);
		void AlterarLeitor(Leitor* L);
		void RemoverLeitor(Leitor* P);
		bool nccDuplicado(const string& ncc);
		

		//EMPRESTIMO
		Emprestimo* Add_Emprestimos();
		bool Add_Emprestimo_Reserva(Emprestimo* E);
		void EntregarLivro(Emprestimo* E);
		void Prorrogacao();
		void MostrarEmprestimo();
		void MultasPendentes();
		
		
		//LER E GUARDAR NO FICHEIRO
		bool load_file(string nf);
		bool save_file(string nf);

	
		// PESQUISA / LISTAGEM
		void RelatorioCategorias();
		void RelatorioLeitores();
		Livro* Pesquisar_L(const list<Livro*>& livros, int abaSelecionada, const char* tabs[], int num_tabs);
		Livro* ResultadoPesquisa();
		Leitor* Pesquisar_P(const list<Leitor*>& leitores, int abaSelecionada, const char* tabs[], int num_tabs);
		Leitor* ResultadoPesquisaP();
		Emprestimo* Pesquisar_E(const list<Emprestimo*>& emprestimos, int abaSelecionada, const char* tabs[], int num_tabs);
		Emprestimo* ResultadoPesquisaE();
		void listagemL(string tipo); // Vai mostrar todos os livros dependendo do tipo de livro que colocar na main quando se chama a funcao
		void listagemP(string tipo); // Vai mostrar todos os livros dependendo do tipo de livro que colocar na main quando se chama a funcao
	
		//GETS
		list<Livro*> get_Livros() {
			return Livros;
		}
		list<Leitor*> get_Leitores() {
			return Leitores;
		}
		list<Emprestimo*> get_Emprestimos() {
			return Emprestimos;
		}


		void Sistema_Notif_atraso();



		
};

#endif 



