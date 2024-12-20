#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H
#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "Multa.h"
#include "Uteis.h"
class Livro;
class Leitor;

class DATA {
public:
	int DIA;
	int MES;
	int ANO;
	DATA() {
		time_t t = time(nullptr);
		tm data_atual;
		localtime_s(&data_atual, &t);
		DIA = data_atual.tm_mday;
		MES = data_atual.tm_mon + 1;
		ANO = data_atual.tm_year + 1900;
	}
	DATA(int _dia, int _mes, int _ano) : DIA(_dia), MES(_mes), ANO(_ano){}
	~DATA() {}
	void adicionar_dias(int num_dias) {
		while (num_dias > 0) {
			int diasNoMesAtual = DiasNoMes(MES, ANO);
			if (num_dias + DIA <= diasNoMesAtual) {
				DIA += num_dias;
				num_dias = 0;
			}
			else {
				num_dias -= (diasNoMesAtual - DIA + 1);
				DIA = 1;
				MES++;
				if (MES > 12) {
					MES = 1;
					ANO++;
				}
			}
		}
	}
};


class Emprestimo
{
	DATA DATA_INICIO;
	int DIAS;
	DATA DATA_ENTREGA; // DATA EM QUE O LEITOR ENTREGOU
	DATA DATA_FIM; //DATA MAXIMA PARA ENTREGA DENTRO DO PRAZO
	float MULTA;
	Leitor* Leitor_Emp;
	Livro* Livro_Emp;
public:
	Emprestimo(DATA _inicio, Leitor* _leitor, Livro* _livro, int _dias, DATA _entrega);
	~Emprestimo();
	float Valor_Multa();
	void AdicionarMulta();
	int calcularDIAS(int dias);
	DATA data_fim();
	void pedir_prorrogacao(int dias);
	DATA get_dataInicio();
	DATA get_dataFim();
	DATA get_dataEntregaLeitor();
	Livro* get_livro();
	Leitor* get_leitor();
	int get_dias();
	void Show();
	void Alterar_dataEntrega(DATA entrega);
	float AplicarDesconto(float multa);

};
#endif