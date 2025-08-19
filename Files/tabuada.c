#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    FILE *fp;
    fp = fopen("tabuada.txt","a");

    if (fp == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    fprintf(fp, "\tTabuada do 7\n");
    for(int i = 1; i <= 10; i++){
        fprintf(fp, "7 x %d = %d\n\n", i, 7*i);
    }

    printf("Arquivo criado/atualizado com sucesso!\n");
    fclose(fp);
    return 0;
}