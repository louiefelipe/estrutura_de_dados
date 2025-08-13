#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fracao.h"

Fracao CriarFracao(int N, int D){
    Fracao F;
    F.Num = N;
    F.Den = D;
    return F;
}

void exibirFracao(Fracao F){
    printf("%d / %d\n", F.Num, F.Den);
}

int calcularMDC(int A, int B){
    if (A < 0) A = -A;
    if (B < 0) B = -B;

    while ((A % B) != 0){
        int temp = A;
        A = B;
        B = temp % B;
    }
        return(B);
}
Fracao simplificarFracao(Fracao F){
    int MDC = calcularMDC(F.Num, F.Den);
    F.Num = F.Num / MDC;
    F.Den = F.Den / MDC;
    return F;
}

Fracao somarFracoes(Fracao F, Fracao G){
    Fracao Resposta;
    Resposta.Den = F.Den * G.Den;
    Resposta.Num = F.Num * G.Den + G.Num * F.Den;
    Resposta = simplificarFracao(Resposta);
    return Resposta;

}

Fracao subtrairFracoes(Fracao F, Fracao G){
    Fracao Resposta;
    Resposta.Den = F.Den * G.Den;
    Resposta.Num = F.Num * G.Den - G.Num * F.Den;
    Resposta = simplificarFracao(Resposta);
    return Resposta;

}