#include "LivroCientifico.h"

LivroCientifico::LivroCientifico(string _titulo, string _autor, int _ano, string _isbn, string _areaestudo) : LivroGenerico(_titulo, _autor, _ano, _isbn), areaEstudo(_areaestudo){}
LivroCientifico::~LivroCientifico() {

}
void LivroCientifico::Show() {
	LivroGenerico::Show();
	cout << "Area de Estudo: " << areaEstudo << endl;
}