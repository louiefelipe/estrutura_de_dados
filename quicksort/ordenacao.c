#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TrocarElemento(int * A, int * B);

int main (int argc, char* argv[]){
    int X = 25;
    int Y = 37;
    TrocarElemento(&X, &Y);
   printf("%d \t %d \n", X, Y); 


}

void TrocarElemento(int * A, int * B){
// A e B são ponteiros 
    int temp = *A;
    *A = *B;
    *B = temp;

}

