#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    FILE *fp;
    fp = fopen("teste.txt","a");

    if (fp == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    fprintf(fp, "Teste para gravação de mensagem em arquivo");

    printf("Arquivo criado/atualizado com sucesso!\n");
    fclose(fp);
    return 0;
}