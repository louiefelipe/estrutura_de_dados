#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipe.h"

Equipe * LerDados (char * NomeArquivo){
    FILE * fp = fopen(NomeArquivo, "r");

    if(fp == NULL){
        printf("ERRO: Não foi possível abrir o arquivo\n");
        exit (ERRO);
    }

    Equipe * X = malloc(20 * sizeof(Equipe));

    int i = 0;
    char Cabecalho[100];

    fscanf(fp, "%s", Cabecalho);

    while (fscanf (fp, "%d;%[^;];%[^;];%d;%d;%d,%d;%d;%d;%d;%d;\n", &X[i].Posicao, &X[i].Estado, &X[i].Nome, &X[i].Pontos, &X[i].Jogos, &X[i].Vitorias, &X[i].Empates, &X[i].Derrotas,&X[i].Gols_pro, &X[i].Gols_cont, &X[i].Saldo_Gols) == 11)
    {
        X[i].Aproveitamento = 100 * (float) X[i].Pontos / (float) (3 * X[i].Jogos);
        printf("%s\t%.2f\n", X[i].Nome, X[i].Aproveitamento);
        i++;
    }
    fclose(fp);
    return X;
}

int getPontos(Equipe *T, int Posicao){

    for(int i = 0; i < 20; i++){
        if(T[i].Posicao == Posicao)
        return T[i].Pontos;
    }
    return ERRO;

float getAproveitamento(Equipe *T, char *Nome){
    for(int i = 0; i < 20; i++){
        if (strcmp(T[i].Nome, Nome)==0)
        return T[i].Aproveitamento;

    return ERRO;  
    }
}

}
        //if (strcmp(T[i].Nome, Nome) == 0)//
