#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

Item * criarItem(char * Titulo, char * Autor, int Ano){
    Item * X = (Item *) malloc(sizeof(Item));
    if (X == NULL){
        printf("Erro: nao foi possivel alocar memoria para o Item\n");
    }

    strcpy(X->Titulo, Titulo);
    strcpy(X->Autor, Autor);
    X->Ano = Ano;
    X->Anterior = NULL;
    X->Posterior = NULL;

    return X;
}

void exibirInicio(Lista * L){
    Item * Atual = L->Inicio;
    for(int i = 0; i < L->Tamanho; i++){
        printf("%d\t %s\n", i + 1, Atual->Titulo);
        Atual = Atual->Posterior;
    }

    printf("\n");
}


void exibirFim(Lista * L) {
    Item * Atual = L->Fim;
    for(int i = 0; i < L->Tamanho; i++){
        printf("%d\t %s\n", i + 1, Atual->Titulo);
        Atual = Atual->Anterior;
    }

    printf("\n");
}


void exibirMusicas(Lista * L, int Ano){
    Item * Atual = L->Inicio;
    for(int i = 0; i < L->Tamanho; i++){

    if(Atual->Ano == Ano){
        printf("%d\t %s\n", i + 1, Atual->Titulo);
        }
        Atual = Atual -> Posterior;
    }

    printf("\n");
    
}



