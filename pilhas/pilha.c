#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Item * criarItem(int Chave){
    Item * i = (Item *) malloc(sizeof(Item));
    if (i == NULL) {
        printf("ERRO: erro de memoria\n");
        return NULL;
    }

    P->Tamanho = 0;
    P->Topo = NULL;

    return P;

}

