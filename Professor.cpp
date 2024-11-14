#include "Professor.h"
Professor::Professor(string ncc, string nome, string morada, string telefone,int idade, string _email, string _Departamento) : Leitor(ncc, nome, morada, telefone, idade), EMAIL(_email), Departamento(_Departamento) {}
Professor::~Professor() {}

void Professor::Show() {
	Leitor::Show();
	cout << "Departamento: " << Departamento << endl;
}

string Professor::get_Departamento() {
	return Departamento;
}

string Professor::get_Email() {
	return EMAIL;
}

void Professor::mudaremail(string new_email) {
	EMAIL = new_email;
}
void Professor::mudarDepartamento(string new_Departamento) {
	Departamento = new_Departamento;
}

string Professor::quem_es() {
	return "Professor";
}



