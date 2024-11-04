#include <iostream>
#include <locale>
#include "Biblioteca.h"
#include "Uteis.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    Biblioteca* BIPV = new Biblioteca("Biblioteca Instituto Politécnico de Viseu");
    BIPV->Sistema_Not_atraso();
    system("pause"); system("cls");
    menu_principal();

    return 0;
}
