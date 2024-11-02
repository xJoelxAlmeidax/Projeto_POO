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
	Biblioteca B_IPV("Biblioteca do Instituto Politécnico de Viseu");
	B_IPV.load();
	LivroGenerico L("Maria dos amaros", "AScas", 2023, "12359980324");
	L.Show();
	return 0;
}