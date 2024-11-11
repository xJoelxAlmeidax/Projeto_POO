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
	string get_area();
	string get_revisor();
	void mudararea(string new_area);
	void mudarrevisor(string new_revisor);
	string quem_es();
};

#endif