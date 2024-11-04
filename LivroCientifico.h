#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H
#include <iostream>
#include <string>
#include <list>
#include "LivroGenerico.h"
class LivroCientifico: public LivroGenerico
{
	string AREAESTUDO;
	string REVISORCIENTIFICO;
public:
	LivroCientifico(string _titulo, string _autor, int _ano, string _isbn, string _areaestudo, string _revisor);
	virtual ~LivroCientifico();
	void Show();
};

#endif