#include "Emprestimo.h"
#include "Livro.h"
#include "Leitor.h"
Emprestimo::Emprestimo(DATA _inicio, Leitor* _leitor, Livro* _livro,int _dias, DATA _entrega){


	DATA_INICIO = _inicio;
	Leitor_Emp = _leitor;
	Livro_Emp = _livro;
	DIAS=calcularDIAS(_dias);
	DATA_FIM = data_fim();
	DATA_ENTREGA=_entrega;
	MULTA = 0;
}

Emprestimo::~Emprestimo() {
}

void Emprestimo::AdicionarMulta() {
	
	if (DATA_ENTREGA.DIA==0) {
		time_t DATA = time(nullptr);//data atual
		tm _DataAtual_;
		localtime_s(&_DataAtual_, &DATA); //data atual convertida para dd/mm/yyyy (só dá para ver os dias se converter)

		//Diferença do dia em que foi realizado o emprestimo até hoje
		int DiferencaDatas = ConverterDataDias(_DataAtual_.tm_mday, _DataAtual_.tm_mon + 1, _DataAtual_.tm_year + 1900) - ConverterDataDias(DATA_FIM.DIA, DATA_FIM.MES, DATA_FIM.ANO);

		//Se a DiferencaDataAtual for maior significa que o dia de entrega já passou
		if (DiferencaDatas > 0) {
			MULTA = DiferencaDatas + 4; // leva 5 paus pelo primeiro dia, mais 1 por cada dia que passa
			return;
		}
	}
	MULTA = 0;
}

float Emprestimo::Valor_Multa(){
	//Falta verifcar
	AdicionarMulta(); //Isto salta fora 
	return MULTA;
}

float Emprestimo::AplicarDesconto(float multa) {
	if ((get_leitor()->quem_es() == "Estudante" || get_leitor()->quem_es() == "Professor") && (get_livro()->quem_es() == "LivroCientifico" || get_livro()->quem_es() == "LivroEducativo")) {
		return 0.5 * multa;
	}
	return multa;
}

int Emprestimo::calcularDIAS(int dias) {
	if (dias == 0)
	{
		if ((Livro_Emp->quem_es() == "LivroEducativo" || Livro_Emp->quem_es() == "LivroCientifico") && (Leitor_Emp->quem_es() == "Professor" || Leitor_Emp->quem_es() == "Estudante")) {
			return 60;
		}
		return 30;
	}
	return dias;
}

DATA Emprestimo::data_fim() {
	DATA D = DATA(DATA_INICIO.DIA, DATA_INICIO.MES, DATA_INICIO.ANO);
	D.adicionar_dias(DIAS);
	return D;
}

void Emprestimo::pedir_prorrogacao(int dias) {
	if (Leitor_Emp->quem_es() == "Estudante" || Leitor_Emp->quem_es() == "Professor") {
		DATA D = DATA_INICIO;
		if (DIAS > 60) {
			cout << "Excedeu o número de dias pelos quais pode prorrogar o emprestimo!" << endl;
			return;
		}
		DIAS += dias;
		DATA_FIM = data_fim();
		cout << "Prorrogação bem sucedida!" << endl;
		return;
	}
	cout << "Não tem permissão para prorrogar o empréstimo!" << endl;
}

Livro* Emprestimo::get_livro()
{
	return Livro_Emp;
}

Leitor* Emprestimo::get_leitor()
{
	return Leitor_Emp;
}

DATA Emprestimo::get_dataInicio()
{
	return DATA_INICIO;
}

DATA Emprestimo::Alterar_dataEntrega(DATA entrega)
{
	DATA_ENTREGA.DIA = entrega.DIA;
	DATA_ENTREGA.MES = entrega.MES;
	DATA_ENTREGA.ANO = entrega.ANO;

	return DATA_ENTREGA;
}

int Emprestimo::get_dias()
{
	return DIAS;
}

void Emprestimo::Show()
{
	MULTA = Valor_Multa();

	cout << Livro_Emp->get_titulo() << '\n';
	cout << Leitor_Emp->get_nome() << '\n';
	cout << "Data: " << DATA_INICIO.DIA << "/" << DATA_INICIO.MES << "/" << DATA_INICIO.ANO << " - " << DATA_FIM.DIA << "/" << DATA_FIM.MES << "/" << DATA_FIM.ANO << '\n';
	cout << "Multa: " << MULTA << " euros" << '\n';

}
