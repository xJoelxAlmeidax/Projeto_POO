#include "Biblioteca.h"
Biblioteca::Biblioteca(string _nome) {
	NOME = _nome;
}
Biblioteca::~Biblioteca(){}

Livro* Biblioteca::Add_Livros() {
	cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	string tipo_uti;
	string titulo;
	string autor;
	int ano; 
	cout << "Título: ";
	cin >> titulo;
	cout << "Autor: ";
	cin >> autor;
	cout << "Ano: ";
	cin >> ano;
	Livro* L = NULL;
	do {
		cout << "Tipo de Livro(Ficcao/Cientifico/Educativo/Jornal/Revista): ";
		cin >> tipo_uti;
		if (tipo_uti == "Ficcao") {
			string _ISBN;
			string _subgenero;
			cout << "ISBN: ";
			cin >> _ISBN;
			cout << "subgenero: ";
			cin >> _subgenero;
			L = new LivroFiccao(titulo, autor, ano, _ISBN, _subgenero);
			break;
		}
		else if (tipo_uti == "Cientifico") {
			string _ISBN;
			string _areaestudo;
			string _revisor;
			cout << "ISBN: ";
			cin >> _ISBN;
			cout << "Area Estudo: ";
			cin >> _areaestudo;
			cout << "Revisor Cientifico: ";
			cin >> _revisor;
			L = new LivroCientifico(titulo,autor,ano,_ISBN, _areaestudo,_revisor);
			break;
		}
		else if (tipo_uti == "Educativo") {
			string _ISBN;
			string _idaderec;
			string _area;
			string _ilustrador;
			cout << "ISBN: ";
			cin >> _ISBN;
			cout << "Idade: ";
			cin >> _idaderec;
			cout << "Area: ";
			cin >> _area;
			cout << "Ilustrador: ";
			cin >> _ilustrador;
			L = new LivroEducativo(titulo, autor,ano,_ISBN,_idaderec,_area,_ilustrador);
			break;
		}
		else if (tipo_uti == "Jornal") {
			//L = new Jornal();
			break;
		}
		else if (tipo_uti == "Revista") {
			//L = new Revista();
			break;
		}
		else {
			cout << "Não é valida! Tente novamente!" << endl;
		}

	} while (true);
	//Ver biblioteca para testar acentos
	
	return L;
}
Leitor* Biblioteca::Add_Leitores() {
	return NULL;
}
bool Biblioteca::Add_Livro(Livro* L) {
	cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	Livros.push_back(L);
	return true;
}
bool Biblioteca::Add_Leitor(Leitor* P) {
	return true;
}
void Biblioteca::Add_Emprestimo() {

}
bool Biblioteca::load(string nf) {
	return true;
}
bool Biblioteca::save(string nf) {
	return true;
}
void Biblioteca::RelatorioCategoria(string cat) {

}
void Biblioteca::Sistema_Not_atraso() {
	cout << "Entrei em" << __FUNCTION__ << endl;
}


