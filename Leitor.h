#ifndef LEITOR_H
#define LEITOR_H
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Leitor
{
	string N_CC;
	string NOME;
	string MORADA;
	string TELEFONE;
	int IDADE;
public:
	Leitor(string _ncc, string _nome, string _morada, string _telefone, int _idade);
	virtual ~Leitor();
	void virtual Show();

	string get_ncc();
	string get_nome();
	string get_morada();
	string get_telefone();
	int get_idade();
	virtual void mudarncc(string new_ncc);   //Será que faz sentido?
	virtual void mudarnome(string new_nome); //Será que faz sentido? pt2
	virtual void mudarmorada(string new_morada);
	virtual void mudartelefone(string new_telefone);
	virtual void mudaridade(int new_idade);
};	
	
#endif