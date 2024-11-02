#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H
#include <iostream>
#include <string>
#include <list>
#include "LivroGenerico.h"
class LivroCientifico: public LivroGenerico
{
	string areaEstudo;
public:
	LivroCientifico(string titulo, string autor, int ano);
};

#endif