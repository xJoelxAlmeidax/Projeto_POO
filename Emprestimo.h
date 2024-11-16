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
	bool isLeapYear(int ano) const {
		return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
	}
	int dias_mes(int mes, int ano) const {
		switch (mes) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return isLeapYear(ano) ? 29 : 28;
		default:
			return 0; // Mês inválido
		}
	}
	void adicionar_dias(int num_dias) {
		while (num_dias > 0) {
			int diasNoMesAtual = dias_mes(MES, ANO);
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
	DATA DATA_FIM;
	DATA DATA_ENTREGA;
	Leitor* Leitor_Emp;
	Livro* Livro_Emp;
public:
	Emprestimo(DATA _inicio, Leitor* _leitor, Livro* _livro);
	~Emprestimo();
	int Valor_Multa(DATA dataInicio, DATA dataFim);
	int calcularDIAS();
	DATA data_entrega();
	void pedir_prorrogacao(int dias);
};
#endif