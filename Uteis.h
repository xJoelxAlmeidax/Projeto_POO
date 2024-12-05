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
bool ValidarISBN(const string& ISSN);
bool ValidarISSN(const string& ISSN);
bool So_numeros(string num);
bool AnoBissexto(int Ano);
int DiasNoMes(int Mes, int Ano);
int ConverterDataDias(int dia, int mes, int ano);
void subs_systpause();
void EncerrarPrograma();
void Envelope(int step);
void moverparalado();


string gerarNomesJornais();
string gerar_nome_autor();
int gerar_anos();
string gerarISBNUnico(vector<string>& geradosISBN);
string gerarISSNUnico(vector<string>& geradosISSN);
string gerarEDICAO();
string gerareditorBoss();
string gerar_tipo_dis();
int idadeRecomendada(const string& livro);






class Uteis
{

public:
	
};
#endif
