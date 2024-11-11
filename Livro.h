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
	list<Emprestimo*> Emp;
	list<Leitor*> Reservas;
public:
	Livro(string titulo, string autor, int ano);
	virtual ~Livro();
	virtual void Show();
	virtual string get_titulo();
	virtual string get_autor();
	virtual int get_ano();
	virtual void mudartitulo(string new_titulo);
	virtual void mudarautor(string new_autor);
	virtual void mudarano(int new_ano);
	virtual string quem_es();
};

#endif