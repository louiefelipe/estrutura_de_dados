#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Equipe.h"

int main(int argc, char* argv){
    Equipe * tabela = LerDados("tabela.csv");

    printf("%d\n", getPontos(tabela, 10));
    printf("%.2f%%\n", getAproveitamento(tabela, "Corinthians"));


    return 0;
}

