#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cidade.h"

/*
RESTRIÇÕES 
    • 3 ≤ T ≤ 106 e 2 ≤ N ≤ 104
    • 0 < Xi < T, para 1 ≤ i ≤ N
    • Xi ≠ Xj, para todo par 1 ≤ i, j ≤ N.
*/

/*
OBSERVAÇÕES 
    - caso ocorra erro na inicialização, da estrada em Estrada *getEstrada(const char *nomeArquivo), esta deverá retornar ponteiro NULL.
    -  construa outros para verificar se sua solução para o problema proposto realmente está correta, observando os limites mínimos e
       máximos para cada variável.
    

*/


//funcao pra auxiliar no get estrada
Cidade *criarCidade(int posicao, const char *nome) {
    Cidade * novaCidade = (Cidade*) malloc(sizeof(Cidade));
    
    if (novaCidade == NULL){
        return NULL;  
    } 
    
    strcpy(novaCidade->Nome, nome);
    novaCidade->Posicao = posicao;
    novaCidade->Proximo = NULL;
    
    return novaCidade;
}



Estrada * getEstrada(const char * nomeArquivo){
    printf("Arquivo a ser aberto: %s\n", nomeArquivo); 
    FILE *fp = fopen(nomeArquivo, "r"); 
    
    if (fp == NULL){
        printf("ERRO: arquivo nao pode ser aberto!\n");
        exit(1); 
    }
    
    int N, T;
    if (fscanf(fp, "%d", &T) != 1 || fscanf(fp, "%d", &N) != 1) {
        printf("ERRO: formato incorreto na leitura de T ou N.\n");
        fclose(fp);
        return NULL;
    }

    /*if (T < 3 || T > 1000000 || N < 2 || N > 10000) {
        fclose(fp);
        return NULL;
    }*/

    // validar restrições
    if (T < 3 || T > 1000000) {
        printf("ERRO: valor de T (%d) inválido. Deve estar entre 3 e 1000000.\n", T);
        fclose(fp);
        return NULL;
    }
    if (N < 2 || N > 10000) {
        printf("ERRO: número de cidades (%d) inválido. Deve estar entre 2 e 10000.\n", N);
        fclose(fp);
        return NULL;
    }


    //alocação dinamica de memoria 
    Estrada * x = (Estrada*) malloc(sizeof(Estrada)); 
    if (x == NULL){
        exit(1); 
    }
    
    x->T = T;
    x->N = N;
    x->Inicio = NULL;

    // Ler as cidades
    Cidade *anterior = NULL;
    int posicoes[N];
    char nomes[N][256];
    int count = 0;


    // leitura das cidades
    for (int i = 0; i < N; i++) {
        int pos;
        char nome[256];

        // lê número e nome (nome pode ter espaços)
        if (fscanf(fp, "%d", &pos) != 1) {
            fclose(fp);
            free(x);
            return NULL;
        }

        // consome espaço antes do nome
        fgetc(fp);

        if (fgets(nome, sizeof(nome), fp) == NULL) {
            printf("ERRO: falha na leitura do nome da cidade %d.\n", i + 1);
            fclose(fp);
            free(x);
            return NULL;
        }

        // remove \n do final
        nome[strcspn(nome, "\n")] = 0;


        // validar posição
        if (pos <= 0 || pos >= T) {
            printf("ERRO: posição inválida (%d) para a cidade '%s'. Deve estar entre > 0 e < T (%d).\n", pos, nome, T);
            fclose(fp);
            free(x);
            return NULL;
        }

        // verificar duplicata
        for (int j = 0; j < count; j++) {
            if (posicoes[j] == pos) {
                printf("ERRO: posição duplicada (%d) detectada na cidade '%s'.\n", pos, nome);
                fclose(fp);
                free(x);
                return NULL;
            }
        }


        posicoes[count++] = pos;
        strcpy(nomes[count], nome);
        count++;


        Cidade *nova = criarCidade(pos, nome);
        
        if (nova == NULL) {
            printf("ERRO: falha ao alocar memória para cidade '%s'.\n", nome);
            fclose(fp);
            free(x);
            return NULL;
        }

        if (x->Inicio == NULL)
            x->Inicio = nova;
        else
            anterior->Proximo = nova;

        anterior = nova;
    }

    fclose(fp);
    printf("Arquivo lido com sucesso. %d cidades carregadas.\n", N);
    return x;

}



double calcularMenorVizinhanca(const char * nomeArquivo){


}


char * cidadeMenorVizinhanca(const char * nomeArquivo){


}
