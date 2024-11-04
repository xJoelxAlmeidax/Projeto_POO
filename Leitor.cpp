#include "Leitor.h"

Leitor::Leitor(string _ncc, string _nome, string _morada, string _telefone) {
	N_CC = _ncc;
	NOME = _nome;
	MORADA = _morada;
	TELEFONE = _telefone;
}
Leitor::~Leitor() {

}
void Leitor::Show() {
	cout << "Nome: " << NOME << endl;
	cout << "CC: " << N_CC << endl;
	cout << "Morada: " << MORADA << endl;
	cout << "Tlm: " << TELEFONE << endl;
}