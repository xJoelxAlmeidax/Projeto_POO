#ifndef JORNAL_H
#define JORNAL_H
#include "OutrosLivros.h"
class Jornal: public OutrosLivros
{
	string EDITOR_CHEFE;
	string TIPO_DISTRIBUICAO; //Local, Regional ou Nacional
public:
	Jornal(string _titulo, string _autor, int _ano, string _issn, string _edicao, string _editor_boss, string _tipo_dis);
	virtual ~Jornal();
	string get_editor();
	string get_tipo();
	void Show();
	void mudareditor(string new_editor);
	void mudartipo(string new_tipo);
	string quem_es();
};

#endif