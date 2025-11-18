#include <stdio.h>
#include <stdlib.h>

typedef struct No{
   
   //arvore de Binaria - 2 filhos
    char Chave;
   
    struct No * Esquerda; //primeiro filho
    struct No * Direita; //seg filho

} No;

No * criarNo(char Chave){
    No * N = (No *) malloc(sizeof(No));
    if (N == NULL){
        printf("Nao ha memoria para o no\n");
        return NULL;
    }

    N->Chave = Chave;
    N->Esquerda = NULL;
    N->Direita = NULL;

    return N;
}

int main(int argc, char* argv[]){

    No * A = criarNo('a');
    No * B = criarNo('b');
    No * C = criarNo('c');
    No * D = criarNo('d');

    A->Esquerda = B;
    A->Direita = C;
    C->Direita = D;

    printf("%c", A->Direita->Direita->Chave);

}


