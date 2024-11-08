#include "LivroGenerico.h"
LivroGenerico::LivroGenerico(string titulo, string autor, int ano,  string _ISBN) : Livro(titulo, autor, ano), ISBN(_ISBN){}
LivroGenerico::~LivroGenerico(){}

void LivroGenerico::Show(){
	Livro::Show();
	cout << "ISBN: " << ISBN << endl;
}

string LivroGenerico::get_isbn() {
	return ISBN;
}