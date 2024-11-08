#include <iostream>
#include <locale>
#include "Biblioteca.h"
#include "Uteis.h"
const int NUM_TABS = 4;
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    Biblioteca* B = new Biblioteca("Biblioteca JRST");
    B->Sistema_Not_atraso();
    system("pause"); system("cls");
    const char* opcoesTab1[] = { "Inscrever", "Alterar Dados", "Remover", "Mostrar Estudantes", "Mostrar Professores", "Mostrar Outros", "Procurar Nome" }; // 7 opções
    const char* opcoesTab2[] = { "Adicionar Livro", "Alterar Livro", "Remover Livro", "Mostrar Livros de Ficção", "Mostrar Livros Cientificos", "Mostrar livros educativos", "Mostrar Jornais", "Mostrar Revistas", "Pesquisar Livro" }; // 4 opções
    const char* opcoesTab3[] = { "Fazer Requisição", "Ver requisições",  "Entregar Livro", "Ver notificações", "Pagar Multa", "Pedir prorrogação de Requisição", "Ver multas pendentes" }; // 1 opção
    const char* opcoesTab4[] = { "Salvar Ficheiros", "Sair" };
    const char** opcoes[NUM_TABS] = { opcoesTab1, opcoesTab2, opcoesTab3, opcoesTab4 };
    int numOpcoes[NUM_TABS] = { 7, 9, 7, 2 };
    int abaSelecionada = 0;
    int opcaoSelecionada = 0;
    while (true) {

        // -------------Exibe o menu-------------
        
        mostrarMenuTabs(abaSelecionada);

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
            switch (valor) {


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
                system("cls");
                cout << "Alterar dados do Leitor\n";
                break;
            case 2:
                system("cls");
                cout << "Remover Leitor\n";
                break;
            case 3:
                system("cls");
                cout << "Mostrar Estudantes\n";
                break;
            case 4:
                system("cls");
                cout << "Mostrar Professores\n";
                break;
            case 5:
                system("cls");
                cout << "Mostrar Outros\n";
                break;
            case 6:
                system("cls");
                cout << "Mostrar Leitor P/ Nome\n";
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
                system("cls");
                cout << "Alterar Livro\n";
                break;
            case 12:
                system("cls");
                cout << "Remover Livro\n";
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
                cout << "Pesquisar Livro\n";
                break;


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
                break;
            case 31:
                return 0;
            }

            Sleep(2000); // Pausa para testes
        }

        system("cls"); // Limpa a tela para atualizar a interface
    }

    return 0;
}
