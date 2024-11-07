#include "LivroEducativo.h"
LivroEducativo::LivroEducativo(string titulo, string autor, int ano,  string _ISBN, string _idaderec, string _area, string _ilustrador): LivroGenerico(titulo, autor, ano,  _ISBN), IDADE_REC(_idaderec), AREA(_area), ILUSTRADOR(_ilustrador){}
LivroEducativo::~LivroEducativo(){}
void LivroEducativo::Show() {
	LivroGenerico::Show();
	cout << "Idade recomendada: " << IDADE_REC << endl;
	cout << "Area: " << AREA << endl;
	cout << "Ilustrador: " << ILUSTRADOR << endl;
}