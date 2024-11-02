#ifndef LIVRO_H
#define LIVRO_H
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Livro
{
	string TITULO;
	string AUTOR;
	int ANO;

public:
	Livro(string titulo, string autor, int ano);
	virtual ~Livro();
	virtual void Show();
};

#endif