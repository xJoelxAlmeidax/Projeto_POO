#include <iostream>
#include <string>
#include <list>
#include <locale>
#include "Biblioteca.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
	cout << "Projeto de POO" << endl;
	Biblioteca B_IPV("Biblioteca do Instituto Politécnico de Viseu");
	return 0;
}