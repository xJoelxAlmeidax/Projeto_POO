#include "Uteis.h"
const int NUM_TABS = 4; // Número de abas

void mostrarMenuTabs(int abaSelecionada) {
    const char* tabs[NUM_TABS] = { "Leitores", "Livros", "Empréstimos", "4 M4C4C0S" };

    cout << "---------------------------------------------------------------------\n";
    cout << "BIBLIOTECA: ";
    for (int i = 0; i < NUM_TABS; i++) {
        if (i == abaSelecionada) {
            cout << "> " << tabs[i] << " <  "; // Destaque a aba selecionada
        }
        else {
            cout << "  " << tabs[i] << "   ";
        }
    }
    cout << endl;
    cout << "---------------------------------------------------------------------\n";
}

void mostrarMenuOpcoes(int opcaoSelecionada, const char* opcoes[], int numOpcoes) {

    for (int i = 0; i < numOpcoes; i++) {
        if (i == opcaoSelecionada) {
            cout << " > "; // Destaca a opção selecionada
        }
        else {
            cout << "   ";
        }
        cout << opcoes[i];
        if (i == opcaoSelecionada) {
            cout << " <" << endl; // Destaca a opção selecionada
        }
        else {
            cout << endl;
        }
    }
}

void menu_principal() {
    // Definindo opções para cada aba com diferentes números de opções
    const char* opcoesTab1[] = { "Inscrever", "Alterar Dados", "Remover", "Mostrar Estudantes", "Mostrar Professores", "Mostrar Outros", "Procurar Nome" }; // 2 opções
    const char* opcoesTab2[] = { "Adicionar Livro", "Alterar Livro", "Remover Livro", "Mostrar Livros de Ficção", "Mostrar Livros Cientificos", "Mostrar livros educativos", "Mostrar Jornais", "Mostrar Revistas", "Pesquisar Livro" }; // 4 opções
    const char* opcoesTab3[] = { "Fazer Requisição", "Ver requisições", "Ver notificações", "Pagar Multa", "Pedir prorrogação de Requisição", "Ver multas pendentes" }; // 1 opção

    // Criando um array de ponteiros para armazenar as opções de cada aba
    const char** opcoes[NUM_TABS] = { opcoesTab1, opcoesTab2, opcoesTab3 };
    int numOpcoes[NUM_TABS] = { 6, 9, 6 }; // Número de opções em cada aba

    int abaSelecionada = 0; // Inicia na primeira aba
    int opcaoSelecionada = 0; // Inicia na primeira opção da aba selecionada

    while (true) {
        // Exibe o menu de abas
        /*cout << R"(
                .--.         .--.          .--.           .--.  
               |o_o |       |o_o |        |o_o |         |o_o | 
               |:_/ |       |:_/ |        |:_/ |         |:_/ | 
              //   \ \     //   \ \      //   \ \       //   \ \ 
             (|     | )   (|     | )    (|     | )     (|     | )
            /'\_   _/`\  /'\_   _/`\   /'\_   _/`\    /'\_   _/`\
            \___)=(___/  \___)=(___/   \___)=(___/    \___)=(___/
              _|___|_      _|___|_       _|___|_       .-|---|-. 
             /       \    /       \     /       \     /         \ 
            |         |  |         |   |         |   |    ___    | 
            |_________|  |_________|   |  O   O  |   |   /   \   |
)";
        cout << R"(
                       .,,uod8B8bou,,.                             
              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.                    
         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||                   
         !...:!TVBBBRPFT||||||||||!!^^""'   ||||                   
         !.......:!?|||||!!^^""'            ||||                   
         !.........||||                     ||||                   
         !.........||||  ##                 ||||                   
         !.........||||                     ||||                   
         !.........||||                     ||||                   
         !.........||||                     ||||                   
         !.........||||                     ||||                   
         `.........||||                    ,||||                   
          .;.......||||               _.-!!|||||                   
   .,uodWBBBBb.....||||       _.-!!|||||||||!:'                    
!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....               
!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.             
!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.           
!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^"`;:::       `.         
!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.   
`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo. 
  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'
    `........::::::::::::::::;iof688888888888888888888b.     `     
      `......:::::::::;iof688888888888888888888888888888b.         
        `....:::;iof688888888888888888888888888888888899fT!        
          `..::!8888888888888888888888888888888899fT|!^"'          
            `' !!988888888888888888888888899fT|!^"'                
                `!!8888888888888888899fT|!^"'                      
                  `!988888888899fT|!^"'                            
                    `!9899fT|!^"'                                  
    )";*/
        mostrarMenuTabs(abaSelecionada);

        // Exibe o menu de opções para a aba selecionada
        mostrarMenuOpcoes(opcaoSelecionada, opcoes[abaSelecionada], numOpcoes[abaSelecionada]);

        // Captura a tecla pressionada
        int tecla = _getch();

        // Verifica as teclas de seta
        if (tecla == 224) { // Teclas de seta geram um código adicional (224)
            tecla = _getch(); // Lê o próximo valor para identificar a seta
            if (tecla == 72) { // Seta para cima
                opcaoSelecionada = (opcaoSelecionada - 1 + numOpcoes[abaSelecionada]) % numOpcoes[abaSelecionada];
            }
            else if (tecla == 80) { // Seta para baixo
                opcaoSelecionada = (opcaoSelecionada + 1) % numOpcoes[abaSelecionada];
            }
            else if (tecla == 75) { // Seta para a esquerda
                abaSelecionada = (abaSelecionada - 1 + NUM_TABS) % NUM_TABS; // Muda para aba anterior
                opcaoSelecionada = 0; // Reinicia a seleção da opção para a primeira
            }
            else if (tecla == 77) { // Seta para a direita
                abaSelecionada = (abaSelecionada + 1) % NUM_TABS; // Muda para aba seguinte
                opcaoSelecionada = 0; // Reinicia a seleção da opção para a primeira
            }
        }
        else if (tecla == 13) { // Tecla Enter
            // Se o usuário pressionar Enter, seleciona a opção atual
            cout << "Você escolheu: " << opcoes[abaSelecionada][opcaoSelecionada] << endl;
            Sleep(1000); // Pausa para mostrar a escolha
        }

        system("cls"); // Limpa a tela para atualizar a interface
    }
}
