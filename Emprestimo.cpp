#include "Emprestimo.h"
void DATA::adicionar_dias(int num_dias){

}
Emprestimo::Emprestimo(DATA _inicio,Leitor* _leitor, Livro* _livro) {
	DATA_INICIO = _inicio;
	Leitor_Emp = _leitor;
	Livro_Emp = _livro;
}

Emprestimo::~Emprestimo() {
	delete(Leitor_Emp);
	delete(Livro_Emp);
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
		return (DiferencaDataAtual - DiferencaDataMax) + 5; // leva 5 paus por dia de atraso
	}
	else
	{
		return 0; // se não for maior significa que ainda tem tempo OUUU tem de entregar hoje, o menes tá de boas
	}
}

void Emprestimo::calcularDIAS() {
	/*if (Livro_Emp.quem_es()=="LivroEducativo" || Livro_Emp.quem_es() == "LivroCientifico") && (dynamic_cast<Professor*>(Leitor_Emp) || dynamic_cast<Estudante*>(Leitor_Emp))) {

	}*/
}