#include "LivroCientifico.h"

LivroCientifico::LivroCientifico(string _titulo, string _autor, int _ano, string _isbn, string _areaestudo, string _revisor) : LivroGenerico(_titulo, _autor, _ano, _isbn), AREAESTUDO(_areaestudo), REVISORCIENTIFICO(_revisor){}
LivroCientifico::~LivroCientifico() {
	cout << "Destruindo Livro Cientifico..." << endl;

}
void LivroCientifico::Show() {
	LivroGenerico::Show();
	cout << "Area de Estudo: " << AREAESTUDO << endl;
	cout << "Revisor Cientifico: " << REVISORCIENTIFICO << endl;
}
string LivroCientifico::get_area() {
	return AREAESTUDO;
}

string LivroCientifico::get_revisor() {
	return REVISORCIENTIFICO;
}

void LivroCientifico::mudararea(string new_area) {
	AREAESTUDO = new_area;
}
void LivroCientifico::mudarrevisor(string new_revisor) {
	REVISORCIENTIFICO = new_revisor;
}

string LivroCientifico::quem_es() {
	return "LivroCientifico";
}