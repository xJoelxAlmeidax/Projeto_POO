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
	string get_area();
	string get_idade();
	string get_ilustrador();
	void Show();
	void mudaridade(string new_idade);
	void mudararea(string new_area);
	void mudarilustrador(string new_ilustrador);
	string quem_es();
};

#endif