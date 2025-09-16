#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TrocarElemento(int * A, int * B);
int Particao(int * V, int Inf, int Sup);
void QuickSort(int * V, int Inf, int Sup);
void ExibirVetor(int * V, int N);

int main (int argc, char* argv[]){

    int Vetor[] = {3, 6, 4, 5, 1, 7 ,2};
    int Tamanho = sizeof(Vetor) / sizeof(int);
    QuickSort(Vetor, 0, Tamanho - 1);
    ExibirVetor(Vetor, Tamanho);

}

void TrocarElemento(int * A, int * B){
// A e B são ponteiros 
    int temp = *A;
    *A = *B;
    *B = temp;

}

int Particao(int * V, int Inf, int Sup){

    int Pivo = V[(Inf + Sup) / 2];
    int i = Inf;
    int j = Sup;

    while (i <= j){
        while(V[i] < Pivo) i++;
        while(V[j] > Pivo) j--;
        if(i < j){
            TrocarElemento(&V[i], &V[j]);
            i++;
            j--;
        }
    }
    /*for(int p = Inf; p < i; p++) printf("%d\t", V[p]);
    printf("\n[%d]\n", V[i]);
    for (int q = i + 1; q <= Sup; q++) printf("%d\t", V[q]);*/

    return i;
    
}

void QuickSort(int * V, int Inf, int Sup){
    if(Inf < Sup){
        int p = Particao(V, Inf, Sup);
        QuickSort(V, Inf, p - 1);
        QuickSort(V, p, Sup);
    }

}

void ExibirVetor(int * V, int N){
    for(int i = 0; i < N; i++) printf("%d\t", V[i]);
}





