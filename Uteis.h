#ifndef UTEIS_H
#define UTEIS_H
#include <iostream>
#include <string>
#include <conio.h> 
#include <windows.h> 
#include <algorithm>
#include <cctype>
#include <regex>
using namespace std;

void mostrarMenuTabs(int abaSelecionada, const char* tabs[], int num_tabs);
void mostrarMenuOpcoes(int opcaoSelecionada, const char* opcoes[], int numOpcoes);
string normalizarString(const string& texto);
bool validarEmail(const string& email);
bool validarTelefone(const string& telefone);
bool validarNCC(const string& ncc);
bool So_numeros(string num);
bool AnoBissexto(int Ano);
int DiasNoMes(int Mes, int Ano);
int ConverterDataDias(int dia, int mes, int ano);

class Uteis
{
public:
	
};
#endif
