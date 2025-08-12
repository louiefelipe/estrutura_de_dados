#ifndef FRACAO_H
#define FRACAO_H

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

#endif