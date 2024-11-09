#include "Revista.h"
Revista:: Revista(string _titulo, string _autor, int _ano, string _issn, string _edicao, string _editora, string _fotografo) : OutrosLivros(_titulo, _autor, _ano, _issn, _edicao), EDITORA(_editora), FOTOGRAFO_CAPA(_fotografo) {}
Revista::~Revista(){
	cout << "Destruindo Revista..." << endl;
}
void Revista::Show(){
	OutrosLivros::Show();
	cout << "Editora:" << EDITORA << endl;
	cout << "Fotografo da Capa:" << FOTOGRAFO_CAPA << endl;
}

string Revista::get_editora()
{
	return EDITORA;
}
string Revista::get_fotografo()
{
	return FOTOGRAFO_CAPA;
}