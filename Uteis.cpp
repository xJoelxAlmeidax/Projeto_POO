#include "Uteis.h"
#include <regex>

const int NUM_TABS = 4; // N�mero de abas

void mostrarMenuTabs(int abaSelecionada, const char* tabs[], int num_tabs) {
    
    for (int i = 0; i < num_tabs; i++) {
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
            cout << " > "; // Destaca a op��o selecionada
        }
        else {
            cout << "   ";
        }
        cout << opcoes[i];
        if (i == opcaoSelecionada) {
            cout << " <" << endl; // Destaca a op��o selecionada
        }
        else {
            cout << endl;
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
    return ncc.size() == 9 && So_numeros(ncc); //funciona como um ciclo
}

bool So_numeros(string num) {
    regex pattern("^[0-9]{1,9}$");
    return regex_match(num, pattern);
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