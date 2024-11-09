#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H
#include <iostream>
#include <string>
#include <list>
#include "LivroGenerico.h"
class LivroFiccao: public LivroGenerico
{
	string SUBGENERO;
public:
	LivroFiccao(string titulo, string autor, int ano, string _ISBN, string _subgenero);
	virtual ~LivroFiccao();
	string get_subgenero();
	void Show();
	void mudarsubgenero(string new_sub);
};

#endif