#include "OutrosLivros.h"
OutrosLivros::OutrosLivros(string _titulo, string _autor, int _ano, string _issn, string _edicao): Livro(_titulo, _autor, _ano), ISSN(_issn), EDICAO(_edicao) {}
OutrosLivros::~OutrosLivros(){
}
void OutrosLivros::Show(){
	Livro::Show();
	cout << "ISSN: " << ISSN << endl;
	cout << "Edição: " << EDICAO << endl;
}