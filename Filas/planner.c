#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "planner.h"

Lista * CriarLista (int C){
    Lista * L = (Lista *)malloc(sizeof(Lista));

    if(L == NULL){
        fprintf(stderr, "ERRO: Não há memória para a estrutura da lista!");
        return NULL;

    }

    L -> Dados = (Tarefa*)malloc(C * sizeof(Tarefa));

    if(L -> Dados == NULL){
        printf("ERRO: Não há memória para o vetor de tarefas!");
        free(L);
        return NULL;
    }

    L -> Tamanho = 0;
    L -> Capacidade = C;
    
    return L;
}

void DestruirLista(Lista * L){
    if(L == NULL) return;
    free(L -> Dados);
    free(L);
}

void AdicionarTarefa(Lista * L, Tarefa T){
    if (L == NULL){
        printf("ERRO: lista inválida!\n");
        return;
    }   
    
    if(L -> Tamanho == L -> Capacidade){
        printf("ERRO: lista cheia!\n");
        return;
    }

    L -> Dados[L -> Tamanho] = T;
    L -> Tamanho++;
}




