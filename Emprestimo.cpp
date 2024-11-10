#include "Emprestimo.h"

Emprestimo::Emprestimo(DATA _inicio, DATA _max, Leitor* _leitor, Livro* _livro) {
	DATA_INICIO = _inicio;
	DATA_MAX = _max;
	Leitor_Emp = _leitor;
	Livro_Emp = _livro;
}

Emprestimo::~Emprestimo() {

}

int Emprestimo::VerMulta(DATA dataInicio, DATA dataFim) { //Data do inicio do emprestimo e fim
	time_t DATA = time(nullptr);//data atual
	tm _DataAtual_;
	localtime_s(&_DataAtual_ ,&DATA); //data atual convertida para dd/mm/yyyy (só dá para ver os dias se converter)

	//Diferença do dia em que foi realizado o emprestimo até hoje
	int DiferencaDataAtual = abs(ConverterDataDias(dataInicio.dia, dataInicio.mes, dataInicio.ano) - ConverterDataDias(_DataAtual_.tm_mday, _DataAtual_.tm_mon + 1, _DataAtual_.tm_year));
	//Tempo Max em dias que pode manter o livro
	int DiferencaDataMax = abs(ConverterDataDias(dataInicio.dia, dataInicio.mes, dataInicio.ano) - ConverterDataDias(dataFim.dia, dataFim.mes, dataFim.ano));

	//Se a DiferencaDataAtual for maior significa que o dia de entrega já passou
	if (DiferencaDataAtual > DiferencaDataMax) {
		return (DiferencaDataAtual - DiferencaDataMax) * 5; // leva 5 paus por dia de atraso
	}
	else
	{
		return 0; // se não for maior significa que ainda tem tempo OUUU tem de entregar hoje, o menes tá de boas
	}
}
