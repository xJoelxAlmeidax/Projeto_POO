#ifndef SENIOR_H
#define SENIOR_H
#include <iostream>
#include <string>
#include <list>
#include "Leitor.h"
class Senior : public Leitor
{
	string NecessidadesAcessibilidade;

	public:
		Senior(string ncc, string nome, string morada, string telefone,int idade, string _NecessidadesAcessibilidade);
		virtual~Senior();
		void Show();
		string get_NecessidadesAcessibilidade();
		void mudarNecessidades(string new_acessibilidade);
		string quem_es();
};

#endif