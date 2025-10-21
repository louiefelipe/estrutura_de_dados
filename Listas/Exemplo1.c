#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    
    int Chave;
    struct Item * Proximo;

} Item;

int main(int argc, char* argv[]){

    Item * I = (Item *) malloc (sizeof(Item));

    I->Chave = 23;
    I->Proximo = NULL;

    printf("Endereco (Hexadecimal): %X\n", I);
    printf("%d\n", I->Chave);
    printf("%d (NULL)\n", I->Proximo);

}