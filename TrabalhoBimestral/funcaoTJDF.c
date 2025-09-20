#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcao.h"

//contar as linhas do arquivo CSV
int ContarLinha(char * arquivo){
    FILE *fp = fopen(arquivo, "r"); 
    if (fp == NULL){
        printf("ERRO: arquivo nao pode ser aberto!\n");
        exit(1); 
    }
    
    // --- 1ª PASSAGEM: contar linhas ---
    int count = 0;
    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp); // pula o cabeçalho
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        count++;
    }
    rewind(fp); // volta ao início
    fclose(fp);
   
    return count; 
}

//função para ler os dados do arquivo de preencher a struct Processo
Processo * lerDados(char * arquivo){
    
    printf("Arquivo a ser aberto: %s\n", arquivo); 
    FILE *fp = fopen(arquivo, "r"); 
    if (fp == NULL){
        printf("ERRO: arquivo nao pode ser aberto!\n");
        exit(1); 
    }
    
    int tamanho = ContarLinha(arquivo);
    printf("Encontradas %d linhas de dados\n", tamanho);

    Processo * x = malloc(tamanho * sizeof(Processo)); 
    memset(x, 0, tamanho * sizeof(Processo));

    char cabecalho[1024]; 
    fgets(cabecalho, sizeof(cabecalho), fp);

    int i = 0;
    char linha[1024];
    
    // Lê linha por linha e depois usa sscanf
    while (fgets(linha, sizeof(linha), fp) != NULL && i < tamanho) {
        // Remove quebras de linha
        linha[strcspn(linha, "\r\n")] = '\0';
        
        // Substitui campos vazios por "0"
        char temp_linha[1024];
        strcpy(temp_linha, linha);
        char *ptr = temp_linha;
        while (*ptr) {
            if (*ptr == ';' && (*(ptr+1) == ';' || *(ptr+1) == '\0')) {
                memmove(ptr + 2, ptr + 1, strlen(ptr + 1) + 1);
                *(ptr + 1) = '0';
            }
            ptr++;
        }
        
        // Usa sscanf para ler
        int result = sscanf(temp_linha, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;%d;%[^;];%d;%d;%d;%d;%d;%d;%d;%d;%[^;];%d;%d;%d;%d;%d;%d;%d;%d",
            &x[i].id_processo, 
            x[i].numero_sigilo, x[i].sigla_grau, x[i].procedimento, 
            x[i].ramo_justica, x[i].sigla_tribunal, &x[i].id_tribunal, 
            &x[i].recurso, &x[i].id_ultimo_oj, x[i].dt_recebimento, 
            &x[i].id_ultima_classe, &x[i].flag_violencia_domestica, 
            &x[i].flag_feminicidio, &x[i].flag_ambiental, &x[i].flag_quilombolas, 
            &x[i].flag_indigenas, &x[i].flag_infancia, &x[i].decisao, 
            x[i].dt_resolvido, &x[i].cnm1, &x[i].primeirasentm1, &x[i].baixm1, 
            &x[i].decm1, &x[i].mpum1, &x[i].julgadom1, &x[i].desm1, &x[i].susm1);
        
        if (result >= 20) {
            i++;
        }
    }
    
    fclose(fp);
    printf("Registros lidos com sucesso: %d\n", i);
    return x;
}
    //função para calcular o percentual de cumprimento Meta1

    double calcularMeta1(Processo * processos, int tamanho){

    long long cnm1_total = 0;
    long long julgadom1_total = 0;
    long long desm1_total = 0;
    long long susm1_total = 0;

    for (int i = 0; i < tamanho; i++){
        cnm1_total += processos[i].cnm1;
        julgadom1_total += processos[i].julgadom1;
        desm1_total += processos[i].desm1;
        susm1_total += processos[i].susm1;
    }

    double denominador = (double)(cnm1_total + desm1_total - susm1_total);

    if (denominador == 0){
        printf("Aviso: Denominador 0. Nao foi possivel calcular\n");
        return 0.0;
    }

    return ((double)julgadom1_total / denominador) * 100.0;

}

    //função para contar o numero de processos de uma flag específica

    int contarPorFlag(Processo * processos, int tamanho, int tipo_flag){
        int contador = 0;
        for (int i = 0; i < tamanho; i++){
            switch (tipo_flag)
            {
            case 1:
                if (processos[i].flag_violencia_domestica == 1) contador++;
                break;

            case 2:
                if (processos[i].flag_feminicidio == 1) contador++;
                break;

            case 3:
                if(processos[i].flag_ambiental == 1) contador++;
                break;

            case 4:
                if(processos[i].flag_indigenas == 1) contador ++;
                break;

            case 5:
                if(processos[i].flag_quilombolas == 1) contador++;
                break;

            case 6:
                if(processos[i].flag_infancia == 1) contador++;
                break;
            }
        }
        return contador;
    }


    //código para gerar o arquivo CSV
    void gerarCSVJulgados(Processo * processos, int tamanho){
    FILE *fp = fopen("processos_julgadosM1.csv", "w");
    if (fp == NULL) {
        printf("ERRO: Nao foi possivel gerar o arquivo de saída.\n");
        exit(1);
    }

    fprintf(fp, "id_processo;numero_sigilo;sigla_grau;procedimento;ramo_justica;sigla_tribunal;id_tribunal;recurso;id_ultimo_oj;dt_recebimento;dt_julgamento;id_ultima_classe;flag_violencia_domestica;flag_feminicidio;flag_ambiental;flag_quilombolas;flag_indigenas;flag_infancia;decisao;dt_resolvido;cnm1;primeirasentm1;baixm1;decm1;mpum1;julgadom1;desm1;susm1\n");

    int contador_julgados = 0;
    for (int i = 0; i < tamanho; i++) {

        //verifica se o processo foi julgado

        if (processos[i].julgadom1 == 1) {

            //escreve a linha do processo no novo arquivo
            fprintf(fp, "%d;%s;%s;%s;%s;%s;%d;%d;%d;%s;%s;%d;%d;%d;%d;%d;%d;%d;%d;%s;%d;%d;%d;%d;%d;%d;%d;%d\n",
                processos[i].id_processo, 
                processos[i].numero_sigilo, processos[i].sigla_grau, processos[i].procedimento, 
                processos[i].ramo_justica, processos[i].sigla_tribunal, processos[i].id_tribunal, 
                processos[i].recurso, processos[i].id_ultimo_oj, processos[i].dt_recebimento, 
                processos[i].dt_julgamento, processos[i].id_ultima_classe, 
                processos[i].flag_violencia_domestica, processos[i].flag_feminicidio, 
                processos[i].flag_ambiental, processos[i].flag_quilombolas, 
                processos[i].flag_indigenas, processos[i].flag_infancia, 
                processos[i].decisao, processos[i].dt_resolvido, processos[i].cnm1, 
                processos[i].primeirasentm1, processos[i].baixm1, processos[i].decm1, 
                processos[i].mpum1, processos[i].julgadom1, processos[i].desm1, 
                processos[i].susm1);
            contador_julgados++;
        }
    }
    
    printf("Arquivo 'processos_julgados.csv' gerado com sucesso. Total de %d processos.\n", contador_julgados);
    fclose(fp);
}


