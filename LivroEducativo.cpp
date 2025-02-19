#include "LivroEducativo.h"
LivroEducativo::LivroEducativo(string titulo, string autor, int ano,  string _ISBN, string _idaderec, string _area, string _ilustrador): LivroGenerico(titulo, autor, ano,  _ISBN), IDADE_REC(_idaderec), AREA(_area), ILUSTRADOR(_ilustrador){}
LivroEducativo::~LivroEducativo(){
	cout << "Destruindo Livro Educativo..." << endl;
}
void LivroEducativo::Show() {
	LivroGenerico::Show();
	cout << "Idade recomendada: " << IDADE_REC << endl;
	cout << "Area: " << AREA << endl;
	cout << "Ilustrador: " << ILUSTRADOR << endl;
}

string LivroEducativo::get_area()
{
	return AREA;
}

string LivroEducativo::get_idade()
{
	return IDADE_REC;
}

string LivroEducativo::get_ilustrador()
{
	return ILUSTRADOR;
}

void LivroEducativo::mudaridade(string new_idade) {
	IDADE_REC = new_idade;
}
void LivroEducativo::mudararea(string new_area) {
	AREA = new_area;
}
void LivroEducativo::mudarilustrador(string new_ilustrador) {
	ILUSTRADOR = new_ilustrador;
}

string LivroEducativo::quem_es() {
	return "LivroEducativo";
}