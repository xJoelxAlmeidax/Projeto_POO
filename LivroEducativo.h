#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H
#include <iostream>
#include <string>
#include <list>
#include "LivroGenerico.h"
class LivroEducativo: public LivroGenerico
{
	string IDADE_REC;
	string AREA;
	string ILUSTRADOR;
public:
	LivroEducativo(string titulo, string autor, int ano, string _ISBN, string _idaderec, string _area, string _ilustrador);
	virtual ~LivroEducativo();
	void Show();
};

#endif