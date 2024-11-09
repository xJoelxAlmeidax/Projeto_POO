#include "Livro.h"
Livro::Livro(string titulo, string autor, int ano) {
	TITULO = titulo;
	AUTOR = autor;
	ANO = ano;
}
Livro::~Livro(){
	cout << "Destruindo Livro..." << endl;
}

void Livro::Show() {
	cout << "Título: " << TITULO << endl;
	cout << "Autor: " << AUTOR << endl;
	cout << "Ano: " << ANO << endl; 
}

string Livro::get_titulo() {
	return TITULO;
}
string Livro::get_autor() {
	return AUTOR;
}
int Livro::get_ano() {
	return ANO;
}

void Livro::mudartitulo(string new_titulo) {
	TITULO = new_titulo;
}
void Livro::mudarautor(string new_autor) {
	AUTOR = new_autor;
}
void Livro::mudarano(int new_ano){
	ANO = new_ano;
}