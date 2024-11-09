#include "Biblioteca.h"
Biblioteca::Biblioteca(string _nome) {
	NOME = _nome;
}
Biblioteca::~Biblioteca(){}

Livro* Biblioteca::Add_Livros() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	string tipo_uti;
	string titulo;
	string autor;
	int ano; 
	cout << "T�tulo: ";
	getline(cin, titulo);
	cout << "Autor: ";
	getline(cin, autor);
	cout << "Ano: ";
	cin >> ano;
	cin.ignore();
	Livro* L = NULL;
	do {
		cout << "Tipo de Livro(Fic��o/Cientifico/Educativo/Jornal/Revista): ";
		getline(cin, tipo_uti);
		tipo_uti = normalizarString(tipo_uti);
		if (tipo_uti == "ficcao") {
			string _ISBN;
			string _subgenero;
			cout << "ISBN: ";
			cin >> _ISBN;
			cin.ignore();
			cout << "Subg�nero: ";
			getline(cin, _subgenero);
			L = new LivroFiccao(titulo, autor, ano, _ISBN, _subgenero);
			break;
		}
		else if (tipo_uti == "cientifico") {
			string _ISBN;
			string _areaestudo;
			string _revisor;
			cout << "ISBN: ";
			cin >> _ISBN;
			cin.ignore();
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
			cout << "ISBN: ";
			cin >> _ISBN;
			cin.ignore();
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
			cout << "ISSN: ";
			cin >> _issn;
			cin.ignore();
			cout << "Edi��o: ";
			getline(cin, _edicao);
			cout << "Editor Chefe: ";
			getline(cin, _editor_boss);
			cout << "Distribui��o geogr�fica (nacional/regional/local/etc.): ";
			getline(cin, _tipo_dis);
			L = new Jornal(titulo, autor, ano, _issn, _edicao, _editor_boss, _tipo_dis);
			break;
		}
		else if (tipo_uti == "revista") {
			string _issn;
			string _edicao;
			string _editora;
			string _fotografo;
			cout << "ISSN: ";
			cin >> _issn;
			cin.ignore();
			cout << "Edi��o: ";
			getline(cin, _edicao);
			cout << "Editora: ";
			getline(cin, _editora);
			cout << "Fotografo da Capa: ";
			getline(cin, _fotografo);
			L = new Revista(titulo, autor, ano, _issn, _edicao, _editora, _fotografo);
			break;
		}
		else {
			cout << "N�o � valida! Tente novamente!" << endl;
		}

	} while (true);	
	return L;
}

Leitor* Biblioteca::Add_Leitores() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	string ncc;
	string nome;
	string morada;
	string telefone;
	int idade;
	cout << "Nome: ";
	getline(cin, nome);
	cout << "N�mero de Cart�o de Cidad�o: ";
	getline(cin, ncc);
	cout << "Morada: ";
	getline(cin, morada);
	cout << "Idade: ";
	cin >> idade;
	cin.ignore();

	while (true) {
		cout << "Telefone: ";
		getline(cin, telefone);

		if (!validarTelefone(telefone)) {
			cout << "Formato do Telefone inv�lido! Tente novamente." << endl;
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
						cout << "Email inv�lido! Tente novamente." << endl;
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
					cout << "Email inv�lido! Tente novamente." << endl;
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
					cout << "Email inv�lido! Tente novamente." << endl;
				}
				else {
					break;
				}
			}
			string _disciplinas;
			cout << "Disciplinas: ";
			getline(cin, _disciplinas);
			L = new Professor(ncc, nome, morada, telefone, idade, email,_disciplinas);
			break;
		}
		else {
			cout << "N�o � valida! Tente novamente!" << endl;
		}

	} while (true);

	return L;
}

bool Biblioteca::Add_Livro(Livro* L) {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	Livros.push_back(L);
	return true;
}

void Biblioteca::RemoverLivro(Livro* L)
{

}

void Biblioteca::AlterarLivro()
{
	cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
}

bool Biblioteca::Add_Leitor(Leitor* P) {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	Leitores.push_back(P);
	return true;
}

void Biblioteca::Add_Emprestimo() {
	cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;

}

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

		getline(File, buffer2, '\t');
		getline(File, buffer3, '\t');
		getline(File, buffer4, '\t');

		if (buffer1 == "LivroCientifico") {
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
		else if (buffer1 == "LeitorComum") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7);
			P = new LeitorComum(buffer2,buffer3,buffer4,buffer5,stoi(buffer6),buffer7);
		}
		else if (buffer1 == "Professor") {
			getline(File, buffer5, '\t');
			getline(File, buffer6);
			P = new Professor(buffer2, buffer3, buffer4, buffer5, stoi(buffer6), buffer7,buffer8);
		}
		else if (buffer1 == "Senior") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7, '\t');
			getline(File, buffer8);
			P = new Senior(buffer2, buffer3, buffer4, buffer5, stoi(buffer6), buffer7);
		}
		else if (buffer1 == "Estudante") {
			getline(File, buffer5, '\t');
			getline(File, buffer6, '\t');
			getline(File, buffer7, '\t');
			getline(File, buffer8);
			P = new Estudante(buffer2, buffer3, buffer4, buffer5, stoi(buffer6), buffer7, buffer8);
		}
		if (L != NULL)
		{
			Add_Livro(L);
		}
		if (P != NULL)
		{
			Add_Leitor(P);
		}
	}

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
		if (LivroCientifico * livroTeste = dynamic_cast<LivroCientifico*>(livroSave)) {
			File << "LivroCientifico\t";
			File << livroTeste->get_titulo() << "\t";
			File << livroTeste->get_autor() << "\t";
			File << livroTeste->get_ano() << "\t";
			File << livroTeste->get_isbn() << "\t";
			File << livroTeste->get_area() << "\t";
			File << livroTeste->get_revisor() << "\n";
		}
		else if (LivroEducativo* livroTeste = dynamic_cast<LivroEducativo*>(livroSave)) {
			File << "LivroEducativo\t";
			File << livroTeste->get_titulo() << "\t";
			File << livroTeste->get_autor() << "\t";
			File << livroTeste->get_ano() << "\t";
			File << livroTeste->get_isbn() << "\t";
			File << livroTeste->get_idade() << "\t";
			File << livroTeste->get_area() << "\t";
			File << livroTeste->get_ilustrador() << "\n";
		}
		else if (LivroFiccao* livroTeste = dynamic_cast<LivroFiccao*>(livroSave)) {
			File << "LivroFiccao\t";
			File << livroTeste->get_titulo() << "\t";
			File << livroTeste->get_autor() << "\t";
			File << livroTeste->get_ano() << "\t";
			File << livroTeste->get_isbn() << "\t";
			File << livroTeste->get_subgenero() << "\n";

		}
		else if (Revista* livroTeste = dynamic_cast<Revista*>(livroSave))
		{
			File << "Revista\t";
			File << livroTeste->get_titulo() << "\t";
			File << livroTeste->get_autor() << "\t";
			File << livroTeste->get_ano() << "\t";
			File << livroTeste->get_issn() << "\t";
			File << livroTeste->get_edicao() << "\t";
			File << livroTeste->get_editora() << "\t";
			File << livroTeste->get_fotografo() << "\n";
		}
		else if (Jornal* livroTeste = dynamic_cast<Jornal*>(livroSave))
		{
			File << "Jornal\t";
			File << livroTeste->get_titulo() << "\t";
			File << livroTeste->get_autor() << "\t";
			File << livroTeste->get_ano() << "\t";
			File << livroTeste->get_issn() << "\t";
			File << livroTeste->get_edicao() << "\t";
			File << livroTeste->get_editor() << "\t";
			File << livroTeste->get_tipo() << "\n";
		}
	}

	for (auto leitorSave : Leitores)
	{
		if (LeitorComum* LeitorTeste = dynamic_cast<LeitorComum*>(leitorSave)) {
			File << "LeitorComum\t";
			File << LeitorTeste->get_ncc() << "\t";
			File << LeitorTeste->get_nome() << "\t";
			File << LeitorTeste->get_morada() << "\t";
			File << LeitorTeste->get_telefone() << "\t";
			File << LeitorTeste->get_idade() << "\t";
			File << LeitorTeste->get_Email() << "\n";
		}
		else if (Senior* LeitorTeste = dynamic_cast<Senior*>(leitorSave)) {
			File << "Senior\t";
			File << LeitorTeste->get_ncc() << "\t";
			File << LeitorTeste->get_nome() << "\t";
			File << LeitorTeste->get_morada() << "\t";
			File << LeitorTeste->get_telefone() << "\t";
			File << LeitorTeste->get_idade() << "\t";
			File << LeitorTeste->get_NecessidadesAcessibilidade() << "\n";
		}
		else if (Professor* LeitorTeste = dynamic_cast<Professor*>(leitorSave)) {
			File << "Professor\t";
			File << LeitorTeste->get_ncc() << "\t";
			File << LeitorTeste->get_nome() << "\t";
			File << LeitorTeste->get_morada() << "\t";
			File << LeitorTeste->get_telefone() << "\t";
			File << LeitorTeste->get_idade() << "\t";
			File << LeitorTeste->get_Email() << "\n";
			File << LeitorTeste->get_Disciplinas() << "\n";

		}
		else if (Estudante* LeitorTeste = dynamic_cast<Estudante*>(leitorSave))
		{
			File << "Estudante\t";
			File << LeitorTeste->get_ncc() << "\t";
			File << LeitorTeste->get_nome() << "\t";
			File << LeitorTeste->get_morada() << "\t";
			File << LeitorTeste->get_telefone() << "\t";
			File << LeitorTeste->get_idade() << "\t";
			File << LeitorTeste->get_Email() << "\t";
			File << LeitorTeste->get_curso() << "\n";
		}
	}

	File.close();
	return true;
}

void Biblioteca::RelatorioCategorias() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	cout << "LIVROS" << endl;
	cout << "------------------------------------------" << endl;
	cout << "            LIVROS CIENTIFICOS" << endl;
	cout << "------------------------------------------" << endl;
	listagem_livros<LivroCientifico>();
	cout << "------------------------------------------" << endl;
	cout << "             LIVROS DE FIC��O" << endl;
	cout << "------------------------------------------" << endl;
	listagem_livros<LivroFiccao>();
	cout << "------------------------------------------" << endl;
	cout << "            LIVROS EDUCATIVOS" << endl;
	cout << "------------------------------------------" << endl;
	listagem_livros<LivroEducativo>();
	cout << "------------------------------------------" << endl;
	cout << "                REVISTAS" << endl;
	cout << "------------------------------------------" << endl;
	listagem_livros<Revista>();
	cout << "------------------------------------------" << endl;
	cout << "                JORNAIS" << endl;
	cout << "------------------------------------------" << endl;
	listagem_livros<Jornal>();
}

void Biblioteca::RelatorioLeitores() {
	//cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
	cout << "LIVROS" << endl;
	cout << "------------------------------------------" << endl;
	cout << "            Leitores Comuns" << endl;
	cout << "------------------------------------------" << endl;
	listagem_leitoresTipo<LeitorComum>();
	cout << "------------------------------------------" << endl;
	cout << "             Professores" << endl;
	cout << "------------------------------------------" << endl;
	listagem_leitoresTipo<Professor>();
	cout << "------------------------------------------" << endl;
	cout << "            Estudantes" << endl;
	cout << "------------------------------------------" << endl;
	listagem_leitoresTipo<Estudante>();
	cout << "------------------------------------------" << endl;
	cout << "                Seniores" << endl;
	cout << "------------------------------------------" << endl;
	listagem_leitoresTipo<Senior>();

}

void Biblioteca::Sistema_Not_atraso() {
	cout << "Entrei em: [" << __FUNCTION__ << "]" << endl;
}


