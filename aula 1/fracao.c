#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Numerador;
    int Denominador;
}Fracao;

Fracao criarFracao(int N, int D){
    Fracao F;
    F.Numerador = N;
    F.Denominador = D;

    return F;
}



int main(int argc, char* argv[]){
Fracao F1 = criarFracao(7, 2);
printf("O valor de F1 eh: %.2f\n", (float)F1.Numerador/F1.Denominador);


    return 0;
}