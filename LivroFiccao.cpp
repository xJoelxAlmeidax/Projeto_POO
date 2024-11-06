#include "LivroFiccao.h"
LivroFiccao::LivroFiccao(string titulo, string autor, int ano,string tipo, string _ISBN, string _subgenero): LivroGenerico(titulo, autor, ano,tipo, _ISBN), SUBGENERO(_subgenero){}
LivroFiccao::~LivroFiccao(){}
void LivroFiccao::Show(){
	LivroGenerico::Show();
	cout << "Subgénero: " << SUBGENERO << endl;
}