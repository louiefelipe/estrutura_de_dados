#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "cidade.h"

int main(int argc, char const *argv[]){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    const char *arquivo = "teste03.txt"; // nome do arquivo de entrada

    //Carregar os dados da estrada
    Estrada *e = getEstrada(arquivo);

    if (e == NULL) {
        printf("Erro ao carregar dados da estrada.\n");
        return 1;
    }

    printf("\n----------------------------\n");
    printf("\tInformações da Estrada\n");
    printf("----------------------------\n\n");
    printf("Tamanho total (T): %d\n", e->T);
    printf("Número de cidades (N): %d\n\n", e->N);

    //Exibir as cidades lidas
    printf("\tLista de Cidades:\n\n");
    Cidade *atual = e->Inicio;

    while (atual != NULL) {
        printf("Cidade: %-20s | Posição: %d\n", atual->Nome, atual->Posicao);
        atual = atual->Proximo;
    }

    return 0;
}