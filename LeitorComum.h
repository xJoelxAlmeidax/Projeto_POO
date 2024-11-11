#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H
#include <iostream>
#include <string>
#include <list>
#include "Leitor.h"
class LeitorComum: public Leitor
{
	string EMAIL;
	public:
		LeitorComum(string ncc, string nome, string morada, string telefone, int idade, string _email);
		virtual ~LeitorComum();
		void Show();
		string get_Email();
		void mudaremail(string new_email);
		string quem_es();
};

#endif