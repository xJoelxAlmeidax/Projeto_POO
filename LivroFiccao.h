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
	LivroFiccao(string titulo, string autor, int ano, string tipo, string _ISBN, string _subgenero);
	virtual ~LivroFiccao();
	void Show();

};

#endif