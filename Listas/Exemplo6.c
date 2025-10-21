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

//Construir encadeamento (LISTA Circular)

A->Proximo = B;
B->Proximo = C;
C->Proximo = D;
D->Proximo = A;


//Percorrer a lista (visitar todos os nós)

printf("Lista:\n\n");
Item * X = A;

for(int i = 0; ;){
    printf("%X \t %d\n", X, X->Chave);
    if(X == NULL) printf("Final da lista");

}


}