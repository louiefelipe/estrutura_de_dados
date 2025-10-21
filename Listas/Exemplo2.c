#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    
    int Chave;
    struct Item * Proximo;

} Item;

int main(int argc, char* argv[]){

    Item * A = (Item *) malloc (sizeof(Item));
    Item * B = (Item *) malloc (sizeof(Item));
    Item * C = (Item *) malloc (sizeof(Item));
    Item * D = (Item *) malloc (sizeof(Item));

    A->Chave = 17;
    A->Proximo = NULL;

    B->Chave = 29;
    B->Proximo = NULL;

    C->Chave = 41;
    C->Proximo = NULL;

    D->Chave = 97;
    D->Proximo = NULL;

    printf("\tEndereco (Hexadecimal): %X\n%X\n%X\n%X\n\n", A, B, C, D);
    printf("%d\n%d\n%d\n%d\n\n", A->Chave, B->Chave, C->Chave, D->Chave);
    //printf("%d, %d, %d, %d (NULL)\n\n", A->Proximo, B->Proximo, C->Proximo, D->Proximo);

//Construir encadeamento (LISTA)

A->Proximo = C;
C->Proximo = B;
B->Proximo = D;

printf("%d\n", A->Chave); //17
printf("%d\n", A->Proximo->Chave); //41
printf("%d\n", C->Proximo->Proximo->Chave); //97


}