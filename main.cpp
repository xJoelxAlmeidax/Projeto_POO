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
	Biblioteca* B_IPV=new Biblioteca("Biblioteca do Instituto Politécnico de Viseu");
	B_IPV->load("Ficheiro");
	delete B_IPV;
	Livro* L = new LivroCientifico("Os Maias", "Eça de Queiroz", 1888, "93743928423", "Incesto");
	L->Show();
	return 0;
}