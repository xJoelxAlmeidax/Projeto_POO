#include "LivroCientifico.h"

LivroCientifico::LivroCientifico(string _titulo, string _autor, int _ano, string _isbn, string _areaestudo, string _revisor) : LivroGenerico(_titulo, _autor, _ano, _isbn), AREAESTUDO(_areaestudo), REVISORCIENTIFICO(_revisor){}
LivroCientifico::~LivroCientifico() {

}
void LivroCientifico::Show() {
	LivroGenerico::Show();
	cout << "Area de Estudo: " << AREAESTUDO << endl;
	cout << "Revisor Cientifico: " << REVISORCIENTIFICO << endl;
}