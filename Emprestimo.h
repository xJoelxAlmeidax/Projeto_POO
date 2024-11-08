#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include <iostream>
#include <string>
#include <list>
#include "Multa.h"
struct DATA {
	int dia;
	int mês;
	int ano;
};
class Livro;
class Leitor;
class Emprestimo
{
	DATA DATA_INICIO;
	DATA DATA_MAX;
	DATA DATA_FIM;
	Leitor *Leitor_Emp;
	Livro *Livro_Emp;
public:
	Emprestimo(DATA _inicio, DATA _max, Leitor* Lei, Livro* Liv);
	~Emprestimo();
};

#endif