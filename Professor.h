#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
#include <string>
#include <list>
#include "Leitor.h"
class Professor : public Leitor
{
	string EMAIL;
	string Departamento;

	public:
		Professor(string ncc, string nome, string morada, string telefone, int idade,string _email, string _Departamento);
		virtual ~Professor();
		void Show();
		string get_Departamento();
		string get_Email();
		void mudaremail(string new_email);
		void mudarDepartamento(string new_Departamento);
		string quem_es();
};
#endif