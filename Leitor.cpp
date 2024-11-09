#include "Leitor.h"

Leitor::Leitor(string _ncc, string _nome, string _morada, string _telefone, int _idade) {
	N_CC = _ncc;
	NOME = _nome;
	MORADA = _morada;
	TELEFONE = _telefone;
	IDADE = _idade;
}
Leitor::~Leitor() {

}
void Leitor::Show() {
	cout << "Nome: " << NOME << endl;
	cout << "CC: " << N_CC << endl;
	cout << "Morada: " << MORADA << endl;
	cout << "Tlm: " << TELEFONE << endl;
	cout << "Idade: " << IDADE << endl;
}

string Leitor::get_ncc()
{
	return N_CC;
}

string Leitor::get_nome()
{
	return NOME;
}

string Leitor::get_morada()
{
	return MORADA;
}

string Leitor::get_telefone()
{
	return TELEFONE;
}

int Leitor::get_idade()
{
	return IDADE;
}