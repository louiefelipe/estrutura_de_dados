#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int Num;
    int Den;
} Fracao;

void exibirFracao(Fracao F);

int calcularMDC(int A, int B);
Fracao simplificarFracao(Fracao F);
Fracao CriarFracao(int N, int D);
Fracao somarFracoes(Fracao F, Fracao G);
Fracao subtrairFracoes(Fracao F, Fracao G);

//exercicio 3/4 - 7/9 + 5/12
Fracao F8 = CriarFracao(3,4);
Fracao F9 = CriarFracao(7,9);
Fracao F10 = CriarFracao(5,12);



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
    exibirFracao (F7);

    Fracao F8 = CriarFracao (3,4);
    Fracao F9 = CriarFracao (7,9);
    Fracao F10 = CriarFracao (5, 12);

    Fracao temp;
    temp = subtrairFracoes(F8, F9);
    temp = somarFracoes (temp, F10);
    exibirFracao(temp);

    return 0;
}

Fracao CriarFracao(int N, int D){
    Fracao F;
    F.Num = N;
    F.Den = D;
    return F;
}

void exibirFracao(Fracao F){
    printf("%d / %d", F.Num, F.Den);
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

subtrairFracoes(Fracao F, Fracao G){
    Fracao Resposta;
    Resposta.Den = F.Den * G.Den;
    Resposta.Num = F.Num * G.Den - G.Num * F.Den;
    Resposta = simplificarFracao(Resposta);
    return Resposta;

}