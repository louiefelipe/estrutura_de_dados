#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int Num;
    int Den;
} Fracao;


int calcularMDC(int A, int B);
Fracao simplificarFracao(Fracao F);
Fracao CriarFracao(int N, int D);
int somarFracoes(Fracao F, Fracao G);

void exibirFracao(Fracao F);

int main( ){

    system("cls");

    printf("%d", calcularMDC(24,30));

    return 0;
}

Fracao CriarFracao(int N, int D){
    Fracao F;
    F.Num = N;
    F.Den = D;
    return F;
}

void exibirFracao(Fracao F){
    printf("%d" / "%d\n", F.Num, F.Den);
    return F;
}

int calcularMDC(int A, int B){
    if (A < 0) A = -A;
    if (B < 0) B = -B;

    while (A % B != 0){
        int temp = A;
        A = B;
        B = temp % B;
        return(B);
    }
}
Fracao simplificarFracao(Fracao F){
    int MDC = calcularMDC(F.Num, F.Den);
    F.Num = F.Num / MDC;
    F.Den = F.Den / MDC;
    return F;
}

somarFracoes(Fracao F, Fracao G){
    Fracao Resposta;
    Resposta.Den = F.Den * G.Den;
    Resposta.Num = F.Num * G.Den + G.Num * F.Den;
    Resposta = simplificarFracao(Resposta);
    return Resposta;

}

