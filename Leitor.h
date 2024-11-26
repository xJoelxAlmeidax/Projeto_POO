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
	list<Emprestimo*> Historico_Emp;  
public:
	Leitor(string _ncc, string _nome, string _morada, string _telefone, int _idade);
	void AddHistEmprestimo(Emprestimo* E);
	void Mostrar_HistEmprestimo();
	virtual ~Leitor();
	void virtual Show();

	string get_ncc();
	string get_nome();
	string get_morada();
	string get_telefone();
	list<Emprestimo*> get_Emp();
	int get_idade();
	virtual string get_NecessidadesAcessibilidade() { return ""; }
	virtual string get_curso(){return "";}
	virtual string get_Email() { return ""; }
	virtual string get_Departamento() { return ""; }
	void mudarncc(string new_ncc);
	void mudarnome(string new_nome); 
	void mudarmorada(string new_morada);
	void mudartelefone(string new_telefone);
	void mudaridade(int new_idade);
	virtual void mudaremail(string new_email) {}	
	virtual void mudarNecessidades(string new_acessibilidade) {}
	virtual void mudarcurso(string new_curso){}
	virtual void mudarDepartamento(string new_Departamento){}
	virtual string quem_es();
};	
	
#endif