#include "Livro.h"
Livro::Livro(string titulo, string autor, int ano) {
	TITULO = titulo;
	AUTOR = autor;
	ANO = ano;
}
Livro::~Livro(){}

void Livro::Show() {
	cout << "T�tulo: " << TITULO << endl;
	cout << "Autor: " << AUTOR << endl;
	cout << "Ano: " << ANO << endl; 
}