#include "Jornal.h"
Jornal::Jornal(string _titulo, string _autor, int _ano, string _issn, string _edicao, string _editor_boss, string _tipo_dis): OutrosLivros(_titulo, _autor, _ano, _issn, _edicao), EDITOR_CHEFE(_editor_boss), TIPO_DISTRIBUICAO(_tipo_dis) {}
Jornal::~Jornal() {
	cout << "Destruindo Jornal..." << endl;
}
void Jornal::Show() {
	OutrosLivros::Show();
	cout << "Editor Chefe: " << EDITOR_CHEFE <<endl;
	cout << "Distribuição Geográfica: " << TIPO_DISTRIBUICAO << endl;
}

string Jornal::get_editor()
{
	return EDITOR_CHEFE;
}

string Jornal::get_tipo() 
{
	return TIPO_DISTRIBUICAO;
}