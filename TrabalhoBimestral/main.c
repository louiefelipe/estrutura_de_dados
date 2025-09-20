#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "funcao.h"

int main(int argc, char const *argv[]){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Processo * pro = lerDados("TJDFT_amostra.csv");
    int tamanho = ContarLinha("TJDFT_amostra.csv"); 
    
    //exibir informações básicas dos processos
    for (int i = 0; i < tamanho; i++) {
        printf("%d\t%s\t%s\n", pro[i].id_processo, pro[i].sigla_grau, pro[i].procedimento);
    }
        printf("----------------------------\n");

    //exibir cumprimento Meta1
    double cumprimento_meta1 = calcularMeta1(pro, tamanho);
    printf("\tRelatório de Metas\n");
    printf("Cumprimento da Meta 1: %.2f%%\n");
    printf("--------------------------\n");

    //exibir contagens de processos por tipo de causa
    printf("\tContagem por Causa\n");
    printf("Violência Doméstica: %d\n", contarPorFlag(pro, tamanho, 1));
    printf("Feminicídio: %d\n", contarPorFlag(pro, tamanho, 2));
    printf("Ambiental: %d\n", contarPorFlag(pro, tamanho, 3));
    printf("Indígena: %d\n", contarPorFlag(pro, tamanho, 4));
    printf("Quilombolas: %d\n", contarPorFlag(pro, tamanho, 5));
    printf("Infância: %d\n", contarPorFlag(pro, tamanho, 6));

    //exibir tempo entre cada processo resolvido
    printf("\tTempo de Resolução do Processo\n");
    for (int i = 0; i < tamanho; i++){ int dias = calcularDias(pro[i].dt_recebimento, pro[i].dt_resolvido);
        if (dias >= 0) {
        printf("Processo %d: %d dias\n", pro[i].id_processo, dias);
    }
}
        printf("--------------------------\n");
        
        gerarCSVJulgados(pro, tamanho);
    
    free(pro);
    return 0;
}
