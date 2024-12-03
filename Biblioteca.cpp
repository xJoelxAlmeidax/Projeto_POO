#include "Biblioteca.h"
Biblioteca::Biblioteca(string _nome) {
	NOME = _nome;
}

Biblioteca::~Biblioteca(){}

// LIVRO
Livro* Biblioteca::Add_Livros() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	string tipo_uti;
	string titulo;
	string autor;
	string in;
	int ano; 
	cout << "Título: ";
	getline(cin, titulo);
	if (titulo == "") return NULL;
	cout << "Autor: ";
	getline(cin, autor);
	cout << "Ano: ";
	cin >> in;
	while (!So_numeros(in))
	{
		cout << "Ano incorreto!!\n";
		cin >> in;
	}
	ano = stoi(in);
	cin.ignore();
	Livro* L = NULL;
	do {
		cout << "Tipo de Livro(Ficção/Cientifico/Educativo/Jornal/Revista): ";
		getline(cin, tipo_uti);
		tipo_uti = normalizarString(tipo_uti);
		if (tipo_uti == "ficcao") {
			string _ISBN;
			string _subgenero;
			do {
				cout << "ISBN: ";
				getline(cin, _ISBN);
				if (!ValidarISBN(_ISBN))
					cout << "ISBN inválido" << endl;
				else if (isbnDuplicado(_ISBN))
					cout << "Já existe um livro com esse ISBN" << endl;
				else
					break;
			} while (true);
			cout << "Subgénero: ";
			getline(cin, _subgenero);
			L = new LivroFiccao(titulo, autor, ano, _ISBN, _subgenero);
			break;
		}
		else if (tipo_uti == "cientifico") {
			string _ISBN;
			string _areaestudo;
			string _revisor;
			do {
				cout << "ISBN: ";
				getline(cin, _ISBN);
				if (!ValidarISBN(_ISBN))
					cout << "ISBN inválido" << endl;
				else if (isbnDuplicado(_ISBN))
					cout << "Já existe um livro com esse ISBN" << endl;
				else
					break;
			} while (true);
			cout << "Area Estudo: ";
			getline(cin, _areaestudo);
			cout << "Revisor Cientifico: ";
			getline(cin, _revisor);
			L = new LivroCientifico(titulo,autor,ano,_ISBN, _areaestudo,_revisor);
			break;
		}
		else if (tipo_uti == "educativo") {
			string _ISBN;
			string _idaderec;
			string _area;
			string _ilustrador;
			do {
				cout << "ISBN: ";
				getline(cin, _ISBN);
				if (!ValidarISBN(_ISBN))
					cout << "ISBN inválido" << endl;
				else if (isbnDuplicado(_ISBN))
					cout << "Já existe um livro com esse ISBN" << endl;
				else
					break;
			} while (true);
			cout << "Idade Recomendada: ";
			getline(cin, _idaderec);
			cout << "Area: ";
			getline(cin, _area);
			cout << "Ilustrador: ";
			getline(cin, _ilustrador);
			L = new LivroEducativo(titulo, autor,ano,_ISBN,_idaderec,_area,_ilustrador);
			break;
		}
		else if (tipo_uti == "jornal") {
			string _issn;
			string _edicao;
			string _editor_boss;
			string _tipo_dis;
			do {
				cout << "ISSN: ";
				getline(cin, _issn);
				if (!ValidarISSN(_issn))
					cout << "ISSN inválido" << endl;
				else if (issnDuplicado(_issn))
					cout << "Já existe um livro com esse ISSN" << endl;
				else
					break;
			} while (true);
			cout << "Edição: ";
			getline(cin, _edicao);
			cout << "Editor Chefe: ";
			getline(cin, _editor_boss);
			cout << "Distribuição geográfica (nacional/regional/local/etc.): ";
			getline(cin, _tipo_dis);
			L = new Jornal(titulo, autor, ano, _issn, _edicao, _editor_boss, _tipo_dis);
			break;
		}
		else if (tipo_uti == "revista") {
			string _issn;
			string _edicao;
			string _editora;
			string _fotografo;
			do {
				cout << "ISSN: ";
				getline(cin, _issn);
				if (!ValidarISSN(_issn))
					cout << "ISSN inválido" << endl;
				else if (issnDuplicado(_issn))
					cout << "Já existe um livro com esse ISSN" << endl;
				else
					break;
			} while (true);
			cout << "Edição: ";
			getline(cin, _edicao);
			cout << "Editora: ";
			getline(cin, _editora);
			cout << "Fotografo da Capa: ";
			getline(cin, _fotografo);
			L = new Revista(titulo, autor, ano, _issn, _edicao, _editora, _fotografo);
			break;
		}
		else {
			cout << "Não é valida! Tente novamente!" << endl;
		}

	} while (true);	
	return L;
}

bool Biblioteca::Add_Livro(Livro* L) {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	if (!L) { return false; }\
	Livros.push_back(L);
	return true;
}

void Biblioteca::AlterarLivro(Livro* L) {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	const char** opcoesAlterar = NULL;
	int numOpcoesAlterar = 0;
	int opcaoSelecionadaAlterar = 0;
	if (L->quem_es() == "Jornal") {
		static const char* opcoesAlterar_here[] = { "Titulo", "Autor", "Ano", "ISSN", "Edição", "Editor Chefe", "Tipo de Dist." };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else if (L->quem_es() == "LivroCientifico") {
		const char* opcoesAlterar_here[] = { "Titulo", "Autor", "Ano", "ISBN", "Área de Estudo", "Revisor Científico" };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else if (L->quem_es() == "LivroEducativo") {
		const char* opcoesAlterar_here[] = { "Titulo", "Autor", "Ano", "ISBN", "Idade Recomendada", "Área", "Ilustrador" };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else if (L->quem_es() == "LivroFiccao") {
		const char* opcoesAlterar_here[] = { "Titulo", "Autor", "Ano", "ISBN", "Subgenero" };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else if (L->quem_es() == "Revista") {
		const char* opcoesAlterar_here[] = { "Titulo", "Autor", "Ano", "ISSN", "Edição", "Editora", "Fotógrafo da Capa" };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else {
		cout << "ERRO" << endl;
		return;
	}


	while (true) {
		system("cls");
		cout << "                 ALTERAR DADOS DE " << L->get_titulo() << endl;
		cout << "---------------------------------------------------------------------" << endl;

		// Exibe o menu de opções para alterar dados
		for (int i = 0; i < numOpcoesAlterar; ++i) {
			if (i == opcaoSelecionadaAlterar)
				cout << " > " << opcoesAlterar[i];
			else
				cout << "   " << opcoesAlterar[i];


			if (strcmp(opcoesAlterar[i], "Titulo") == 0)
				cout << "\t\t[" << L->get_titulo() << "]";
			else if (strcmp(opcoesAlterar[i], "Autor") == 0)
				cout << "\t\t[" << L->get_autor() << "]";
			else if (strcmp(opcoesAlterar[i], "Ano") == 0)
				cout << "\t\t\t[" << L->get_ano() << "]";
			else if (strcmp(opcoesAlterar[i], "ISBN") == 0)
				cout << "\t\t\t[" << L->get_isbn() << "]";
			else if (strcmp(opcoesAlterar[i], "ISSN") == 0)
				cout << "\t\t\t[" << L->get_issn() << "]";
			else if (strcmp(opcoesAlterar[i], "Edição") == 0)
				cout << "\t\t[" << L->get_edicao() << "]";
			else if (strcmp(opcoesAlterar[i], "Editor Chefe") == 0)
				cout << "\t\t[" << L->get_editor() << "]";
			else if (strcmp(opcoesAlterar[i], "Tipo de Dist.") == 0)
				cout << "\t\t[" << L->get_tipo() << "]";
			else if (strcmp(opcoesAlterar[i], "Área de Estudo") == 0)
				cout << "\t[" << L->get_area() << "]";
			else if (strcmp(opcoesAlterar[i], "Revisor Científico") == 0)
				cout << "\t[" << L->get_revisor() << "]";
			else if (strcmp(opcoesAlterar[i], "Idade Recomendada") == 0)
				cout << "\t[" << L->get_idade() << "]";
			else if (strcmp(opcoesAlterar[i], "Área") == 0)
				cout << "\t\t\t[" << L->get_area() << "]";
			else if (strcmp(opcoesAlterar[i], "Ilustrador") == 0)
				cout << "\t\t[" << L->get_ilustrador() << "]";
			else if (strcmp(opcoesAlterar[i], "Subgenero") == 0)
				cout << "\t\t[" << L->get_subgenero() << "]";
			else if (strcmp(opcoesAlterar[i], "Editora") == 0)
				cout << "\t\t[" << L->get_editora() << "]";
			else if (strcmp(opcoesAlterar[i], "Fotógrafo da Capa") == 0)
				cout << "\t[" << L->get_fotografo() << "]";

			cout << endl;
		}

		int tecla = _getch();

		if (tecla == 224) {
			tecla = _getch();
			if (tecla == 72) { // Seta para cima
				opcaoSelecionadaAlterar = (opcaoSelecionadaAlterar - 1 + numOpcoesAlterar) % numOpcoesAlterar;
			}
			else if (tecla == 80) { // Seta para baixo
				opcaoSelecionadaAlterar = (opcaoSelecionadaAlterar + 1) % numOpcoesAlterar;
			}
		}
		else if (tecla == 13) {
			string buffer;
			int buffer1;
			if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Titulo") == 0) {
				cout << "Titulo:";
				getline(cin, buffer);
				L->mudartitulo(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Autor") == 0) {
				cout << "Autor:";
				getline(cin, buffer);
				L->mudarautor(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Ano") == 0) {
				cout << "Ano:";
				cin >> buffer1;
				cin.ignore();
				L->mudarano(buffer1);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "ISBN") == 0) {
				cout << "ISBN:";
				getline(cin, buffer);
				L->mudarISBN(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "ISSN") == 0) {
				cout << "ISSN:";
				getline(cin, buffer);
				L->mudarISSN(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Edição") == 0) {
				cout << "Edição:";
				getline(cin, buffer);
				L->mudaredicao(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Editor Chefe") == 0) {
				cout << "Editor Chefe:";
				getline(cin, buffer);
				L->mudareditor(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Tipo de Dist.") == 0) {
				cout << "Tipo de Distribuição:";
				getline(cin, buffer);
				L->mudartipo(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Área de Estudo") == 0) {
				cout << "Área de Estudo:";
				getline(cin, buffer);
				L->mudararea(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Revisor Científico") == 0) {
				cout << "Revisor Científico:";
				getline(cin, buffer);
				L->mudarrevisor(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Idade Recomendada") == 0) {
				cout << "Idade Recomendada:";
				getline(cin, buffer);
				L->mudaridade(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Área") == 0) {
				cout << "Área:";
				getline(cin, buffer);
				L->mudararea(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Ilustrador") == 0) {
				cout << "Ilustrador:";
				getline(cin, buffer);
				L->mudarilustrador(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Subgenero") == 0) {
				cout << "Subgenero:";
				getline(cin, buffer);
				L->mudarsubgenero(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Editora") == 0) {
				cout << "Editora:";
				getline(cin, buffer);
				L->mudareditora(buffer);
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Fotógrafo da Capa") == 0) {
				cout << "Fotógrafo da Capa:";
				getline(cin, buffer);
				L->mudarfotografo(buffer);
			}
			cout << "Alteração bem-sucedida!" << endl;
			system("pause");
		}
		else if (tecla == 27) {
			break;
		}
	}


}

void Biblioteca::RemoverLivro(Livro* L) {


	// ver esta parte da erro quando se quer apagar o ultimo do emprestimo, leitor, etc

	for (auto it = Emprestimos.begin(); it != Emprestimos.end();) {

		if ((*it)->get_livro()->get_isbn() != "" && L->get_isbn() != "" && (*it)->get_livro()->get_isbn() == L->get_isbn() || (*it)->get_livro()->get_issn() != "" && L->get_issn() != "" && (*it)->get_livro()->get_issn() == L->get_issn())
		{
			it = Emprestimos.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (Leitor* leitor : Leitores)
	{
		list <Emprestimo*> Emp_Hist = leitor->get_Emp();
		if (!Emp_Hist.empty()) {
			for (auto it_hist = Emp_Hist.begin(); it_hist != Emp_Hist.end();) {

				if ((*it_hist)->get_livro()->get_isbn() != "" && L->get_isbn() != "" && (*it_hist)->get_livro()->get_isbn() == L->get_isbn() || (*it_hist)->get_livro()->get_issn() != "" && L->get_issn() != "" && (*it_hist)->get_livro()->get_issn() == L->get_issn())
				{
					it_hist = Emp_Hist.erase(it_hist);
				}
				else
				{
					++it_hist;
				}
			}
		}
	}

	Livros.remove(L);
	delete(L);
}

bool Biblioteca::isbnDuplicado(const string& ISBN) {
	for (const auto livro : Livros) {
		if (livro->get_isbn() == ISBN) {
			return true;
		}
	}
	return false;
}

bool Biblioteca::issnDuplicado(const string& ISSN) {
	for (const auto livro : Livros) {
		if (livro->get_issn() == ISSN) {
			return true;
		}
	}
	return false;
}



// LEITOR
Leitor* Biblioteca::Add_Leitores() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	string ncc;
	string nome;
	string morada;
	string telefone;
	int idade;
	cout << "Nome: ";
	getline(cin, nome);
	if (nome=="") return NULL;


	while (true) {
		cout << "Número de Cartão de Cidadão: ";
		getline(cin, ncc);

		if (!validarNCC(ncc)) {
			cout << "Número de Cartão de Cidadão Inválido" << endl;
		}
		else {
			if (nccDuplicado(ncc))
			{
				cout << "Número de Cartão de Cidadão já existente" << endl;
			}
			else
			{
				break;
			}
		}
	}

	cout << "Morada: ";
	getline(cin, morada);
	cout << "Idade: ";
	cin >> idade;
	cin.ignore();

	while (true) {
		cout << "Telefone: ";
		getline(cin, telefone);

		if (!validarTelefone(telefone)) {
			cout << "Formato do Telefone inválido! Tente novamente." << endl;
		}
		else {
			break;
		}
	}

	Leitor* L = NULL;
	do {
		string tipo_leitor;
		string email;
		cout << "Tipo de Leitor(Estudante/Professor/Externo): ";		
		getline(cin, tipo_leitor);
		tipo_leitor = normalizarString(tipo_leitor);
		if (tipo_leitor == "externo") {
			if (idade >= 69)
			{
				string _necessidadesAcessibilidade;
				cout << "Necessidades de Acessibilidade: ";
				getline(cin, _necessidadesAcessibilidade);
				L = new Senior(ncc, nome, morada, telefone, idade, _necessidadesAcessibilidade);
				break;
			}
			else
			{
				while (true)
				{
					cout << "Email: ";
					getline(cin, email);

					if (!validarEmail(email)) {
						cout << "Email inválido! Tente novamente." << endl;
					}
					else {
						break;
					}
				}
				L = new LeitorComum(ncc, nome, morada, telefone, idade, email);
			}
			break;
		}
		else if (tipo_leitor == "estudante") {
			while (true)
			{
				cout << "Email: ";
				getline(cin, email);

				if (!validarEmail(email)) {
					cout << "Email inválido! Tente novamente." << endl;
				}
				else {
					break;
				}
			}
			string _Curso;
			cout << "Curso: ";
			getline(cin, _Curso);
			L = new Estudante(ncc,nome,morada,telefone, idade, email, _Curso);
			break;
		}
		else if (tipo_leitor == "professor") {
			while (true)
			{
				cout << "Email: ";
				getline(cin, email);

				if (!validarEmail(email)) {
					cout << "Email inválido! Tente novamente." << endl;
				}
				else {
					break;
				}
			}
			string _Departamento;
			cout << "Departamento: ";
			getline(cin, _Departamento);
			L = new Professor(ncc, nome, morada, telefone, idade, email,_Departamento);
			break;
		}
		else {
			cout << "Não é valida! Tente novamente!" << endl;
		}

	} while (true);

	return L;
}

bool Biblioteca::Add_Leitor(Leitor* P) {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	if (!P) { return false; }
	Leitores.push_back(P);
	return true;
}

void Biblioteca::AlterarLeitor(Leitor* L) {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	const char** opcoesAlterar = NULL;
	int numOpcoesAlterar = 0;
	int opcaoSelecionadaAlterar = 0;
	if (L->quem_es() == "LeitorComum") {
		static const char* opcoesAlterar_here[] = { "Nome", "Num. CC", "Morada", "Telefone", "Idade", "Email" };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else if (L->quem_es() == "Estudante") {
		const char* opcoesAlterar_here[] = { "Nome", "Num. CC", "Morada", "Telefone", "Idade", "Email", "Curso" };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else if (L->quem_es() == "Professor") {
		const char* opcoesAlterar_here[] = { "Nome", "Num. CC", "Morada", "Telefone", "Idade", "Email", "Departamento" };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else if (L->quem_es() == "Senior") {
		const char* opcoesAlterar_here[] = { "Nome", "Num. CC", "Morada", "Telefone", "Idade", "Necessidades" };
		opcoesAlterar = opcoesAlterar_here;
		numOpcoesAlterar = sizeof(opcoesAlterar_here) / sizeof(opcoesAlterar_here[0]);
		opcaoSelecionadaAlterar = 0;
	}
	else {
		cout << "ERRO" << endl;
		return;
	}


	while (true) {
		system("cls");
		cout << "                 ALTERAR DADOS DE " << L->get_nome() << endl;
		cout << "---------------------------------------------------------------------" << endl;

		// Exibe o menu de opções para alterar dados
		for (int i = 0; i < numOpcoesAlterar; ++i) {
			if (i == opcaoSelecionadaAlterar)
				cout << " > " << opcoesAlterar[i];
			else
				cout << "   " << opcoesAlterar[i];


			if (strcmp(opcoesAlterar[i], "Nome") == 0)
				cout << "\t\t\t[" << L->get_nome() << "]";
			else if (strcmp(opcoesAlterar[i], "Num. CC") == 0)
				cout << "\t\t[" << L->get_ncc() << "]";
			else if (strcmp(opcoesAlterar[i], "Morada") == 0)
				cout << "\t\t[" << L->get_morada() << "]";
			else if (strcmp(opcoesAlterar[i], "Telefone") == 0)
				cout << "\t\t[" << L->get_telefone() << "]";
			else if (strcmp(opcoesAlterar[i], "Idade") == 0)
				cout << "\t\t[" << L->get_idade() << "]";
			else if (strcmp(opcoesAlterar[i], "Email") == 0)
				cout << "\t\t[" << L->get_Email() << "]";
			else if (strcmp(opcoesAlterar[i], "Curso") == 0 && L->quem_es() == "Estudante")
				cout << "\t\t[" << L->get_curso() << "]";
			else if (strcmp(opcoesAlterar[i], "Departamento") == 0 && L->quem_es() == "Professor")
				cout << "\t\t[" << L->get_Departamento() << "]";
			else if (strcmp(opcoesAlterar[i], "Necessidades") == 0 && L->quem_es() == "Senior")
				cout << "\t\t[" << L->get_NecessidadesAcessibilidade() << "]";

			cout << endl;
		}

		int tecla = _getch();

		if (tecla == 224) {
			tecla = _getch();
			if (tecla == 72) { // Seta para cima
				opcaoSelecionadaAlterar = (opcaoSelecionadaAlterar - 1 + numOpcoesAlterar) % numOpcoesAlterar;
			}
			else if (tecla == 80) { // Seta para baixo
				opcaoSelecionadaAlterar = (opcaoSelecionadaAlterar + 1) % numOpcoesAlterar;
			}
		}
		else if (tecla == 13) {
			string buffer;
			int buffer1;
			bool AlteracaoSucesso = false;

			if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Nome") == 0) {
				cout << "Nome: ";
				getline(cin, buffer);
				L->mudarnome(buffer);
				AlteracaoSucesso = true;
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Num. CC") == 0) {
				cout << "Número do CC: ";
				getline(cin, buffer);
				if (validarNCC(buffer))
				{
					L->mudarncc(buffer);
					AlteracaoSucesso = true;
				}
				else
				{
					cout << "Número de CC inválido" << endl;
					Sleep(1500);
				}
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Morada") == 0) {
				cout << "Morada: ";
				getline(cin, buffer);
				L->mudarmorada(buffer);
				AlteracaoSucesso = true;
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Telefone") == 0) {
				cout << "Telefone:";
				getline(cin, buffer);
				if (validarTelefone(buffer))
				{
					L->mudartelefone(buffer);
					AlteracaoSucesso = true;
				}
				else
				{
					cout << "Telefone inválido! Tente novamente." << endl;
					Sleep(1500);
				}
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Idade") == 0) {
				cout << "Idade:";
				cin >> buffer1;
				cin.ignore();
				L->mudaridade(buffer1);
				AlteracaoSucesso = true;
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Email") == 0) {
				cout << "Email:";
				getline(cin, buffer);
				if (validarEmail(buffer))
				{
					L->mudaremail(buffer);
					AlteracaoSucesso = true;
				}
				else
				{
					cout << "Email inválido! Tente novamente." << endl;
					Sleep(1500);
				}
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Curso") == 0 && L->quem_es() == "Estudante") {
				cout << "Curso:";
				getline(cin, buffer);
				L->mudarcurso(buffer);
				AlteracaoSucesso = true;
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Departamento") == 0 && L->quem_es() == "Professor") {
				cout << "Departamento:";
				getline(cin, buffer);
				L->mudarDepartamento(buffer);
				AlteracaoSucesso = true;
			}
			else if (strcmp(opcoesAlterar[opcaoSelecionadaAlterar], "Necessidades") == 0 && L->quem_es() == "Senior") {
				cout << "Necessidades:";
				getline(cin, buffer);
				L->mudarNecessidades(buffer);
				AlteracaoSucesso = true;
			}
			if (AlteracaoSucesso)
			{
				cout << "Alteração bem-sucedida!" << endl;
				system("pause");
			}

		}
		else if (tecla == 27) {
			break;
		}
	}
}

void Biblioteca::RemoverLeitor(Leitor* P) {

	for (auto it = Emprestimos.begin(); it != Emprestimos.end();) {

		if ((*it)->get_leitor()->get_ncc() != "" && P->get_ncc() != "" && (*it)->get_leitor()->get_ncc() == P->get_ncc())
		{
			it = Emprestimos.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (Livro* livro : Livros)
	{
		list <Leitor*> reserva = livro->get_leitores();
		for (auto it_reserva = reserva.begin(); it_reserva != reserva.end();)
		{
			if ((*it_reserva)->get_ncc() != "" && P->get_ncc() != "" && (*it_reserva)->get_ncc() == P->get_ncc())
			{
				it_reserva = reserva.erase(it_reserva);
			}
			else
			{
				++it_reserva;
			}
		}
	}

	Leitores.remove(P);
	delete(P);
}

bool Biblioteca::nccDuplicado(const string& ncc) {
	for (const auto leitor : Leitores) {
		if (leitor->get_ncc() == ncc) {
			return true;
		}
	}
	return false;
}



//EMPRESTIMO
Emprestimo* Biblioteca::Add_Emprestimos() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;

	DATA DATAINICIO;
	DATA ENTREGA;
	ENTREGA.DIA = 0;
	ENTREGA.MES = 0;
	ENTREGA.ANO = 0;
	Livro* B = ResultadoPesquisa();
	Leitor* A = ResultadoPesquisaP();
	if (B && A) {
		Emprestimo* E = new Emprestimo(DATAINICIO, A, B, 0, ENTREGA);
		return E;
	}
	return NULL;
}

bool Biblioteca::Add_Emprestimo_Reserva(Emprestimo* E) {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;

	if (!E) { return false; }
	else if (Emprestimos.empty()) { Emprestimos.push_back(E); return true; }

	bool encontrado = false;

	for (Emprestimo* emprestimo : Emprestimos)
	{
		if (emprestimo->get_livro()->get_isbn() != "" && E->get_livro()->get_isbn() != "" && emprestimo->get_livro()->get_isbn() == E->get_livro()->get_isbn() || emprestimo->get_livro()->get_issn() != "" && E->get_livro()->get_issn() != "" && emprestimo->get_livro()->get_issn() == E->get_livro()->get_issn())
		{
			encontrado = true;
			break;
		}
	}


	if (encontrado == true)
	{
		E->get_livro()->AddReserva(E->get_leitor());
		delete(E);
	}
	else
	{
		Emprestimos.push_back(E);
	}

	return true;
}

void Biblioteca::EntregarLivro(Emprestimo* E) {
	if (!E) { return; }
	string opc;

	float multa = E->Valor_Multa();
	if (multa != 0)
	{
		cout << "Tem uma multa de " << multa << " euros" << endl;
		if (multa != E->AplicarDesconto(multa)) {
			cout << "BENEFICIO DE ESTUDANTE/PROFESSOR: 50% OFF" << endl;
			cout << "Valor de multa a pagar: " << E->AplicarDesconto(multa) << endl;
		}
		cout << "Pagar Multa(S/N)" << endl;
		cin >> opc;

		if (opc == "N")
		{
			return;
		}
	}

	for (Leitor* LeitorAddHist : Leitores)
	{
		if (LeitorAddHist->get_ncc() == E->get_leitor()->get_ncc())
		{
			DATA dataEntrega;
			E->Alterar_dataEntrega(dataEntrega);

			LeitorAddHist->AddHistEmprestimo(E);
			break;
		}
	}


	list <Leitor*> reserva = E->get_livro()->get_leitores();

	if (!reserva.empty())
	{
		for (Leitor* reservaNovoEmp : reserva)
		{
			DATA DATAINICIO;
			DATA ENTREGA;
			ENTREGA.DIA = 0;
			ENTREGA.MES = 0;
			ENTREGA.ANO = 0;
			Emprestimo* E_NovoEmp = new Emprestimo(DATAINICIO, reservaNovoEmp, E->get_livro(), 0, ENTREGA);
			Emprestimos.remove(E);
			delete(E);
			Add_Emprestimo_Reserva(E_NovoEmp);
			break;
		}
	}
}

void Biblioteca::Prorrogacao() {
	int dias = 0;

	cout << "Dias: ";
	cin >> dias;
	cin.ignore();

	Emprestimo* E = Pesquisar_E();
	if(E)
		E->pedir_prorrogacao(dias);
}

void Biblioteca::MostrarEmprestimo() {
	Emprestimo* E = Pesquisar_E();
	if(E)
		E->Show();
}

void Biblioteca::MultasPendentes() {
	for (const auto emprestimoTeste : Emprestimos) {
		int valorMulta = emprestimoTeste->Valor_Multa();
		if (valorMulta != 0)
		{
			cout << emprestimoTeste->get_leitor()->get_nome() << '\t' << valorMulta << " euros" << endl;
		}
	}
}

void Biblioteca::Ver_HistoricoPessoa()
{
	Leitor* P = ResultadoPesquisaP();
	if(P)
		P->Mostrar_HistEmprestimo();
}


//RESERVAS
void Biblioteca::Ver_Reservas()
{
	Livro* L = ResultadoPesquisa();
	if(L)
		L->Mostrar_Reserva();
}


//LER E GUARDAR NO FICHEIRO
bool Biblioteca::load_file(string nf) {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;

	ifstream File(nf);
	if (!File) {
		return false;
	}

	string buffer1, buffer2, buffer3, buffer4, buffer5, buffer6, buffer7, buffer8;
	
	while(getline(File,buffer1,'\t'))
	{
		Livro* L = NULL;
		Leitor* P = NULL;
		Emprestimo* E = NULL;
		Leitor* R = NULL;
		Leitor* P_EMP = NULL;


		getline(File, buffer2, '\t');
		getline(File, buffer3, '\t');
		getline(File, buffer4, '\t');

		if (buffer1 == "LeitorComum") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7);
			P = new LeitorComum(buffer2, buffer3, buffer4, buffer5, stoi(buffer6), buffer7);
		}
		else if (buffer1 == "Professor") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7, '\t');
			getline(File, buffer8);
			P = new Professor(buffer2, buffer3, buffer4, buffer5, stoi(buffer6), buffer7, buffer8);
		}
		else if (buffer1 == "Senior") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7);
			P = new Senior(buffer2, buffer3, buffer4, buffer5, stoi(buffer6), buffer7);
		}
		else if (buffer1 == "Estudante") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7, '\t');
			getline(File, buffer8);
			P = new Estudante(buffer2, buffer3, buffer4, buffer5, stoi(buffer6), buffer7, buffer8);
		}
		else if (buffer1 == "LivroCientifico") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7);
			L = new LivroCientifico(buffer2, buffer3, stoi(buffer4), buffer5, buffer6, buffer7);
		}
		else if (buffer1 == "LivroEducativo") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7, '\t');
			getline(File, buffer8);
			L = new LivroEducativo(buffer2, buffer3, stoi(buffer4), buffer5, buffer6, buffer7, buffer8);
		}
		else if (buffer1 == "LivroFiccao") {
			getline(File, buffer5, '\t');
			getline(File, buffer6);
			L = new LivroFiccao(buffer2, buffer3, stoi(buffer4), buffer5,buffer6);
		}
		else if (buffer1 == "Revista") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7, '\t');
			getline(File, buffer8);
			L = new Revista(buffer2, buffer3, stoi(buffer4), buffer5, buffer6, buffer7, buffer8);
		}
		else if (buffer1 == "Jornal"){
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7, '\t');
			getline(File, buffer8);
			L = new Jornal(buffer2, buffer3, stoi(buffer4), buffer5, buffer6, buffer7, buffer8);
		}
		else if (buffer1 == "Emprestimo" || buffer1 == "Historico") {
			DATA data;
			DATA entrega;
			entrega.DIA = 0;
			entrega.MES = 0;
			entrega.ANO = 0;
			Livro* L_EMP = NULL;
			bool leitor = false, livro = false;

			data.DIA = stoi(buffer2);
			data.MES = stoi(buffer3);
			data.ANO = stoi(buffer4);

			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7);

			for (auto leitorLoad : Leitores)
			{
				if (leitorLoad->get_ncc() == buffer5)
				{
					P_EMP = leitorLoad;
					leitor = true;
					break;
				}
			}

			for (auto livroLoad : Livros)
			{
				if (livroLoad->get_isbn() == buffer6 || livroLoad->get_issn() == buffer6)
				{
					L_EMP = livroLoad;
					livro = true;
					break;
				}

			}
			if (livro == true && leitor == true)
				E = new Emprestimo(data, P_EMP, L_EMP,stoi(buffer7),entrega);
		}
		if (L != NULL)
		{
			Add_Livro(L);
		}
		if (P != NULL)
		{
			Add_Leitor(P);
		}
		if (E != NULL)
		{
			if (buffer1 == "Emprestimo")
				Add_Emprestimo_Reserva(E);
			else
				P_EMP->AddHistEmprestimo(E);
		}
	}

	// Limpa e posiciona para o inicio do ficheiro
	File.clear();    
	File.seekg(0);

	while (getline(File, buffer1, '\t'))
	{
		getline(File, buffer2, '\t');
		getline(File, buffer3);

		if (buffer1 == "Reserva") {

			Leitor* P_R = NULL;
			bool R_leitor = false;

			
			for (auto leitorLoad : Leitores)
			{
				if (leitorLoad->get_ncc() == buffer3)
				{
					R_leitor = true;
					P_R = leitorLoad;		
					break;
				}
					
			}

			for (auto livroLoad : Livros)
			{
				if (livroLoad->get_isbn() == buffer2 || livroLoad->get_issn() == buffer2)
				{
					if (R_leitor == true)
					{
						livroLoad->AddReserva(P_R);
					}
					break;
				}
			}
		}
	}
	File.close();
	return true;
}

bool Biblioteca::save_file(string nf) {
	ofstream File(nf);

	if (!File)
	{
		return false;
	}

	for (auto livroSave : Livros)
	{
		if (livroSave->quem_es() == "LivroCientifico") {
			File << "LivroCientifico\t";
			File << livroSave->get_titulo() << "\t";
			File << livroSave->get_autor() << "\t";
			File << livroSave->get_ano() << "\t";
			File << livroSave->get_isbn() << "\t";
			File << livroSave->get_area() << "\t";
			File << livroSave->get_revisor() << "\n";
		}
		else if (livroSave->quem_es() == "LivroEducativo") {
			File << "LivroEducativo\t";
			File << livroSave->get_titulo() << "\t";
			File << livroSave->get_autor() << "\t";
			File << livroSave->get_ano() << "\t";
			File << livroSave->get_isbn() << "\t";
			File << livroSave->get_idade() << "\t";
			File << livroSave->get_area() << "\t";
			File << livroSave->get_ilustrador() << "\n";
		}
		else if (livroSave->quem_es() == "LivroFiccao") {
			File << "LivroFiccao\t";
			File << livroSave->get_titulo() << "\t";
			File << livroSave->get_autor() << "\t";
			File << livroSave->get_ano() << "\t";
			File << livroSave->get_isbn() << "\t";
			File << livroSave->get_subgenero() << "\n";

		}
		else if (livroSave->quem_es() == "Revista")
		{
			File << "Revista\t";
			File << livroSave->get_titulo() << "\t";
			File << livroSave->get_autor() << "\t";
			File << livroSave->get_ano() << "\t";
			File << livroSave->get_issn() << "\t";
			File << livroSave->get_edicao() << "\t";
			File << livroSave->get_editora() << "\t";
			File << livroSave->get_fotografo() << "\n";
		}
		else if (livroSave->quem_es() == "Jornal")
		{
			File << "Jornal\t";
			File << livroSave->get_titulo() << "\t";
			File << livroSave->get_autor() << "\t";
			File << livroSave->get_ano() << "\t";
			File << livroSave->get_issn() << "\t";
			File << livroSave->get_edicao() << "\t";
			File << livroSave->get_editor() << "\t";
			File << livroSave->get_tipo() << "\n";
		}
	}

	for (auto leitorSave : Leitores)
	{
		if (leitorSave->quem_es()=="LeitorComum") {
			File << "LeitorComum\t";
			File << leitorSave->get_ncc() << "\t";
			File << leitorSave->get_nome() << "\t";
			File << leitorSave->get_morada() << "\t";
			File << leitorSave->get_telefone() << "\t";
			File << leitorSave->get_idade() << "\t";
			File << leitorSave->get_Email() << "\n";
		}
		else if (leitorSave->quem_es() == "Senior") {
			File << "Senior\t";
			File << leitorSave->get_ncc() << "\t";
			File << leitorSave->get_nome() << "\t";
			File << leitorSave->get_morada() << "\t";
			File << leitorSave->get_telefone() << "\t";
			File << leitorSave->get_idade() << "\t";
			File << leitorSave->get_NecessidadesAcessibilidade() << "\n";
		}
		else if (leitorSave->quem_es() == "Professor") {
			File << "Professor\t";
			File << leitorSave->get_ncc() << "\t";
			File << leitorSave->get_nome() << "\t";
			File << leitorSave->get_morada() << "\t";
			File << leitorSave->get_telefone() << "\t";
			File << leitorSave->get_idade() << "\t";
			File << leitorSave->get_Email() << "\t";
			File << leitorSave->get_Departamento() << "\n";

		}
		else if (leitorSave->quem_es() == "Estudante")
		{
			File << "Estudante\t";
			File << leitorSave->get_ncc() << "\t";
			File << leitorSave->get_nome() << "\t";
			File << leitorSave->get_morada() << "\t";
			File << leitorSave->get_telefone() << "\t";
			File << leitorSave->get_idade() << "\t";
			File << leitorSave->get_Email() << "\t";
			File << leitorSave->get_curso() << "\n";
		}

		list <Emprestimo*> Emp_Hist = leitorSave->get_Emp();
		if(!Emp_Hist.empty()){
			for (auto Emp_HistSave : Emp_Hist)
			{
				File << "Historico\t";
				File << Emp_HistSave->get_dataInicio().DIA << "\t";
				File << Emp_HistSave->get_dataInicio().MES << "\t";
				File << Emp_HistSave->get_dataInicio().ANO << "\t";
				File << Emp_HistSave->get_leitor()->get_ncc() << "\t";
				if (Emp_HistSave->get_livro()->get_isbn() != "")
					File << Emp_HistSave->get_livro()->get_isbn() << "\t";
				else
					File << Emp_HistSave->get_livro()->get_issn() << "\t";
				File << Emp_HistSave->get_dias() << "\n";

				// guardar data entrega
			}
		}
	}

	for (auto emprestimoSave : Emprestimos)
	{
		File << "Emprestimo\t";
		File << emprestimoSave->get_dataInicio().DIA << "\t";
		File << emprestimoSave->get_dataInicio().MES << "\t";
		File << emprestimoSave->get_dataInicio().ANO << "\t";
		File << emprestimoSave->get_leitor()->get_ncc() << "\t";
		if ((emprestimoSave->get_livro())->quem_es() == "LivroEducativo" || (emprestimoSave->get_livro())->quem_es() == "LivroCientifico" || (emprestimoSave->get_livro())->quem_es() == "LivroFiccao")
		{
			File << emprestimoSave->get_livro()->get_isbn() << "\t";
		}
		else
		{
			File << emprestimoSave->get_livro()->get_issn() << "\t";
		}
		File << emprestimoSave->get_dias() << "\n";
		
		
	}

	for (auto livroReserva : Livros)
	{

		list <Leitor*> LeitorReserva = livroReserva->get_leitores();

		for (auto leitorReservaSave : LeitorReserva)
		{
			File << "Reserva\t";
			if (livroReserva->get_isbn() != "")
				File << livroReserva->get_isbn() << "\t";
			else
				File << livroReserva->get_issn() << "\t";
			File << leitorReservaSave->get_ncc() << "\n";
		}
	}

	File.close();
	return true;
}



// PESQUISA / LISTAGEM
void Biblioteca::RelatorioCategorias() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	cout << "LIVROS" << endl;
	cout << "------------------------------------------" << endl;
	cout << "            LIVROS CIENTIFICOS" << endl;
	cout << "------------------------------------------" << endl;
	listagemL("LivroCientifico");
	cout << "------------------------------------------" << endl;
	cout << "             LIVROS DE FICÇÃO" << endl;
	cout << "------------------------------------------" << endl;
	listagemL("LivroFiccao");
	cout << "------------------------------------------" << endl;
	cout << "            LIVROS EDUCATIVOS" << endl;
	cout << "------------------------------------------" << endl;
	listagemL("LivroEducativo");
	cout << "------------------------------------------" << endl;
	cout << "                REVISTAS" << endl;
	cout << "------------------------------------------" << endl;
	listagemL("Revista");
	cout << "------------------------------------------" << endl;
	cout << "                JORNAIS" << endl;
	cout << "------------------------------------------" << endl;
	listagemL("Jornal");
}

void Biblioteca::RelatorioLeitores() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	cout << "LIVROS" << endl;
	cout << "------------------------------------------" << endl;
	cout << "            Leitores Comuns" << endl;
	cout << "------------------------------------------" << endl;
	listagemP("LeitorComum");
	cout << "------------------------------------------" << endl;
	cout << "             Professores" << endl;
	cout << "------------------------------------------" << endl;
	listagemP("Professor");
	cout << "------------------------------------------" << endl;
	cout << "            Estudantes" << endl;
	cout << "------------------------------------------" << endl;
	listagemP("Estudante");
	cout << "------------------------------------------" << endl;
	cout << "                Seniores" << endl;
	cout << "------------------------------------------" << endl;
	listagemP("Senior");

}

Livro* Biblioteca::Pesquisar_L(const list<Livro*>& livros, int abaSelecionada, const char* tabs[], int num_tabs) {
	string entrada;
	list<Livro*> filtrados;
	list<Livro*>::iterator selecao = filtrados.end(); // Inicializa seleção como vazia
	int contador = 0;
	while (true) {
		// Armazena o índice atual da seleção, se houver uma seleção válida
		int indiceSelecionado = -1;
		if (selecao != filtrados.end()) {
			indiceSelecionado = distance(filtrados.begin(), selecao);
		}

		// Limpa a lista de filtrados antes de reprocessar
		filtrados.clear();

		// Filtra os livros com base na aba selecionada e na entrada do usuário
		for (Livro* livro : livros) {
			bool correspondeCategoria = false;
			switch (abaSelecionada) {
			case 0: correspondeCategoria = true; break; // Biblioteca inteira
			case 1: {
				if (livro->quem_es() == "LivroFiccao") {
					correspondeCategoria = true; 
				}
				break;
			}
			case 2: {
				if (livro->quem_es() == "LivroCientifico") {
					correspondeCategoria = true;
				}
				break;
			}
			case 3: {
				if (livro->quem_es() == "LivroEducativo") {
					correspondeCategoria = true;
				}
				break;
			}
			case 4: {
				if (livro->quem_es() == "Revista") {
					correspondeCategoria = true;
				}
				break;
			}
			case 5: {
				if (livro->quem_es() == "Jornal") {
					correspondeCategoria = true;
				}
				break;
			}
			}
			if (correspondeCategoria && (livro->get_titulonormalizado().find(normalizarString(entrada)) != string::npos || livro->get_isbn().find(entrada) != string:: npos || livro->get_issn().find(entrada) != string::npos)) {
				filtrados.push_back(livro);
			}
		}

		// Atualiza a seleção com base no índice armazenado
		if (!filtrados.empty()) {
			if (indiceSelecionado >= 0 && indiceSelecionado < filtrados.size()) {
				selecao = next(filtrados.begin(), indiceSelecionado);
			}
			else {
				selecao = filtrados.begin();  // Se índice não é válido, começa do primeiro livro
			}
		}
		else {
			selecao = filtrados.end();  // Sem seleção válida se `filtrados` estiver vazio
		}

		// Exibe o menu e os livros filtrados com a seleção destacada
		system("CLS");
		mostrarMenuTabs(abaSelecionada, tabs, num_tabs);
		cout << "Pesquisa: " << entrada << endl;
		cout << "-------------------------------------------------" << endl;
		int count = 0;
		for (auto it = filtrados.begin(); it != filtrados.end() && count<=20; ++it, count++) {
			if (it == selecao) cout << " > "; else cout << "   ";
			cout << (*it)->get_titulo();
			if ((*it)->quem_es() == "LivroCientifico" || (*it)->quem_es() == "LivroFiccao" || (*it)->quem_es() == "LivroEducativo") {
				cout << "\t[" << (*it)->get_isbn() << "]" << endl;
			}
			else {
				cout << "\t[" << (*it)->get_issn() << "]" << endl;
			}
		}
		cout << "-------------------------------------------------" << endl;
		// Captura a tecla pressionada para navegação ou seleção
		int tecla = _getch();
		if (tecla == 224) {  // Tecla especial (setas)
			int direcao = _getch();
			if (!filtrados.empty()) {
				switch (direcao) {
				case 72:  // Seta para cima
					if (selecao != filtrados.begin()) {
						--selecao;
						--contador;
					}
					break;
				case 80:  // Seta para baixo
					if (next(selecao) != filtrados.end() && contador<20) {
						++selecao;
						++contador;
					}
					break;
				}
			}
		}
		else if (tecla == 27) { // ESC
			return NULL; // Retorna nullptr para indicar cancelamento
		}
		else if (tecla == '\r') {  // Enter para selecionar o livro
			return (selecao != filtrados.end()) ? *selecao : nullptr;
		}
		else if (tecla == 8 && !entrada.empty()) {  // Backspace para apagar caracteres da pesquisa
			entrada.pop_back();
		}
		else if (isprint(tecla)) {  // Caractere imprimível (adiciona à pesquisa)
			entrada += static_cast<char>(tecla);
		}
	}
}

Livro* Biblioteca::ResultadoPesquisa() {
	const char* tabs_p[] = { "BIBLIOTECA", "Ficção", "Científico", "Educativo", "Revistas", "Jornais" };
	int abaSelecionada_p = 0;

	system("CLS");
	cout << "Pesquisar Livro\n";

	while (true) {
		// Limpa a tela apenas uma vez antes de mostrar o menu
		system("CLS");

		// Exibe o menu de abas
		mostrarMenuTabs(abaSelecionada_p, tabs_p, 6);
		cout << "Pressione a seta para mudar de aba, Enter para pesquisar\n";

		// Espera pela tecla pressionada para navegar entre as abas
		int tecla = _getch();

		if (tecla == 224) { // Tecla especial (setas)
			switch (_getch()) {
			case 75: // Seta esquerda
				abaSelecionada_p = (abaSelecionada_p > 0) ? abaSelecionada_p - 1 : 5;
				break;
			case 77: // Seta direita
				abaSelecionada_p = (abaSelecionada_p < 5) ? abaSelecionada_p + 1 : 0;
				break;
			}
		}
		else if (tecla == 27) { // ESC
			return NULL; // Retorna nullptr para indicar cancelamento
		}
		else if (tecla == '\r') { // Enter para iniciar a pesquisa
			// Inicia a pesquisa de livros, considerando a aba selecionada
			Livro* livroSelecionado = Pesquisar_L(get_Livros(), abaSelecionada_p, tabs_p, 6);
			if (livroSelecionado)
				return livroSelecionado;
		}
	}
	return NULL;
}

Leitor* Biblioteca::Pesquisar_P(const list<Leitor*>& leitores, int abaSelecionada, const char* tabs[], int num_tabs) {
	string entrada;
	list<Leitor*> filtrados;
	list<Leitor*>::iterator selecao = filtrados.end(); // Inicializa seleção como vazia
	int contador = 0;
	while (true) {
		// Armazena o índice atual da seleção, se houver uma seleção válida
		int indiceSelecionado = -1;
		if (selecao != filtrados.end()) {
			indiceSelecionado = distance(filtrados.begin(), selecao);
		}

		// Limpa a lista de filtrados antes de reprocessar
		filtrados.clear();

		// Filtra os livros com base na aba selecionada e na entrada do usuário
		for (Leitor* leitor : leitores) {
			bool correspondeCategoria = false;
			switch (abaSelecionada) {
			case 0: correspondeCategoria = true; break; // Biblioteca inteira
			case 1: {
				if (leitor->quem_es() == "LeitorComum") {
					correspondeCategoria = true;
				}
				break;
			}
			case 2: {
				if (leitor->quem_es() == "Estudante") {
					correspondeCategoria = true;
				}
				break;
			}
			case 3: {
				if (leitor->quem_es() == "Professor") {
					correspondeCategoria = true;
				}
				break;
			}
			case 4: {
				if (leitor->quem_es() == "Senior") {
					correspondeCategoria = true;
				}
				break;
			}
			}
			if (correspondeCategoria && (leitor->get_nomenormalizado().find(normalizarString(entrada)) != string::npos || leitor->get_ncc().find(entrada) != string::npos)) {
				filtrados.push_back(leitor);
			}
		}

		// Atualiza a seleção com base no índice armazenado
		if (!filtrados.empty()) {
			if (indiceSelecionado >= 0 && indiceSelecionado < filtrados.size()) {
				selecao = next(filtrados.begin(), indiceSelecionado);
			}
			else {
				selecao = filtrados.begin();  // Se índice não é válido, começa do primeiro livro
			}
		}
		else {
			selecao = filtrados.end();  // Sem seleção válida se `filtrados` estiver vazio
		}

		// Exibe o menu e os livros filtrados com a seleção destacada
		system("CLS");
		mostrarMenuTabs(abaSelecionada, tabs, num_tabs);
		cout << "Pesquisa: " << entrada << endl;
		cout << "-------------------------------------------------" << endl;
		int count = 0;
		for (auto it = filtrados.begin(); it != filtrados.end() && count <= 20; ++it, count++) {
			if (it == selecao) cout << " > "; else cout << "   ";
			cout << (*it)->get_nome() << "\t[" << (*it)->get_ncc() << "]" << endl;
		}
		cout << "-------------------------------------------------" << endl;

		// Captura a tecla pressionada para navegação ou seleção
		int tecla = _getch();

		if (tecla == 224) {  // Tecla especial (setas)
			int direcao = _getch();
			if (!filtrados.empty()) {
				switch (direcao) {
				case 72:  // Seta para cima
					if (selecao != filtrados.begin()) {
						--selecao;
					}
					break;
				case 80:  // Seta para baixo
					if (next(selecao) != filtrados.end() && contador < 20) {
						++selecao;
					}
					break;
				}
			}
		}
		else if (tecla == 27) { // ESC
			return NULL; // Retorna nullptr para indicar cancelamento
		}
		else if (tecla == '\r') {  // Enter para selecionar o livro
			return (selecao != filtrados.end()) ? *selecao : nullptr;
		}
		else if (tecla == 8 && !entrada.empty()) {  // Backspace para apagar caracteres da pesquisa
			entrada.pop_back();
		}
		else if (isprint(tecla)) {  // Caractere imprimível (adiciona à pesquisa)
			entrada += static_cast<char>(tecla);
		}
	}
}

Leitor* Biblioteca::ResultadoPesquisaP() {
	const char* tabs_p[] = { "LEITORES", "Leitor Comum", "Estudante", "Professor", "Senior" };
	int abaSelecionada_p = 0;

	system("CLS");
	cout << "Pesquisar Leitor\n";

	while (true) {
		// Limpa a tela apenas uma vez antes de mostrar o menu
		system("CLS");

		// Exibe o menu de abas
		mostrarMenuTabs(abaSelecionada_p, tabs_p, 5);
		cout << "Pressione a seta para mudar de aba, Enter para pesquisar\n";

		// Espera pela tecla pressionada para navegar entre as abas
		int tecla = _getch();

		if (tecla == 224) { // Tecla especial (setas)
			switch (_getch()) {
			case 75: // Seta esquerda
				abaSelecionada_p = (abaSelecionada_p > 0) ? abaSelecionada_p - 1 : 5;
				break;
			case 77: // Seta direita
				abaSelecionada_p = (abaSelecionada_p < 5) ? abaSelecionada_p + 1 : 0;
				break;
			}
		}
		else if (tecla == 27) { // ESC
			return NULL; // Retorna nullptr para indicar cancelamento
		}
		else if (tecla == '\r') { // Enter para iniciar a pesquisa
			// Inicia a pesquisa de livros, considerando a aba selecionada
			Leitor* leitorSelecionado = Pesquisar_P(get_Leitores(), abaSelecionada_p, tabs_p, 5);
			if (leitorSelecionado)
				return leitorSelecionado;
		}
	}
	return NULL;
}

Emprestimo* Biblioteca::Pesquisar_E() {
	const list<Emprestimo*>& emprestimos = Emprestimos;
	string entrada;
	list<Emprestimo*> filtrados;
	list<Emprestimo*>::iterator selecao = filtrados.end(); // Inicializa seleção como vazia
	int contador = 0;
	while (true) {
		// Armazena o índice atual da seleção, se houver uma seleção válida
		int indiceSelecionado = -1;
		if (selecao != filtrados.end()) {
			indiceSelecionado = distance(filtrados.begin(), selecao);
		}

		// Limpa a lista de filtrados antes de reprocessar
		filtrados.clear();

		// Filtra os livros com base na aba selecionada e na entrada do usuário
		for (Emprestimo* emprestimo : Emprestimos) {

			if(emprestimo->get_leitor()->get_nomenormalizado().find(normalizarString(entrada)) != string::npos || emprestimo->get_livro()->get_titulonormalizado().find(normalizarString(entrada)) != string::npos)
				filtrados.push_back(emprestimo);
		}

		// Atualiza a seleção com base no índice armazenado
		if (!filtrados.empty()) {
			if (indiceSelecionado >= 0 && indiceSelecionado < filtrados.size()) {
				selecao = next(filtrados.begin(), indiceSelecionado);
			}
			else {
				selecao = filtrados.begin();  // Se índice não é válido, começa do primeiro livro
			}
		}
		else {
			selecao = filtrados.end();  // Sem seleção válida se `filtrados` estiver vazio
		}

		// Exibe o menu e os livros filtrados com a seleção destacada
		system("CLS");
		cout << "Pesquisa: " << entrada << endl;
		cout << "-------------------------------------------------" << endl;
		int count = 0;
		for (auto it = filtrados.begin(); it != filtrados.end() && count <= 20; ++it, count++) {
			if (it == selecao) cout << " > "; else cout << "   ";
			cout << (*it)->get_livro()->get_titulo() << "\t[" << (*it)->get_leitor()->get_nome() << "]" << endl;
		}
		cout << "-------------------------------------------------" << endl;

		// Captura a tecla pressionada para navegação ou seleção
		int tecla = _getch();

		if (tecla == 224) {  // Tecla especial (setas)
			int direcao = _getch();
			if (!filtrados.empty()) {
				switch (direcao) {
				case 72:  // Seta para cima
					if (selecao != filtrados.begin()) {
						--selecao;
					}
					break;
				case 80:  // Seta para baixo
					if (next(selecao) != filtrados.end() && contador < 20) {
						++selecao;
					}
					break;
				}
			}
		}
		else if (tecla == 27) { // ESC
			return NULL; // Retorna nullptr para indicar cancelamento
		}
		else if (tecla == '\r') {  // Enter para selecionar o livro
			return (selecao != filtrados.end()) ? *selecao : nullptr;
		}
		else if (tecla == 8 && !entrada.empty()) {  // Backspace para apagar caracteres da pesquisa
			entrada.pop_back();
		}
		else if (isprint(tecla)) {  // Caractere imprimível (adiciona à pesquisa)
			entrada += static_cast<char>(tecla);
		}
	}
}


void Biblioteca::listagemL(string tipo) {

	for (list<Livro*>::iterator it = Livros.begin(); it != Livros.end(); ++it)
	{
		//metodo de polimorfismo para saber o tipo de leitor
		if ((*it)->quem_es() == tipo) {
			(*it)->Show();
			cout << "-------------------------------------" << endl;
		}
	}

}

void Biblioteca::listagemP(string tipo) {

	for (list<Leitor*>::iterator it = Leitores.begin(); it != Leitores.end(); ++it)
	{
		//metodo de polimorfismo para saber o tipo de leitor
		if ((*it)->quem_es() == tipo) {
			(*it)->Show();
			cout << "-------------------------------------" << endl;
		}
	}
}




void Biblioteca::Sistema_Notif_atraso() {
	cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;

	cout << "---------------------- Multas Pendentes ----------------------" << endl;
	MultasPendentes();
	cout << "--------------------------------------------------------------\n\n" << endl;

	cout << "-------------------------- Emprestimos que estão próximos do prazo entrega --------------------------" << endl;
	for (Emprestimo* emprestimoAcabar : Emprestimos)
	{
		time_t DATA_ = time(nullptr);//data atual
		tm dataAtual;
		localtime_s(&dataAtual, &DATA_);

		DATA dataFIM = emprestimoAcabar->data_fim();

		if (-3 <= ConverterDataDias(dataAtual.tm_mday, dataAtual.tm_mon + 1, dataAtual.tm_year + 1900) - ConverterDataDias(dataFIM.DIA, dataFIM.MES, dataFIM.ANO) && 0 >= ConverterDataDias(dataAtual.tm_mday, dataAtual.tm_mon + 1, dataAtual.tm_year + 1900) - ConverterDataDias(dataFIM.DIA, dataFIM.MES, dataFIM.ANO))
		{
			cout << "Titulo: " << emprestimoAcabar->get_livro()->get_titulo() << " | " << "Nome: " << emprestimoAcabar->get_leitor()->get_nome() << " | CC: " << emprestimoAcabar->get_leitor()->get_ncc() << " | " << "Data de Entrega: " << dataFIM.DIA << "/" << dataFIM.MES << "/" << dataFIM.ANO << endl;
		}
	}
	cout << "---------------------------------------------------------------------------------------------------" << endl;


}




