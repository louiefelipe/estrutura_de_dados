#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 200000

int main(int argc, char* argv){

    int soma = 0;
    srand(time(NULL));

    for(int i = 0; i < TAMANHO; i++){
        int temp = rand()%1000;
        printf("%d\n", temp);
        soma = soma + temp;
    }
    
    clock_t TF = clock();
    
    //double TempoCPU = ((double) (TF - T0)) / CLOCKS_PER_SEC;
   // printf("Tempo de CPU: %.3f segundos\n", TempoCPU);//
    printf("Soma: %d\n", soma);


    //rand(); gera um número pseudo-aleatório
    
    return 0;
}