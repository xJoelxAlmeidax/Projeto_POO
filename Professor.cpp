#include "Professor.h"
Professor::Professor(string ncc, string nome, string morada, string telefone,int idade, string _email, string _disciplinas) : Leitor(ncc, nome, morada, telefone, idade), EMAIL(_email), Disciplinas(_disciplinas) {}
Professor::~Professor() {}

void Professor::Show() {
	Leitor::Show();
	cout << "Disciplinas: " << Disciplinas << endl;
}

string Professor::get_Disciplinas() {
	return Disciplinas;
}

string Professor::get_Email() {
	return EMAIL;
}
