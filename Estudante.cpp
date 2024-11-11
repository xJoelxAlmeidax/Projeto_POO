#include "Estudante.h"
Estudante::Estudante(string ncc, string nome, string morada, string telefone, int idade,string _email, string _Curso) : Leitor(ncc,nome,morada,telefone,idade), EMAIL(_email),Curso(_Curso){}
Estudante::~Estudante() {}

void Estudante::Show() {
	Leitor::Show();
	cout << "Email: " << EMAIL << endl;
	cout << "Curso: " << Curso << endl;
}

string Estudante::get_curso() {
	return Curso;
}

string Estudante::get_Email() {
	return EMAIL;
}

void Estudante::mudaremail(string new_email) {
	EMAIL = new_email;
}
void Estudante::mudarcurso(string new_curso) {
	Curso = new_curso;
}
string Estudante::quem_es() {
	return "Estudante";
}