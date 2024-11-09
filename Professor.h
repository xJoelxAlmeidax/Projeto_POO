#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
#include <string>
#include <list>
#include "Leitor.h"
class Professor : public Leitor
{
	string EMAIL;
	string Disciplinas;

	public:
		Professor(string ncc, string nome, string morada, string telefone, int idade,string _email, string _Disciplinas);
		virtual ~Professor();
		void Show();
		string get_Disciplinas();
		string get_Email();
		void mudaremail(string new_email);
		void mudardisciplina(string new_disciplina);
};
#endif