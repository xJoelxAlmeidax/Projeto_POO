#include "LivroFiccao.h"
LivroFiccao::LivroFiccao(string titulo, string autor, int ano, string _ISBN, string _subgenero): LivroGenerico(titulo, autor, ano, _ISBN), SUBGENERO(_subgenero){}
LivroFiccao::~LivroFiccao(){
	cout << "Destruindo Livro de Fic��o..." << endl;
}
void LivroFiccao::Show(){
	LivroGenerico::Show();
	cout << "Subg�nero: " << SUBGENERO << endl;
}

string LivroFiccao::get_subgenero()
{
	return SUBGENERO;
}

void LivroFiccao::mudarsubgenero(string new_sub) {
	SUBGENERO = new_sub;
}