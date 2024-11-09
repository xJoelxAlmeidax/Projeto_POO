#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include <iostream>
#include <string>
#include <list>
#include "Leitor.h"

class Estudante : public Leitor
{
	string EMAIL;
	string Curso;
	public:
	Estudante(string ncc, string nome, string morada, string telefone, int idade, string _email, string _Curso);
	virtual ~Estudante();
	void Show();
	string get_curso();
	string get_Email();
	void mudaremail(string new_email);
	void mudarcurso(string new_curso);
};

#endif