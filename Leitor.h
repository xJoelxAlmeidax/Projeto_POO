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
public:
	Leitor(string _ncc, string _nome, string _morada, string _telefone);
	virtual ~Leitor();
	void virtual Show();

};

#endif