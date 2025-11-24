#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "expressao.h"

void run_testes(int id, const char *posFixa) {
    printf("\n--- testes %d ---\n", id);
    printf("Expressao POSFIXA de entrada: \"%s\"\n", posFixa);

    char tempPosFixa_Val[512];
    strcpy(tempPosFixa_Val, posFixa);
    
    float valorCalc = getValorPosFixa(tempPosFixa_Val);
    printf("Valor calculado = %.4f\n", valorCalc);
  
    char tempPosFixa_Inf[512];
    strcpy(tempPosFixa_Inf, posFixa);
    
    char *inFixaCalc = getFormaInFixa(tempPosFixa_Inf);

    if (inFixaCalc != NULL) {
        printf("Conversao: INFIXA calculada = \"%s\"\n", inFixaCalc);
       
    } else {
        printf("Conversao: INFIXA Calculada = ERRO (Retorno NULL)\n");
    }
}

int main() {
    printf("----------------------------------------------------\n");
    printf("  TESTES CALCULOS DE EXPRESSOES POSFIXAS E INFIXAS\n");
    printf("----------------------------------------------------\n");
    
    //testes do pdf
    run_testes(1, "3 4 + 5 *");
    run_testes(2, "7 2 * 4 +");
    run_testes(3, "8 5 2 4 + * +");
    run_testes(4, "6 2 / 3 + 4 *");
    run_testes(5, "9 5 4 8 2 * + * +");
    run_testes(6, "2 3 + log 5 /");
    run_testes(7, "10 log 3 ^ 2 +");
    run_testes(8, "45 60 + 30 cos *");
    run_testes(9, "0.5 45 sen 2 ^ +");

    //outros testes
    run_testes(10, "16 raiz 2 / 3 +");
    run_testes(11, "90 sen 2 ^ 3 4 * +");
    run_testes(12, "5 0 /"); //divisao por zero
    run_testes(13, "2 3 ^ 4 5 * +");
    run_testes(14, "100 3 % 5 + 2 ^");
    
    printf("\n---------------------------------------------------\n");
    printf("fim de testes\n");
    printf("----------------------------------------------------\n");
    
    return 0;
}