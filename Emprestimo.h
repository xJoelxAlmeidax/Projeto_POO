#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "Multa.h"
#include "Uteis.h"

struct DATA {
	int dia;
	int mes;
	int ano;
};
class Livro;
class Leitor;
class Emprestimo
{
	DATA DATA_INICIO;
	DATA DATA_MAX;
	DATA DATA_FIM;
	Leitor* Leitor_Emp;
	Livro* Livro_Emp;
public:
	Emprestimo(DATA _inicio, DATA _max, Leitor* Lei, Livro* Liv);
	~Emprestimo();
	int VerMulta(DATA dataInicio, DATA dataFim);
};
#endif