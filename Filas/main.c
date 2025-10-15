#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "planner.h"

void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo) {
    // DEBUG 1: Verifica se os ponteiros de entrada são válidos
    if (Lista == NULL || CaminhoArquivo == NULL) {
        fprintf(stderr, "DEBUG 1: Erro! Lista ou Caminho de arquivo eh NULL.\n"); 
        return;
    }

    // DEBUG 2: Verifica se o fopen está sendo tentado
    printf("DEBUG 2: Tentando abrir o arquivo '%s'...\n", CaminhoArquivo);

    FILE *Arq = fopen(CaminhoArquivo, "w");
    if (Arq == NULL) {
        // Se falhar, DEVE mostrar esta mensagem
        perror("ERRO CRITICO (fopen): Falha ao abrir o arquivo para escrita"); 
        return;
    }
    
    // DEBUG 3: Verifica se a abertura foi bem-sucedida
    printf("DEBUG 3: Arquivo aberto com sucesso. Iniciando escrita...\n");

    /* Cabeçalho HTML + CSS embutido */
    fputs(
"<!DOCTYPE html>\n"
"<html lang=\"pt-br\">\n"
"<head>\n"
"   <meta charset=\"utf-8\">\n"
"   <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
"   <title>Lista de Tarefas</title>\n"
"   <style>\n"
"    :root { --borda:#e0e0e0; --cinza:#f8f9fa; --texto:#222; --verde:#d1e7dd; --laranja:#ffe8cc; --azul:#e7f1ff; }\n"
"    body{font-family:system-ui,-apple-system,Segoe UI,Roboto,Ubuntu,'Helvetica Neue',Arial,sans-serif;margin:24px;color:var(--texto);}\n"
"    h1{font-size:22px;margin:0 0 16px;}\n"
"    table{width:100%;border-collapse:collapse;background:#fff;border:1px solid var(--borda);table-layout:fixed;}\n"
"    thead th{background:var(--cinza);text-align:left;font-weight:600;padding:10px;border-bottom:1px solid var(--borda);} \n"
"    td{padding:10px;border-top:1px solid var(--borda);vertical-align:middle;word-wrap:break-word;}\n"
"    .col-titulo{width:45%;}\n"
"    .col-responsavel{width:18%;}\n"
"    .col-status{width:15%;}\n"
"    .col-progresso{width:15%;}\n"
"    .col-avaliacao{width:7%;}\n"
"    .status{display:inline-block;padding:4px 8px;border-radius:8px;font-size:12px;font-weight:600;}\n"
"    .status-afazer{background:var(--azul);}\n"
"    .status-emandamento{background:var(--laranja);}\n"
"    .status-feito{background:var(--verde);}\n"
"    .progresso{width:100%;height:10px;background:#eee;border-radius:6px;overflow:hidden;border:1px solid #ddd;}\n"
"    .progresso-barra{height:100%;background:#2f80ed;}\n"
"    .estrela{font-size:14px;color:#ffb703;}\n"
"    @media (max-width:720px){ .col-titulo{width:100%;} }\n"
"   </style>\n"
"</head>\n"
"<body>\n"
"   <h1>Lista de Tarefas</h1>\n"
"   <table>\n"
"       <thead>\n"
"           <tr>\n"
"               <th style=\"width:5%;\">#</th>\n"
"               <th class=\"col-titulo\">Título</th>\n"
"               <th class=\"col-responsavel\">Responsável</th>\n"
"               <th class=\"col-status\">Status</th>\n"
"               <th class=\"col-progresso\">Progresso</th>\n"
"               <th class=\"col-avaliacao\">Avaliação</th>\n"
"           </tr>\n"
"       </thead>\n"
"       <tbody>\n", Arq);

    /* Percorrer a lista de tarefas e gerar as linhas */
    int i;
    for (i = 0; i < Lista->Tamanho; i++) {
        Tarefa T = Lista->Dados[i];
        int Percentual = (int)(T.Progresso * 100.0f);
        if (Percentual < 0) Percentual = 0;
        if (Percentual > 100) Percentual = 100;

        fprintf(Arq, "           <tr>\n");
        fprintf(Arq, "               <td>%02d</td>\n", i + 1); // Contagem a partir de 1 (mais amigável)

        /* Coluna Título */
        fprintf(Arq, "               <td class=\"col-titulo\">%s</td>\n", T.Titulo);

        /* Coluna Responsável */
        fprintf(Arq, "               <td class=\"col-responsavel\">%s</td>\n", T.Responsavel);

        /* Coluna Status */
        const char *Classe =
            (T.Status == A_FAZER) ? "status-afazer" :
            (T.Status == EM_ANDAMENTO) ? "status-emandamento" :
            (T.Status == CONCLUIDO) ? "status-feito" : "status-desconhecido";

        const char *Texto =
            (T.Status == A_FAZER) ? "A Fazer" :
            (T.Status == EM_ANDAMENTO) ? "Em Andamento" :
            (T.Status == CONCLUIDO) ? "Concluído" : "?";

        fprintf(Arq, "               <td class=\"col-status\"><span class=\"status %s\">%s</span></td>\n",
                Classe, Texto);

        /* Coluna Progresso */
        fprintf(Arq,
                "               <td class=\"col-progresso\">\n"
                "                   <div class=\"progresso\"><div class=\"progresso-barra\" style=\"width:%d%%\"></div></div>\n"
                "               </td>\n", Percentual);

        /* Coluna Avaliação (estrelas) */
        fprintf(Arq, "               <td class=\"col-avaliacao estrela\">");
        int j;
        int Prioridade = T.Prioridade; 
        if (Prioridade < 0) Prioridade = 0;
        if (Prioridade > 5) Prioridade = 5;
        
        for (j = 0; j < Prioridade; j++) fputs("&#9733;", Arq); /* ★ */
        for (; j < 5; j++) fputs("&#9734;", Arq);             /* ☆ */
        fputs("</td>\n", Arq);

        fputs("           </tr>\n", Arq);
    }

    /* Rodapé */
    fputs(
"       </tbody>\n"
"   </table>\n"
"</body>\n"
"</html>\n", Arq);

    fclose(Arq);
}

int main(int argc, char* argv[]){
     Lista * Planner = CriarLista(200); 
    
    // Verificação de segurança
    if (Planner == NULL) {
        printf("ERRO FATAL: Falha ao criar a lista (CriarLista retornou NULL).\n");
        return 1; // Termina o programa
    }

    Tarefa T1 = {"Entrega do relatorio de BD", "Rafael Souza", CONCLUIDO, 1.00, 4};
    Tarefa T2 = {"Revisao do codigo do sistema", "Carlos Henrique", CONCLUIDO, 1.00, 5};
    Tarefa T3 = {"Criacao de mockups para o app", "Juliana Ribeiro", EM_ANDAMENTO, 0.40, 3};
    Tarefa T4 = {"Levantamento de requisitos", "Rafael Souza", A_FAZER, 0.00, 2};
    Tarefa T5 = {"Treinamento da equipe", "Fernanda Lima", EM_ANDAMENTO, 0.60, 4};
    Tarefa T6 = {"Testes automatizados", "Lucas Martins", A_FAZER, 0.00, 5};
    Tarefa T7 = {"Atualizacao da documentacao tecnica", "Mariana Alves", A_FAZER, 0.00, 3};
    Tarefa T8 = {"Integracao com API externa", "Pedro Rocha", EM_ANDAMENTO, 0.50, 4};
    Tarefa T9 = {"Apresentacao para o cliente", "Bianca Torres", CONCLUIDO, 1.00, 5};
    Tarefa T10 = {"Correcao de bugs criticos", "Joao Victor", EM_ANDAMENTO, 0.30, 5};

    AdicionarTarefa(Planner, T1);
    AdicionarTarefa(Planner, T2);
    AdicionarTarefa(Planner, T3);
    AdicionarTarefa(Planner, T4);
    AdicionarTarefa(Planner, T5);
    AdicionarTarefa(Planner, T6);
    AdicionarTarefa(Planner, T7);
    AdicionarTarefa(Planner, T8);
    AdicionarTarefa(Planner, T9);
    AdicionarTarefa(Planner, T10);

    //printf("%d\n", Planner);
    printf("--------Lista de Tarefas----------:\n");
    for(int i = 0; i < Planner->Tamanho; i++){
        printf("%d\t%s\n", i, Planner->Dados[i].Titulo);
    }
    printf("----------------------------------\n");

    //GerarHTMLTabela(Planner, "planner_de_tarefas.html");
   //printf("Arquivo HTML 'planner_de_tarefas.html' gerado com sucesso!\n");
   
   printf("DEBUG: Chamando GerarHTMLTabela...\n"); // Debug para ver se a chamada ocorreu
    GerarHTMLTabela(Planner, "planner_de_tarefas.html");
    printf("--- FIM DA EXECUCAO ---\n");

    DestruirLista(Planner);

    return 0;

    }