#include "Uteis.h"
#include <regex>

const int NUM_TABS = 4; // Número de abas

void mostrarMenuTabs(int abaSelecionada, const char* tabs[], int num_tabs) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < num_tabs; i++) {
        if (i == abaSelecionada) {
            SetConsoleTextAttribute(hConsole, (7 << 4) | 0);
            cout << "    " << tabs[i] << "    "; // Destaque a aba selecionada
            SetConsoleTextAttribute(hConsole, 7);
        }
        else {
            cout << "    " << tabs[i] << "    ";
        }
    }
    cout << endl;
}

void mostrarMenuOpcoes(int opcaoSelecionada, const char* opcoes[], int numOpcoes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < numOpcoes; i++) {
        if (i == opcaoSelecionada) {
            SetConsoleTextAttribute(hConsole, (15 << 4) | 0);
            cout << " > " << opcoes[i] << endl; // Destaca a opção selecionada
            SetConsoleTextAttribute(hConsole, 7);
        }
        else {
            SetConsoleTextAttribute(hConsole, 7);
            cout << "   " << opcoes[i] << endl;
        }
    }
}

//Remover acentos e letras maiusculas para verificações quando é feito um input
string normalizarString(const string& texto) {
    string textoNormalizado = texto;

    // Converter para minúsculas
    transform(textoNormalizado.begin(), textoNormalizado.end(), textoNormalizado.begin(), ::tolower);

    // Substituir letras acentuadas
    for (char& c : textoNormalizado) {
        switch (c) {
        case 'á': case 'à': case 'ã': case 'â': case 'æ': c = 'a'; break;
        case 'é': case 'è': case 'ê': c = 'e'; break;
        case 'í': case 'ì': case 'î': case '¡':c = 'i'; break;
        case 'ó': case 'ò': case 'õ': case 'ô': c = 'o'; break;
        case 'ú': case 'ù': case 'û': c = 'u'; break;
        case 'ç': case '‡': c = 'c'; break;
        case 'Á': case 'À': case 'Ã': case 'Â': case 'Æ': c = 'a'; break;
        case 'É': case 'È': case 'Ê': c = 'e'; break;
        case 'Í': case 'Ì': case 'Î': c = 'i'; break;
        case 'Ó': case 'Ò': case 'Õ': case 'Ô': c = 'o'; break;
        case 'Ú': case 'Ù': case 'Û': c = 'u'; break;
        case 'Ç': c = 'c'; break;
        }
    }

    return textoNormalizado;
}

bool validarEmail(const string& email) {
    // Valida o formato dos emails
    const regex formatoEmail(R"((\w+)(\.\w+)*@(\w+)(\.\w+)+)");
    return regex_match(email, formatoEmail);
}

bool validarTelefone(const string& telefone) {
    // Valida os números de telefone com 9 dígitos começando com 9
    const regex formatoTelefone(R"(9[1236]\d{7})");
    return regex_match(telefone, formatoTelefone);
}

bool validarNCC(const string& ncc) {
    return ncc.size() == 9 && So_numeros(ncc); //funciona como um ciclo
}

bool So_numeros(string num) {
    regex pattern("^[0-9]{1,9}$");
    return regex_match(num, pattern);
}

bool ValidarISBN(const string& ISBN) {
    regex pattern(R"(((^\d{1,5}-\d{1,7}-\d{1,7}-[\dX]$)|^\d{10}$)|((^\d{3}-\d{1,5}-\d{1,7}-\d{1,7}-\d$)|^\d{13}$))");
    //R"()" serve para transformar em string literal bruta OU seja para ser lida exatamente como escrita
    return regex_match(ISBN, pattern);
}

bool ValidarISSN(const string& ISSN) {
    regex pattern(R"(^\d{4}-\d{3}[\dX]$|^\d{8}$)");
    //R"()" serve para transformar em string literal bruta OU seja para ser lida exatamente como escrita
    return regex_match(ISSN, pattern);
}

static bool AnoBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true;
    }
    return false;
}

int DiasNoMes(int mes, int ano) {
    switch (mes) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return AnoBissexto(ano) ? 29 : 28; // if AnoBissexto == true -> 29 else -> 28
    default:
        return 31;
    }
}

int ConverterDataDias(int dia, int mes, int ano) {
    int DiasTotais = dia;

    // Somar os dias dos meses anteriores ao mês atual
    for (int mes_ = 1; mes_ < mes; mes_++) {
        DiasTotais += DiasNoMes(mes_, ano);
    }

    // Somar os dias dos anos anteriores ao ano atual (assumindo 1500 como referência)
    for (int ano_ = 1500; ano_ < ano; ano_++) {
        DiasTotais += AnoBissexto(ano_) ? 366 : 365;
    }

    return DiasTotais;
}

void subs_systpause() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Alterar a cor do fundo para branco e o texto para preto
    SetConsoleTextAttribute(hConsole, 14);
    cout << "Pressione ENTER para continuar..." << endl;

    // Voltar à cor padrão
    SetConsoleTextAttribute(hConsole, 7); 
    int tecla;
    do {
        tecla = _getch();
    } while (tecla != 13); // Continua até pressionar o Enter
}

void EncerrarPrograma() {
    std::vector<std::string> art = {
        "                        .,,uod8B8bou,,.",
        "                ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:.",
        "            ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||",
        "            !...:!TVBBBRPFT||||||||||!!^^\"\"'   ||||",
        "            !.......:!?|||||!!^^\"\"'            ||||",
        "            !.........||||                     ||||",
        "            !.........||||                     ||||",
        "            !.........||||                     ||||",
        "            !.........||||                     ||||",
        "            !.........||||                     ||||",
        "            `.........||||                    ,||||",
        "            .;.......||||               _.-!!|||||",
        "    .,uodWBBBBb.....||||       _.-!!|||||||||!:'",
        "!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb....",
        "!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `.",
        "!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `.",
        "!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"`;:::       `.",
        "!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo.",
        "`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo.",
        "    `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'",
        "    `........::::::::::::::::;iof688888888888888888888b.     `",
        "        `......:::::::::;iof688888888888888888888888888888b.",
        "        `....:::;iof688888888888888888888888888888888899fT!",
        "            `..::!8888888888888888888888888888888899fT|!^\"'",
        "            `' !!988888888888888888888888899fT|!^\"'",
        "                `!!8888888888888888899fT|!^\"'",
        "                    `!988888888899fT|!^\"'",
        "                    `!9899fT|!^\"'"
    };

    // Índices do ecrã (linhas que representam a tela)
    const int screen_start = 5; // Linha inicial do ecrã
    const int screen_end = 9;   // Linha final do ecrã

    for (int cycle = 0; cycle < 3; ++cycle) { // Executa duas vezes
        for (int dot_count = 0; dot_count <= 2; ++dot_count) { // Pontos progressivos
            // Limpar a tela
            std::cout << "\033[2J\033[1;1H";

            // Atualizar a arte com o texto no ecrã
            for (size_t j = 0; j < art.size(); ++j) {
                if (j >= screen_start && j <= screen_end) {
                    if (j == screen_start + 2) { // Linha principal do texto
                        std::cout << "            !.........||||   A encerrar.";
                        for (int d = 0; d < dot_count; ++d) std::cout << ".";
                        for (int s = 0; s < 3 - dot_count; ++s) std::cout << " "; // Adicionar espaços para manter o alinhamento
                        std::cout << "    ||||" << std::endl;
                    }
                    else {
                        // Outras linhas do ecrã
                        std::cout << "            !.........||||                     ||||" << std::endl;
                    }
                }
                else {
                    // Partes fixas da arte
                    std::cout << art[j] << std::endl;
                }
            }

            // Pausar antes de adicionar mais um ponto
            Sleep(500);
        }
    }

    system("cls");
    for (size_t j = 0; j < art.size(); ++j) {
        cout << art[j] << endl;
    }
}


/*cout << R"(
                    .--.         .--.         .--.         .--.
                   |o_o |       |o_o |       |o_o |       |o_o |
                   |:_/ |       |:_/ |       |:_/ |       |:_/ |
                  //   \ \     //   \ \     //   \ \     //   \ \
                 (|     | )   (|     | )   (|     | )   (|     | )
                /'\_   _/`\  /'\_   _/`\  /'\_   _/`\  /'\_   _/`\
                \___)=(___/  \___)=(___/  \___)=(___/  \___)=(___/
                 __|___|__    __|___|_    ___|___|__    __|___|__
                /         \  /        \  /          \  /         \
                |  Simão  |  |  Joel  |  |  Renato  |  |  Tomás  |
                \_________/  \________/  \__________/  \_________/
)";*/




void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // Código para limpar o terminal
}

void drawEnvelope(int step) {
    clearScreen();  // Limpa a tela a cada nova fase
    if (step == 0) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                 ?                \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%                0%     ?&\n";
        std::cout << "&%      ?@%            =%?      ?&\n";
        std::cout << "%%        ?&0  =======?%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
    }
    else if (step == 1) {
        std::cout << "           ?0?0=?==?              \n";
        std::cout << "                ?00               \n";
        std::cout << "                 0?               \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%                0%     ?&\n";
        std::cout << "&%      ?@%            =%?      ?&\n";
        std::cout << "%%        ?&0  =======?%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
    }
    else if (step == 2) {
        std::cout << "              0     0?            \n";
        std::cout << "            ?0       ??           \n";
        std::cout << "           %????= ????%           \n";
        std::cout << "           ????%?=%0              \n";
        std::cout << "            ?%00=0 =%0            \n";
        std::cout << "          0%?   ==   ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%                0%     ?&\n";
        std::cout << "&%      ?@%            =%?      ?&\n";
        std::cout << "%%        ?&0  =======?%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
    }
    else if (step == 3) {
        std::cout << "                                  \n";
        std::cout << "             ?0?==00???           \n";
        std::cout << "              0=?0%=?==0          \n";
        std::cout << "              ?0======?0          \n";
        std::cout << "            ?&%=====?&0           \n";
        std::cout << "          0%0=====  =&&0          \n";
        std::cout << "        0%?=??=?==?=?=0%&0        \n";
        std::cout << "      0%?     =?=0   ?= =%&0      \n";
        std::cout << "    ?%?       0=?          %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%                0%     ?&\n";
        std::cout << "&%      ?@%            =%?      ?&\n";
        std::cout << "%%        ?&0  =======?%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
    }
    else if (step == 4) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                 ?                \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?    0??  ??0&&0        \n";
        std::cout << "      0%?      =?=0%== ==%&0      \n";
        std::cout << "    ?%?      =??===? ===?  %&?    \n";
        std::cout << "   0?     ?00?======??00     0%0  \n";
        std::cout << " ??=======?0%%%==== =%0000???00&@0\n";
        std::cout << "&@0????=======0==?=? 0         0&0\n";
        std::cout << "&&&0         0=?=   0?       ?0 0&\n";
        std::cout << "@% 0&%       ==             %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%                0%     ?&\n";
        std::cout << "&%      ?@%            =%?      ?&\n";
        std::cout << "%%        ?&0  =======?%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 5) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                 ?                \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======   ?=             0&0\n";
        std::cout << "&&&0            0?0  ??      ?0 0&\n";
        std::cout << "@% 0&%          0==%0==??   %?  0&\n";
        std::cout << "@%   %&=  =000??======? ? =&=   0&\n";
        std::cout << "&%    =&%  ????=====?==0?0%     ?&\n";
        std::cout << "&%      ?@%   ?=====??==%?      ?&\n";
        std::cout << "%%        ?@%0??000?0=?%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 6) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                 ?                \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%        00      0%     ?&\n";
        std::cout << "&%      ?@%      0=0?0??&?      ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 7) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                 ?                \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%       =?      0%      ?&\n";
        std::cout << "&%      ?@%      ??=  =%?       ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 8) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                 ?                \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%               0%      ?&\n";
        std::cout << "&%      ?@%     ??=   =%?       ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 9) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                 ?                \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%       =?      0%      ?&\n";
        std::cout << "&%      ?@%      ??=  =%?       ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 10) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                 ?                \n";
        std::cout << "              ?%0=?0              \n";
        std::cout << "            ?%0    =%0            \n";
        std::cout << "          0%?        ?&0          \n";
        std::cout << "        0%?            %&0        \n";
        std::cout << "      0%?               =%&0      \n";
        std::cout << "    ?%?                    %&?    \n";
        std::cout << "   0?                        0%0  \n";
        std::cout << " ??========????00000000000???00&@0\n";
        std::cout << "&@0????======                  0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%        ==      0%     ?&\n";
        std::cout << "&%      ?@%      0=0?0??&?      ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 11) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "              ?%@%0               \n";
        std::cout << "           ?%@&?  ?%&%?           \n";
        std::cout << "        ?%@%?        =%&%?        \n";
        std::cout << "      %&%?              =%&%0     \n";
        std::cout << "   0&%?                    =?%%?  \n";
        std::cout << " 0&0????????00000%%%%%&&&&&&&&&&@0\n";
        std::cout << "&%%0???????=======             0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%        ==      0%     ?&\n";
        std::cout << "&%      ?@%      0=0?0??&?      ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 12) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "          ?0%&&&&0%%%0??          \n";
        std::cout << "     ?0%&&&0?        =?0%&&&%0?   \n";
        std::cout << " 0&0????????00000%%%%%&&&&&&&&&&@0\n";
        std::cout << "&%%0???????=======             0&0\n";
        std::cout << "&&&0                         ?0 0&\n";
        std::cout << "@% 0&%                      %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%        ==      0%     ?&\n";
        std::cout << "&%      ?@%      0=0?0??&?      ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 13) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "    ????????00000%%%%%&&&&&&&&&&@0\n";
        std::cout << "&%&&@@%&0??========     =0%%%0?%&0\n";
        std::cout << "&&&0  =?0%%%%%0??= =0%%0?    ?0 0&\n";
        std::cout << "@% 0&%        =??0%?=       %?  0&\n";
        std::cout << "@%   %&=                  ?&=   0&\n";
        std::cout << "&%    =&%        ==      0%     ?&\n";
        std::cout << "&%      ?@%      0=0?0??&?      ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 14) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "    ????????00000%%%%%&&&&&&&&&&@0\n";
        std::cout << "&%%&0??????????==           0@@@&0\n";
        std::cout << "&&&0@&?                   %%%00 0&\n";
        std::cout << "@% 0&0%&%=              %@%=%?  0&\n";
        std::cout << "@%   %&==0&%?        =%@0 ?&=   0&\n";
        std::cout << "&%    =&%   0&%?   ?&&?  0%     ?&\n";
        std::cout << "&%      ?@%    0%&&&00??&?      ?&\n";
        std::cout << "%%        ?@@0000???%?0%        ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
    else if (step == 15) {
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "                                  \n";
        std::cout << "       ?????00000%%%%%&&&&&&&&&&@0\n";
        std::cout << "&%%00000?????0???======       =&&0\n";
        std::cout << "&&&0                         ?&=0&\n";
        std::cout << "@% 0@?                      %0  0&\n";
        std::cout << "@%   &&=                  =&=   0&\n";
        std::cout << "&%    =&%                %%     ?&\n";
        std::cout << "&%      ?&0            =&?      ?&\n";
        std::cout << "%%        ?&0   ==?????%&       ?&\n";
        std::cout << "0%         ?0???????=?%?        ?&\n";
        std::cout << "?&       ??            =0?      ?&\n";
        std::cout << "?@     ??                =0?    ?&\n";
        std::cout << "?@   ??                    =?=  ?&\n";
        std::cout << "=& =?                         ==0%\n";
        std::cout << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
        }
}