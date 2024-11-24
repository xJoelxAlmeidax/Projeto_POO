#include "Emprestimo.h"
#include "Livro.h"
#include "Leitor.h"
Emprestimo::Emprestimo(DATA _inicio, Leitor* _leitor, Livro* _livro) {
	DATA_INICIO = _inicio;
	Leitor_Emp = _leitor;
	Livro_Emp = _livro;
	DIAS = calcularDIAS();
	DATA_ENTREGA = data_entrega();
}

Emprestimo::~Emprestimo() {
}

int Emprestimo::Valor_Multa(DATA dataInicio, DATA dataFim) { //Data do inicio do emprestimo e fim
	time_t DATA = time(nullptr);//data atual
	tm _DataAtual_;
	localtime_s(&_DataAtual_ ,&DATA); //data atual convertida para dd/mm/yyyy (só dá para ver os dias se converter)

	//Diferença do dia em que foi realizado o emprestimo até hoje
	int DiferencaDataAtual = abs(ConverterDataDias(dataInicio.DIA, dataInicio.MES, dataInicio.ANO) - ConverterDataDias(_DataAtual_.tm_mday, _DataAtual_.tm_mon + 1, _DataAtual_.tm_year + 1900));
	//Tempo Max em dias que pode manter o livro
	int DiferencaDataMax = abs(ConverterDataDias(dataInicio.DIA, dataInicio.MES, dataInicio.ANO) - ConverterDataDias(dataFim.DIA, dataFim.MES, dataFim.ANO));

	//Se a DiferencaDataAtual for maior significa que o dia de entrega já passou
	if (DiferencaDataAtual > DiferencaDataMax) {
		int teste = (DiferencaDataAtual - DiferencaDataMax) + 4;
		return  teste; // leva 5 paus pelo primeiro dia, mais 1 por cada dia que passa
	}
	else
	{
		return 0; // se não for maior significa que ainda tem tempo OUUU tem de entregar hoje, o menes tá de boas
	}
}

int Emprestimo::calcularDIAS() {
	if ((Livro_Emp->quem_es()=="LivroEducativo" || Livro_Emp->quem_es() == "LivroCientifico") && (Leitor_Emp->quem_es()=="Professor" || Leitor_Emp->quem_es() == "Estudante")) {
		return 60;
	}
	return 30;
}

DATA Emprestimo::data_entrega() {
	DATA D = DATA(DATA_INICIO.DIA, DATA_INICIO.MES, DATA_INICIO.ANO);
	D.adicionar_dias(DIAS);
	return D;
}

void Emprestimo::pedir_prorrogacao(int dias) {
	if (Leitor_Emp->quem_es() == "Estudante" || Leitor_Emp->quem_es() == "Professor") {
		DATA D = DATA_INICIO;
		D.adicionar_dias(60);
		if (ConverterDataDias(D.DIA, D.MES, D.ANO) < ConverterDataDias(DATA_FIM.DIA, DATA_FIM.MES, DATA_FIM.ANO)) {
			cout << "Só pode fazer uma prorrogação por empréstimo." << endl;
			return;
		}
		DATA_FIM.adicionar_dias(dias);
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

void Emprestimo::Show()
{
	DATA DATA_FIM = data_entrega();
	MULTA = Valor_Multa(DATA_INICIO, DATA_FIM);

	cout << Livro_Emp->get_titulo() << '\n';
	cout << Leitor_Emp->get_nome() << '\n';
	cout << "Data: " << DATA_INICIO.DIA << "/" << DATA_INICIO.MES << "/" << DATA_INICIO.ANO << " - " << DATA_FIM.DIA << "/" << DATA_FIM.MES << "/" << DATA_FIM.ANO << '\n';
	cout << "Multa: " << MULTA << " euros" << '\n';

}
