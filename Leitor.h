#ifndef LEITOR_H
#define LEITOR_H
#include <iostream>
#include <string>
#include <list>
using namespace std;
#include "Emprestimo.h"
class Leitor
{
	string N_CC;
	string NOME;
	string MORADA;
	string TELEFONE;
	int IDADE;
	list<Emprestimo*> Emp;
public:
	Leitor(string _ncc, string _nome, string _morada, string _telefone, int _idade);
	virtual ~Leitor();
	void virtual Show();

	string get_ncc();
	string get_nome();
	string get_morada();
	string get_telefone();
	int get_idade();
	virtual void mudarncc(string new_ncc);   //Ser� que faz sentido? R: se calhar NIF faz mais sentido pois � definitivo (2mas)
	virtual void mudarnome(string new_nome); //Ser� que faz sentido? pt2 R: pah yh (2mas)
	virtual void mudarmorada(string new_morada);
	virtual void mudartelefone(string new_telefone);
	virtual void mudaridade(int new_idade);
	virtual string quem_es();
};	
	
#endif