#ifndef LIVRO_H
#define LIVRO_H
#include <iostream>
#include <string>
#include <list>
#include "Emprestimo.h"
#include "Leitor.h"
using namespace std;
class Livro
{
	string TITULO;
	string AUTOR;
	int ANO;
	list<Leitor*> Reservas;
	public:
		Livro(string titulo, string autor, int ano);
		void AddReserva(Leitor* P);
		void Mostrar_Reserva();
		virtual ~Livro();
		virtual void Show();


		//get
		string get_titulo();
		string get_autor();
		int get_ano();
		list<Leitor*> get_leitores();


		//gets extra
		virtual string get_issn() { return ""; }
		virtual string get_edicao() { return ""; }
		virtual string get_isbn() { return ""; }
		virtual string get_editora() { return ""; }
		virtual string get_fotografo() { return ""; }
		virtual string get_subgenero() { return ""; }
		virtual string get_area() { return ""; }
		virtual string get_idade() { return ""; }
		virtual string get_ilustrador() { return ""; }
		virtual string get_revisor() { return ""; }
		virtual string get_editor() { return ""; }
		virtual string get_tipo() { return ""; }

		//Mudar
		virtual void mudartitulo(string new_titulo);
		virtual void mudarautor(string new_autor);
		virtual void mudarano(int new_ano);
		virtual string quem_es();

		//Mudar extra
		virtual void mudarISSN(string new_issn){}
		virtual void mudaredicao(string new_edicao){}
		virtual void mudarISBN(string new_isbn){}
		virtual void mudareditora(string new_editora){}
		virtual void mudarfotografo(string new_fotografo){}
		virtual void mudarsubgenero(string new_sub){}
		virtual void mudaridade(string new_idade){}
		virtual void mudararea(string new_area){}
		virtual void mudarilustrador(string new_ilustrador){}
		virtual void mudarrevisor(string new_revisor){}
		virtual void mudareditor(string new_editor){}
		virtual void mudartipo(string new_tipo){}
};

#endif