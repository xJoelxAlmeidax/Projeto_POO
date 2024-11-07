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
};

#endif