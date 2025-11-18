#include <stdio.h>
#include <stdlib.h>

typedef struct No{
   
   //arvore de Binaria - 2 filhos
    char Chave;
   
    struct No * Esquerda; //primeiro filho
    struct No * Direita; //seg filho

} No;

No * criarNo(int Chave){
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

int contarNos(No * N){
    if (N == NULL) return 0;
    return 1 + contarNos(N->Direita) + contarNos(N->Esquerda);
}

int main(int argc, char* argv[]){

    //nivel 1
    No * Raiz = criarNo(10);

    //nivel 2
    Raiz->Esquerda = criarNo(12);
    Raiz->Direita = criarNo(15);
    
    //nivel 3
    Raiz->Esquerda->Esquerda = criarNo(16);
    Raiz->Esquerda->Direita = criarNo(18);

    Raiz->Direita->Direita = criarNo(20);

    //nivel 4
    Raiz->Direita->Direita->Esquerda = criarNo(17);
    Raiz->Direita->Direita->Direita = criarNo(19);

    printf("%d\n", Raiz->Direita->Direita->Direita->Chave);
    printf("%d\n", Raiz->Direita->Direita->Esquerda->Chave);
    printf("Nos encontrados: %d\n", contarNos);

}


