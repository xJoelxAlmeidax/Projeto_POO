#ifndef LIVROGENERICO_H
#define LIVROGENERICO_H
#include <iostream>
#include <string>
#include <list>
#include "Livro.h"
class LivroGenerico : public Livro
{
	string ISBN;
	public:
	LivroGenerico(string titulo, string autor, int ano, string _ISBN);
	virtual ~LivroGenerico();
	void Show();
};

#endif
