#include <stdio.h>
#include <stdlib.h>

typedef struct No{
   
   //arvore de 3 graus
    char Chave;
   
    struct No * F1; //primeiro filho
    struct No * F2; //seg filho
    struct No * F3; //terc filho
    
    //outra possibilidade

    struct No * F[3];

} No;

No * criarNo(char Chave){
    No * N = (No *) malloc(sizeof(No));
    if (N == NULL){
        printf("Nao ha memoria para o no\n");
        return NULL;
    }

    N->Chave = Chave;
    N->F1 = NULL;
    N->F2 = NULL;
    N->F3 = NULL;

    for(int i = 0; i < 3; i++) N->F[i] = NULL;
    return N;
}


