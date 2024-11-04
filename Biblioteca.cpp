#include "Biblioteca.h"
Biblioteca::Biblioteca(string _nome) {
	NOME = _nome;
}
Biblioteca::~Biblioteca(){}

bool Biblioteca::Add_Livros() {
	return true;
}
bool Biblioteca::Add_Leitores() {
	return true;
}
bool Biblioteca::Add_Livro(Livro* L) {
	return true;
}
bool Biblioteca::Add_Leitor(Leitor* P) {
	return true;
}
void Biblioteca::Add_Emprestimo() {

}
bool Biblioteca::load(string nf) {
	return true;
}
bool Biblioteca::save(string nf) {
	return true;
}
void Biblioteca::RelatorioCategoria(string cat) {

}
void Biblioteca::Sistema_Not_atraso() {
	cout << "Entrei em" << __FUNCTION__ << endl;
}
void Biblioteca::listagem_livros() {

}
