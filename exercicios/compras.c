#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    FILE *fp;
    fp = fopen("nota_fiscal.txt","a");

    if (fp == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    
    
    printf("Arquivo criado/atualizado com sucesso!\n");
    fclose(fp);
    return 0;
}