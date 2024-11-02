#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <string>
#include <list>
#include "Livro.h"
#include "Leitor.h"
#include "Emprestimo.h"
using namespace std;

class Biblioteca
{
	string NOME;
	list<Livro*> Livro;
	list<Leitor*> Leitor;
	list<Emprestimo*> Emprestimo;
	public:
		Biblioteca(string _nome);
		virtual ~Biblioteca();
		void virtual show();
		void load();
		void save();
};

#endif 



