#include <iostream>
#include <string>
#include <list>
#include <locale>
#include "Biblioteca.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	cout << "			Projeto de POO" << endl;
	cout << "------------------------------------------------------------" << endl;
	Biblioteca* B_IPV=new Biblioteca("Biblioteca do Instituto Polit�cnico de Viseu");
	B_IPV->load("Ficheiro");
	delete B_IPV;
	Livro* L = new LivroCientifico("Os Maias", "E�a de Queiroz", 1888, "93743928423", "Incesto");
	L->Show();
	return 0;
}