#ifndef UTEIS_H
#define UTEIS_H
#include <iostream>
#include <string>
#include <conio.h> 
#include <windows.h> 
#include <algorithm>
using namespace std;

void mostrarMenuTabs(int abaSelecionada);
void mostrarMenuOpcoes(int opcaoSelecionada, const char* opcoes[], int numOpcoes);
string normalizarString(const string& texto);
bool validarEmail(const string& email);
bool validarTelefone(const string& telefone);

class Uteis
{
public:
	
};
#endif
