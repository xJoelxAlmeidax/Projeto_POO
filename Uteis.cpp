#include "Uteis.h"
#include <regex>

const int NUM_TABS = 4; // N�mero de abas

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
            cout << " > " << opcoes[i] << endl; // Destaca a op��o selecionada
            SetConsoleTextAttribute(hConsole, 7);
        }
        else {
            SetConsoleTextAttribute(hConsole, 7);
            cout << "   " << opcoes[i] << endl;
        }
    }
}

//Remover acentos e letras maiusculas para verifica��es quando � feito um input
string normalizarString(const string& texto) {
    string textoNormalizado = texto;

    // Converter para min�sculas
    transform(textoNormalizado.begin(), textoNormalizado.end(), textoNormalizado.begin(), ::tolower);

    // Substituir letras acentuadas
    for (char& c : textoNormalizado) {
        switch (c) {
        case '�': case '�': case '�': case '�': case '�': c = 'a'; break;
        case '�': case '�': case '�': c = 'e'; break;
        case '�': case '�': case '�': case '�':c = 'i'; break;
        case '�': case '�': case '�': case '�': c = 'o'; break;
        case '�': case '�': case '�': c = 'u'; break;
        case '�': case '�': c = 'c'; break;
        case '�': case '�': case '�': case '�': case '�': c = 'a'; break;
        case '�': case '�': case '�': c = 'e'; break;
        case '�': case '�': case '�': c = 'i'; break;
        case '�': case '�': case '�': case '�': c = 'o'; break;
        case '�': case '�': case '�': c = 'u'; break;
        case '�': c = 'c'; break;
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
    // Valida os n�meros de telefone com 9 d�gitos come�ando com 9
    const regex formatoTelefone(R"(9[1236]\d{7})");
    return regex_match(telefone, formatoTelefone);
}

bool validarNCC(const string& ncc) {
    return ncc.size() == 8 && So_numeros(ncc); //funciona como um ciclo
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

bool AnoBissexto(int ano) {
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

    // Somar os dias dos meses anteriores ao m�s atual
    for (int mes_ = 1; mes_ < mes; mes_++) {
        DiasTotais += DiasNoMes(mes_, ano);
    }

    // Somar os dias dos anos anteriores ao ano atual (assumindo 1500 como refer�ncia)
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

    // Voltar � cor padr�o
    SetConsoleTextAttribute(hConsole, 7); 
    int tecla;
    do {
        tecla = _getch();
    } while (tecla != 13); // Continua at� pressionar o Enter
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

    // �ndices do ecr� (linhas que representam a tela)
    const int screen_start = 5; // Linha inicial do ecr�
    const int screen_end = 9;   // Linha final do ecr�

    for (int cycle = 0; cycle < 3; ++cycle) { // Executa duas vezes
        for (int dot_count = 0; dot_count <= 2; ++dot_count) { // Pontos progressivos
            // Limpar a tela
            std::cout << "\033[2J\033[1;1H";

            // Atualizar a arte com o texto no ecr�
            for (size_t j = 0; j < art.size(); ++j) {
                if (j >= screen_start && j <= screen_end) {
                    if (j == screen_start + 2) { // Linha principal do texto
                        std::cout << "            !.........||||   A encerrar.";
                        for (int d = 0; d < dot_count; ++d) std::cout << ".";
                        for (int s = 0; s < 3 - dot_count; ++s) std::cout << " "; // Adicionar espa�os para manter o alinhamento
                        std::cout << "    ||||" << std::endl;
                    }
                    else {
                        // Outras linhas do ecr�
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
            system("cls");
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
                |  Sim�o  |  |  Joel  |  |  Renato  |  |  Tom�s  |
                \_________/  \________/  \__________/  \_________/
)";*/


void Envelope(int step) {
    system("cls");  // Limpa a tela a cada nova fase
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

void printEnvelope(int offset) {
    // Cria o envelope deslocado horizontalmente
    string spaces(offset, '    '); // Espa�os para o deslocamento
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "                                  \n";
    cout << spaces << "       ?????00000%%%%%&&&&&&&&&&@0\n";
    cout << spaces << "&%%00000?????0???======       =&&0\n";
    cout << spaces << "&&&0                         ?&=0&\n";
    cout << spaces << "@% 0@?                      %0  0&\n";
    cout << spaces << "@%   &&=                  =&=   0&\n";
    cout << spaces << "&%    =&%                %%     ?&\n";
    cout << spaces << "&%      ?&0            =&?      ?&\n";
    cout << spaces << "%%        ?&0   ==?????%&       ?&\n";
    cout << spaces << "0%         ?0???????=?%?        ?&\n";
    cout << spaces << "?&       ??            =0?      ?&\n";
    cout << spaces << "?@     ??                =0?    ?&\n";
    cout << spaces << "?@   ??                    =?=  ?&\n";
    cout << spaces << "=& =?                         ==0%\n";
    cout << spaces << "=&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&0\n";
}

int getScreenWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1; // Retorna a largura do terminal
    }
    return 80; // Retorna 80 como padr�o para se falhar
}

void moverparalado() {
    const int screenWidth = getScreenWidth();  // Largura do terminal em caracteres 
    const int envelopeWidth = 36; // Largura do envelope em caracteres
    const int totalSteps = screenWidth-36; // Total de passos do envelope pra nao deformar

    for (int i = 0; i <= totalSteps; i += 4) {
        system("cls"); 
        printEnvelope(i); 
        Sleep(2);     
    }
}









unsigned long long indiceTesteNome = 0;
unsigned long long indiceTesteed = 0;

string gerarNomesJornais() {
    // Lista de nomes e sobrenomes
    vector<string> livrosEducativos = {
        "Fundamentos da Educa��o e Aprendizagem",
        "Desenvolvimento Cognitivo e Psicologia Infantil",
        "M�todos e T�cnicas de Ensino",
        "Educa��o e Inclus�o: Desafios e Solu��es",
        "Pedagogia do S�culo XXI: Inova��es e Tend�ncias",
        "Pr�ticas Pedag�gicas para o Ensino Fundamental",
        "A Psicologia na Sala de Aula: Teorias e Aplica��es",
        "Educa��o Ambiental: Conscientiza��o e Sustentabilidade",
        "Ensino de Matem�tica: Estrat�gias para o Sucesso Escolar",
        "Alfabetiza��o e Letramento: M�todos e Desafios"
    };
    // Combinar nome e sobrenome
    return livrosEducativos[indiceTesteNome++];
}

string gerar_nome_autor() {
    // Listas de primeiros nomes e sobrenomes
    std::vector<std::string> primeiros_nomes = { "Isabel", "Fernando", "Luana", "Miguel", "Patr�cia", "Rodrigo", "Raquel", "Pedro", "Gabriela", "Ricardo" };
    std::vector<std::string> sobrenomes = { "Gomes", "Martins", "Cardoso", "Vieira", "Campos", "Machado", "Ferreira", "Sousa", "Costa", "Teixeira" };

    // Gerando �ndices aleat�rios para selecionar nomes
    int indice_primeiro_nome = rand() % primeiros_nomes.size();
    int indice_sobrenome = rand() % sobrenomes.size();

    // Montando o nome completo
    return primeiros_nomes[indice_primeiro_nome] + " " + sobrenomes[indice_sobrenome];
}

int gerar_anos() {
    // Gerando ano aleat�rio entre 1950 e 2024
    int ano = rand() % (2024 - 1950 + 1) + 1950;

    // Montando o nome completo com o ano
    return ano;
}



string gerarNumeroAleatorio(int comprimento) {
    string numero;
    for (int i = 0; i < comprimento; ++i) {
        numero += to_string(rand() % 10);
    }
    return numero;
}

// Fun��o para verificar unicidade no vetor
bool verificarUnicidadeISBN(const vector<string>& gerados, const string& ISBN) {
    for (const auto& item : gerados) {
        if (item == ISBN) {
            return false; // ISBN j� gerado
        }
    }
    return true;
}

// Fun��o para verificar unicidade no vetor de ISSNs
bool verificarUnicidadeISSN(const vector<string>& gerados, const string& ISSN) {
    for (const auto& item : gerados) {
        if (item == ISSN) {
            return false; // ISSN j� gerado
        }
    }
    return true;
}

// Fun��o para gerar ISBN �nico
string gerarISBNUnico(vector<string>& geradosISBN) {
    string ISBN;
    do {
        // Formato b�sico de 13 d�gitos: 978-1-23456-7890-X
        string prefixo = "978";         // Prefixo padr�o
        string grupo = gerarNumeroAleatorio(1); // Grupo de 1 d�gito
        string editora = gerarNumeroAleatorio(5); // C�digo da editora
        string publicacao = gerarNumeroAleatorio(3); // C�digo de publica��o
        string digito = to_string(rand() % 10); // D�gito de verifica��o

        ISBN = prefixo + "-" + grupo + "-" + editora + "-" + publicacao + "-" + digito;

    } while (!verificarUnicidadeISBN(geradosISBN, ISBN) || !ValidarISBN(ISBN));

    geradosISBN.push_back(ISBN); // Armazena o ISBN gerado
    return ISBN;
}

// Fun��o para gerar ISSN �nico
string gerarISSNUnico(vector<string>& geradosISSN) {
    string ISSN;
    do {
        // Formato b�sico de 8 d�gitos: 1234-567X
        string parte1 = gerarNumeroAleatorio(4); // Primeira parte
        string parte2 = gerarNumeroAleatorio(3); // Segunda parte
        string digito = to_string(rand() % 10);  // D�gito de verifica��o (ou 'X')

        if (rand() % 2 == 0) {
            digito = "X"; // 50% de chance de ser 'X'
        }

        ISSN = parte1 + "-" + parte2 + digito;

    } while (!verificarUnicidadeISSN(geradosISSN, ISSN) || !ValidarISSN(ISSN));

    geradosISSN.push_back(ISSN); // Armazena o ISSN gerado
    return ISSN;
}

string gerarEDICAO() {
    // Lista de nomes e sobrenomes
    vector<string> ed = { "1 Edi��o","2 Edi��o","3 Edi��o","4 Edi��o","5 Edi��o","6 Edi��o","7 Edi��o","8 Edi��o","9 Edi��o","10 Edi��o" };

    // Combinar nome e sobrenome
    return ed[indiceTesteed++];
}

string gerareditorBoss() {
    // Lista de nomes e sobrenomes
    vector<string> areasDeEstudoCientificas = {
    "Ci�ncias da Educa��o / Psicologia Educacional / Pedagogia",
    "Psicologia / Neuroci�ncias Cognitivas / Desenvolvimento Infantil",
    "Pedagogia / Ci�ncias da Educa��o / Did�tica",
    "Educa��o Inclusiva / Sociologia da Educa��o / Psicologia Educacional",
    "Pedagogia / Tecnologias Educacionais / Inova��es no Ensino",
    "Ci�ncias da Educa��o / Did�tica / Ensino Fundamental",
    "Psicologia Educacional / Psicologia Cognitiva / Neuropsicologia",
    "Ci�ncias Ambientais / Educa��o Ambiental / Ecologia",
    "Matem�tica Educacional / Educa��o Matem�tica / Psicologia Cognitiva",
    "Lingu�stica / Psicologia Cognitiva / Ci�ncias da Linguagem"
    };

    // Combinar nome e sobrenome
    return areasDeEstudoCientificas[indiceTesteNome];
}

string gerar_tipo_dis() {
    // Listas de primeiros nomes e sobrenomes
    vector<string> nomesDePessoas = {
    "Arthur Figueiredo",
    "Lu�sa Oliveira",
    "Pedro Martins",
    "Clara Alves",
    "Felipe Costa",
    "Sofia Pereira",
    "Vin�cius Rocha",
    "Isabela Duarte",
    "Andr� Gomes",
    "Juliana Lima",
    "Rafael Barbosa",
    "Larissa Mendes",
    "Gustavo Silva",
    "Beatriz Castro",
    "Samuel Ribeiro",
    "Fernanda Costa",
    "Ot�vio Souza",
    "Carolina Ferreira",
    "Henrique Pinto",
    "Isabel Santos"
    };

    // Gerando �ndices aleat�rios para selecionar nomes
    int indice_tipo = rand() % nomesDePessoas.size();

    // Montando o nome completo
    return nomesDePessoas[indice_tipo];
}



// Fun��o para retornar a idade recomendada para o livro
int idadeRecomendada(const string& livro) {
    // Definir a idade recomendada com base no t�tulo do livro
    if (livro == "Fundamentos da Educa��o e Aprendizagem" || livro == "M�todos e T�cnicas de Ensino" || livro == "Gest�o Escolar: Lideran�a e Empoderamento") {
        return 18;  // Livros mais t�cnicos, recomendados para adultos ou educadores
    }
    else if (livro == "Desenvolvimento Cognitivo e Psicologia Infantil" || livro == "A Psicologia na Sala de Aula: Teorias e Aplica��es") {
        return 16;  // Livros educativos mais profundos, para maiores de 16 anos ou estudantes de psicologia
    }
    else if (livro == "Educa��o e Inclus�o: Desafios e Solu��es" || livro == "Pedagogia do S�culo XXI: Inova��es e Tend�ncias") {
        return 14;  // Livros para adolescentes ou iniciantes na educa��o
    }
    else if (livro == "Educa��o Ambiental: Conscientiza��o e Sustentabilidade" || livro == "Alfabetiza��o e Letramento: M�todos e Desafios") {
        return 12;  // Livros voltados para adolescentes em fase escolar
    }
    else if (livro == "Ensino de Matem�tica: Estrat�gias para o Sucesso Escolar") {
        return 10;  // Livros focados em ensinar matem�tica, adequados para crian�as mais velhas
    }
    else {
        return 18;  // Default para livros adultos ou especializados
    }
}

