#include "Livro.h"
Livro::Livro(string titulo, string autor, int ano, string _tipo) {
	TITULO = titulo;
	AUTOR = autor;
	ANO = ano;
	TIPO = _tipo;
}
Livro::~Livro(){}

void Livro::Show() {
	cout << "TIPO:" << TIPO << endl;
	cout << "Título: " << TITULO << endl;
	cout << "Autor: " << AUTOR << endl;
	cout << "Ano: " << ANO << endl; 
}