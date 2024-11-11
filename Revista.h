#ifndef REVISTA_H
#define REVISTA_H
#include "OutrosLivros.h"
class Revista: public OutrosLivros
{
	string EDITORA;
	string FOTOGRAFO_CAPA;
public:
	Revista(string _titulo, string _autor, int _ano, string _issn, string _edicao, string _editora, string _fotografo);
	virtual ~Revista();
	string get_editora();
	string get_fotografo();
	void Show();
	void mudareditora(string new_editora);
	void mudarfotografo(string new_fotografo);
	string quem_es();
};

#endif