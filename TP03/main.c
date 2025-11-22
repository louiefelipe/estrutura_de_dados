#include "expressao.h" // Inclui as definições e protótipos
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Função auxiliar para rodar um único teste, sem exibir os resultados esperados
void run_test_no_expected(int id, const char *posFixa) {
    printf("\n--- Teste %d ---\n", id);
    printf("Expressão Pós-fixa de Entrada: \"%s\"\n", posFixa);

    // 1. Teste de Avaliação (getValorPosFixa)
    // Cria uma cópia da string para evitar modificação por strtok
    char tempPosFixa_Val[512];
    strcpy(tempPosFixa_Val, posFixa);
    
    float valorCalculado = getValorPosFixa(tempPosFixa_Val);
    printf("  [AVALIAÇÃO]: Valor Calculado = %.4f\n", valorCalculado);
    
    // 2. Teste de Conversão (getFormaInFixa)
    // Cria uma cópia da string para evitar modificação por strtok
    char tempPosFixa_Inf[512];
    strcpy(tempPosFixa_Inf, posFixa);
    
    char *inFixaCalculada = getFormaInFixa(tempPosFixa_Inf);

    if (inFixaCalculada != NULL) {
        printf("  [CONVERSÃO]: Infixa Calculada = \"%s\"\n", inFixaCalculada);
        // Se sua função usa malloc, é importante liberar a memória
        // Se ela usa static, não é necessário free
        // Assumindo que você usa malloc ou static para o retorno, manteremos sem free por segurança.
    } else {
        printf("  [CONVERSÃO]: Infixa Calculada = ERRO (Retorno NULL)\n");
    }
}

int main() {
    printf("====================================================\n");
    printf("  TESTE DO AVALIADOR DE EXPRESSÕES NUMÉRICAS\n");
    printf("  Verifique a saída com os resultados da tabela.\n");
    printf("====================================================\n");

    // Os casos de teste da tabela (apenas a notação Pós-fixa é usada):

    // 1: (3+4)*5
    run_test_no_expected(1, "3 4 + 5 *");

    // 2: 7*2+4
    run_test_no_expected(2, "7 2 * 4 +");

    // 3: 8+(5*(2+4))
    run_test_no_expected(3, "8 5 2 4 + * +");

    // 4: (6/2+3)*4
    run_test_no_expected(4, "6 2 / 3 + 4 *");
    
    // 5: 9+(5*(4+8*2))
    run_test_no_expected(5, "9 5 4 8 2 * + * +");

    // 6: log(2+3)/5
    run_test_no_expected(6, "2 3 + log 5 /");

    // 7: (log 10)^3+2
    run_test_no_expected(7, "10 log 3 ^ 2 +");

    // 8: (45+60)*cos(30)
    run_test_no_expected(8, "45 60 + 30 cos *");

    // 9: sen(45)^2+0,5
    run_test_no_expected(9, "0.5 45 sen 2 ^ +");
    
    printf("\n====================================================\n");
    printf("  FIM DOS TESTES.\n");
    printf("====================================================\n");
    
    return 0;
}