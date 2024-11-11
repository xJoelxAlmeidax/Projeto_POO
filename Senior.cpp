#include "Senior.h"
Senior::Senior(string ncc, string nome, string morada, string telefone,int idade, string _NecessidadesAcessibilidade) : Leitor(ncc, nome, morada, telefone,idade), NecessidadesAcessibilidade(_NecessidadesAcessibilidade) {}
Senior::~Senior() {}

void Senior::Show() {
	Leitor::Show();
	cout << "Necessidades de Acessibilidade: " << NecessidadesAcessibilidade << endl;
}

string Senior::get_NecessidadesAcessibilidade() {
	return NecessidadesAcessibilidade;
}

void Senior::mudarNecessidades(string new_acessibilidade) {
	NecessidadesAcessibilidade = new_acessibilidade;
}

string Senior::quem_es() {
	return "Senior";
}