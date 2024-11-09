#ifndef OUTROSLIVROS_H
#define OUTROSLIVROS_H
#include "Livro.h"
class OutrosLivros : public Livro
{
	string ISSN;
	string EDICAO;
public:
	OutrosLivros(string _titulo, string _autor, int _ano, string _issn, string _edicao);
	virtual ~OutrosLivros();
	string get_issn();
	string get_edicao();
	void Show();
};

#endif