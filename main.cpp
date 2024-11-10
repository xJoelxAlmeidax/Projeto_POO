#include <iostream>
#include <locale>
#include "Biblioteca.h"
const int NUM_TABS = 4;
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    Biblioteca* B = new Biblioteca("Biblioteca JRST");
    B->load_file("Dados.txt");
    B->Sistema_Not_atraso();
    system("pause"); system("cls");
    const char* opcoesTab1[] = { "Inscrever", "Alterar Dados", "Remover","Mostrar Leitores Comuns", "Mostrar Estudantes", "Mostrar Professores", "Mostrar Seniores", "Mostrar todos", "Procurar Nome"}; // 7 opções
    const char* opcoesTab2[] = { "Adicionar Livro", "Alterar Livro", "Remover Livro", "Mostrar Livros de Ficção", "Mostrar Livros Científicos", "Mostrar livros educativos", "Mostrar Revistas", "Mostrar Jornais", "Mostrar todos", "Pesquisar Livro"}; // 4 opções
    const char* opcoesTab3[] = { "Fazer Requisição", "Ver requisições",  "Entregar Livro", "Ver notificações", "Pagar Multa", "Pedir prorrogação de Requisição", "Ver multas pendentes" }; // 1 opção
    const char* opcoesTab4[] = { "Salvar Ficheiros", "Sair" };
    const char** opcoes[NUM_TABS] = { opcoesTab1, opcoesTab2, opcoesTab3, opcoesTab4 };
    int numOpcoes[NUM_TABS] = { 9, 10, 7, 2 };
    const char* tabs[NUM_TABS] = { "Leitores", "Livros", "Empréstimos", "Ficheiros" };
    int abaSelecionada = 0;
    int opcaoSelecionada = 0;
    while (true) {

        // -------------Exibe o menu-------------
        cout << "                             BIBLIOTECA:                             " << endl;
        cout << "---------------------------------------------------------------------" << endl;
        mostrarMenuTabs(abaSelecionada, tabs, 4);

        mostrarMenuOpcoes(opcaoSelecionada, opcoes[abaSelecionada], numOpcoes[abaSelecionada]);

        int tecla = _getch();

        // --------------------Verifica as teclas de seta--------------------------

        if (tecla == 224) { 
            tecla = _getch(); 
            if (tecla == 72) { // ^
                opcaoSelecionada = (opcaoSelecionada - 1 + numOpcoes[abaSelecionada]) % numOpcoes[abaSelecionada];
            }
            else if (tecla == 80) { // v
                opcaoSelecionada = (opcaoSelecionada + 1) % numOpcoes[abaSelecionada];
            }
            else if (tecla == 75) { // <
                abaSelecionada = (abaSelecionada - 1 + NUM_TABS) % NUM_TABS;
                opcaoSelecionada = 0; //opção volta a ser a primeira da lista
            }
            else if (tecla == 77) { // >
                abaSelecionada = (abaSelecionada + 1) % NUM_TABS;
                opcaoSelecionada = 0;//opção volta a ser a primeira da lista
            }
        }
        else if (tecla == 13) { // Tecla Enter
            int valor = abaSelecionada * 10 + opcaoSelecionada; // calculo para obter valores diferentes para todas as opções 
            switch (valor) {                                      //(funciona neste caso, porque cada aba tem menos de 10 opções)


                //primeira aba
            case 0:
                system("cls");
                cout << "Inscrever Leitor\n";
                {
                    Leitor* L = B->Add_Leitores();
                    B->Add_Leitor(L);
                }
                break;
            case 1:
            {
                system("cls");
                cout << "Alterar dados do Leitor\n";
                Leitor* P = B->ResultadoPesquisaP();
                if (P == NULL) {
                    cout << "Operação Cancelada" << endl;
                    break;
                }
                B->AlterarLeitor(P);
            }
                break;
            case 2:
            {
                system("cls");
                cout << "Remover Leitor\n";
                Leitor* P = B->ResultadoPesquisaP();
                if (P == NULL) {
                    cout << "Operação Cancelada" << endl;
                    break;
                }
                B->RemoverLeitor(P);
                delete(P);
            }
                break;
            case 3:
                system("cls");
                cout << "Mostrar Leitores Comuns\n";
                B->listagem_leitoresTipo<LeitorComum>();
                break;
            case 4:
                system("cls");
                cout << "Mostrar Estudantes\n";
                B->listagem_leitoresTipo<Estudante>();
                break;
            case 5:
                system("cls");
                cout << "Mostrar Professores\n";
                B->listagem_leitoresTipo<Professor>();
                break;
            case 6:
                system("cls");
                cout << "Mostrar Seniores\n";
                B->listagem_leitoresTipo<Senior>();
                break;
            case 7:
                system("cls");
                cout << "Mostrar todos os Utilizadores\n";
                B->RelatorioLeitores();
                break;
            case 8:
            {
                system("cls");
                cout << "Mostrar Leitor P/ Nome\n";
                Leitor* P = B->ResultadoPesquisaP();
                if (P == NULL) {
                    cout << "Operação Cancelada" << endl;
                    break;
                }
                cout << "--------------------------------------" << endl;
                P->Show();
                cout << "--------------------------------------" << endl;
            }
                break;


                //segunda aba
            case 10:
                system("cls");
                cout << "Adicionar livro\n";
                {
                    Livro* L = B->Add_Livros();
                    B->Add_Livro(L);
                }
                break;
            case 11:
            {
                system("cls");
                cout << "Alterar Livro\n";
                Livro* L = B->ResultadoPesquisa();
                if (L == NULL) {
                    cout << "Operação Cancelada" << endl;
                    break;
                }
                B->AlterarLivro(L);

                

                }
                break;
            case 12:
            {
                system("cls");
                cout << "Remover Livro\n";
                Livro* L = B->ResultadoPesquisa();
                if (L == NULL) {
                    cout << "Operação Cancelada" << endl;
                    break;
                }
                B->RemoverLivro(L);
                delete(L);
            }
                break;
            case 13:
                system("cls");
                cout << "Mostrar Livros de Ficção\n";
                B->listagem_livros<LivroFiccao>();
                break;
            case 14:
                system("cls");
                cout << "Mostrar Livros Científicos\n";
                B->listagem_livros<LivroCientifico>();
                break;
            case 15:
                system("cls");
                cout << "Mostrar Livros Educativos\n";
                B->listagem_livros<LivroEducativo>();
                break;
            case 16:
                system("cls");
                cout << "Mostrar Revistas\n";
                B->listagem_livros<Revista>();
                break;
            case 17:
                system("cls");
                cout << "Mostrar Jornais\n";
                B->listagem_livros<Jornal>();
                break;
            case 18:
                system("cls");
                cout << "Mostrar todos os Livros\n";
                B->RelatorioCategorias();
                break;
            case 19:
            {
                Livro* L = B->ResultadoPesquisa();
                if (L == NULL) {
                    cout << "Operação Cancelada" << endl;
                    break;
                }
                cout << "--------------------------------------" << endl;
                L->Show();
                cout << "--------------------------------------" << endl;
                break;
            }

                //terceira aba
            case 20:
                system("cls");
                cout << "Fazer Requisição\n";
                break;
            case 21:
                system("cls");
                cout << "Ver Requisição\n";
                break;
            case 22:
                system("cls");
                cout << "Entregar Livro\n";
                break;
            case 23:
                system("cls");
                cout << "Ver Notificações\n";
                break;
            case 24:
                system("cls");
                cout << "Pagar Multa\n";
                break;
            case 25:
                system("cls");
                cout << "Pedir prorrogação\n";
                break;
            case 26:
                system("cls");
                cout << "Ver Multas pendentes\n";
                break;

                //quarta aba
            case 30:
                system("cls");
                cout << "Salvar Ficheiros\n";
                B->save_file("Dados.txt");
                break;
            case 31:
                system("cls");
                cout << "Sair\n";
                B->save_file("Dados.txt");
                return 0;
            }

            Sleep(4000); // Pausa para testes
        }
        system("cls"); // Limpa a tela para atualizar a interface
    }
}
