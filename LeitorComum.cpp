#include "LeitorComum.h"
LeitorComum::LeitorComum(string ncc, string nome, string morada, string telefone, int idade, string _email) : Leitor(ncc, nome, morada, telefone,idade), EMAIL(_email){}
LeitorComum::~LeitorComum() {}

void LeitorComum::Show() {
	Leitor::Show();
	cout << "Email: " << EMAIL << endl;
}

string LeitorComum::get_Email() {
	return EMAIL;
}

void LeitorComum::mudaremail(string new_email) {
	EMAIL = new_email;
}

string LeitorComum::quem_es() {
	return "LeitorComum";
}