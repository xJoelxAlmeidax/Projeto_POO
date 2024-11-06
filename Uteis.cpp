#include "Uteis.h"
const int NUM_TABS = 4; // Número de abas

void mostrarMenuTabs(int abaSelecionada) {
    const char* tabs[NUM_TABS] = { "Leitores", "Livros", "Empréstimos", "Ficheiros" };
    cout << "                             BIBLIOTECA:                             "<<endl;
    cout << "---------------------------------------------------------------------"<<endl;
    for (int i = 0; i < NUM_TABS; i++) {
        if (i == abaSelecionada) {
            cout << "  > " << tabs[i] << " <  "; // Destaque a aba selecionada
        }
        else {
            cout << "    " << tabs[i] << "    ";
        }
    }
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
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