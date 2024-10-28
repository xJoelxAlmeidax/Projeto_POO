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
	public:
		Biblioteca(string _nome);
		virtual ~Biblioteca();

};

#endif 



