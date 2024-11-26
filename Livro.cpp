#include "Livro.h"
Livro::Livro(string titulo, string autor, int ano) {
	TITULO = titulo;
	AUTOR = autor;
	ANO = ano;
}

void Livro::AddReserva(Leitor* P)
{
	Reservas.push_back(P);
}

void Livro::Mostrar_Reserva(){
	if(Reservas.empty())
		cout << "Nenhuma reserva para este livro";
	else
	{
		cout << "Pessoas com reserva no livro " << TITULO << "\n";
		for (auto reserva : Reservas) { 	//Percorre a lista de reservas do livro
			cout << "Nome: " << reserva->get_nome() << " | CC: " << reserva->get_ncc() << endl;	//Mostra o requesitante do livro
		}
	}
	
}

list<Leitor*> Livro::get_leitores(){
	return Reservas;
}

Livro::~Livro(){
	cout << "Destruindo Livro..." << endl;
}

string Livro::quem_es() {
	return "";
}

void Livro::Show() {
	cout << "Título: " << TITULO << endl;
	cout << "Autor: " << AUTOR << endl;
	cout << "Ano: " << ANO << endl; 
}

string Livro::get_titulo() {
	return TITULO;
}
string Livro::get_autor() {
	return AUTOR;
}
int Livro::get_ano() {
	return ANO;
}

void Livro::mudartitulo(string new_titulo) {
	TITULO = new_titulo;
}
void Livro::mudarautor(string new_autor) {
	AUTOR = new_autor;
}
void Livro::mudarano(int new_ano){
	ANO = new_ano;
}