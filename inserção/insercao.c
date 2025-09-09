#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 50000

//Protótipos
void InsertionSort(int * V, int N);
void ExibirVetor(int * V, int N);

//Principal
int main(int argc, char* argv[]){
    int Conjunto[TAMANHO]; //= {1, 9, 7, 8, 5, 2, 0, 15, -2, 4};
    for(int i = 0; i < TAMANHO; i++) Conjunto[i] = rand() % 1000;

    clock_t T0 = clock();
    InsertionSort(Conjunto, TAMANHO);
    clock_t TF = clock();

    //int Tamanho = sizeof(Conjunto) / sizeof(int);
    //InsertionSort(Conjunto, TAMANHO);
    ExibirVetor(Conjunto, TAMANHO);

    printf("Tempo de CPU %f\n", (double)(TF - T0) / CLOCKS_PER_SEC);


    //printf("\nVetor ordenado:\n");
    //ExibirVetor(Conjunto, Tamanho);

return 0;
}


//Implementação das Funções
void InsertionSort(int * V, int N){
    int Chave; // Elemento que será inserido na parte ordenada
    int i; // Posição (ou coordenada) do elemento chave
    int j; // posição de elemento da "parte ordenada" que será comparada com Chave

    for(i = 1; i < N; i++){
        Chave = V[i];
        j = i - 1;

        while (j >= 0 && V[j] > Chave){
            V[j + 1] = V[j];
            j--;
        }

        V[j + 1] = Chave; //Copiando o Chave no último lugar modificado       

    }

}

void ExibirVetor(int * V, int N){

    int i;
    for(i = 0; i < N; i++)printf("%d\t", V[i]);
    printf("\n");

}