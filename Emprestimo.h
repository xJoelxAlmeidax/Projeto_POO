#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "Multa.h"
#include "Uteis.h"
class Livro;
class Leitor;

class DATA {
public:
	int dia;
	int mes;
	int ano;
	void adicionar_dias(int num_dias);
};
//struct DATA {
//	int dia;
//	int mes;
//	int ano;
//};


class Emprestimo
{
	DATA DATA_INICIO;
	int DIAS;
	DATA DATA_FIM;
	Leitor* Leitor_Emp;
	Livro* Livro_Emp;
public:
	Emprestimo(DATA _inicio,Leitor* _leitor, Livro* _livro);
	~Emprestimo();
	int VerMulta(DATA dataInicio, DATA dataFim);
	void calcularDIAS();
};
#endif