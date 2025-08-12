#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fracao.h"

int main( ){

    system("cls");

    Fracao F1 = CriarFracao(24, 30);
    F1 = simplificarFracao(F1);
    exibirFracao(F1); 

    Fracao F2 = CriarFracao(-30, 40);
    F2 = simplificarFracao(F2);
    exibirFracao(F2);

    Fracao F3 = CriarFracao(37, 42);
    F3 = simplificarFracao(F3);
    exibirFracao(F3);

    Fracao F4 = CriarFracao(5,6);
    Fracao F5 = CriarFracao(4,9);
    Fracao F6 = somarFracoes(F4, F5);
    exibirFracao(F6);
    Fracao F7 = subtrairFracoes(F4, F5);

    Fracao F8 = CriarFracao (3,4);
    Fracao F9 = CriarFracao (7,9);
    Fracao F10 = CriarFracao (5, 12);

    Fracao temp;
    temp = subtrairFracoes(F8, F9);
    temp = somarFracoes (temp, F10);
    exibirFracao(temp);

    return 0;
}