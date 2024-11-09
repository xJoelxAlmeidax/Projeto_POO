#ifndef UTEIS_H
#define UTEIS_H
#include <iostream>
#include <string>
#include <conio.h> 
#include <windows.h> 
#include <algorithm>
using namespace std;

void mostrarMenuTabs(int abaSelecionada, const char* tabs[], int num_tabs);
void mostrarMenuOpcoes(int opcaoSelecionada, const char* opcoes[], int numOpcoes);
string normalizarString(const string& texto);
bool validarEmail(const string& email);
bool validarTelefone(const string& telefone);

class Uteis
{
public:
	static bool AnoBisexto(int Ano);
	static int DiasNoMes(int Mes, int Ano);
	static int ConverterDataDias(int dia, int mes, int ano);
};
#endif
