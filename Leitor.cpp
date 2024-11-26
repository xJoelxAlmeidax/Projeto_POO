#include "Leitor.h"

Leitor::Leitor(string _ncc, string _nome, string _morada, string _telefone, int _idade) {
	N_CC = _ncc;
	NOME = _nome;
	MORADA = _morada;
	TELEFONE = _telefone;
	IDADE = _idade;
}
Leitor::~Leitor() {

}

string Leitor::quem_es() {
	return "";
}
void Leitor::Show() {
	cout << "Nome: " << NOME << endl;
	cout << "CC: " << N_CC << endl;
	cout << "Morada: " << MORADA << endl;
	cout << "Tlm: " << TELEFONE << endl;
	cout << "Idade: " << IDADE << endl;
}

string Leitor::get_ncc()
{
	return N_CC;
}

string Leitor::get_nome()
{
	return NOME;
}

string Leitor::get_morada()
{
	return MORADA;
}

string Leitor::get_telefone()
{
	return TELEFONE;
}

int Leitor::get_idade()
{
	return IDADE;
}

void Leitor::mudarncc(string new_ncc) {
	N_CC = new_ncc;
}
void Leitor::mudarnome(string new_nome) {
	NOME = new_nome;
}
void Leitor::mudarmorada(string new_morada) {
	MORADA = new_morada;
}
void Leitor::mudartelefone(string new_telefone) {
	TELEFONE = new_telefone;
}
void Leitor::mudaridade(int new_idade) {
	IDADE = new_idade;
}

void Leitor::AddHistEmprestimo(Emprestimo* E)
{
	Historico_Emp.push_back(E);
}

list<Emprestimo*> Leitor::get_Emp()
{
	return Historico_Emp;
}

void Leitor::Mostrar_HistEmprestimo()
{
	if (Historico_Emp.empty())
		cout << "Nenhum Emprestimo realizado ate ao momento" << endl;
	else
	{
		int teste = 0;
		cout << "Emprestimos Já Feitos pelo " << NOME << "\n";
		for (auto hist_emp : Historico_Emp) { 	//Percorre a lista de reservas do livro
			// mostrar os livros ja requisitados
			teste++;
		}

		cout << "Num de livros Requisitados: " << teste;
	}
}