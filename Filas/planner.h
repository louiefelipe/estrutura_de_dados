#ifndef PLANNER_H
#define PLANNER_H

#define TAM_TITULO 100
#define TAM_NOME 50

#define A_FAZER 0
#define EM_ANDAMENTO 1
#define CONCLUIDO 2

//typedef enum{A_FAZER, EM_ANDAMENTO, CONCLUIDO} TipoStatus;

//DEFININDO A ESTRUTURA DE ELEMENTOS DE UMA LISTA
typedef struct{

    char Titulo[TAM_TITULO], Responsavel[TAM_NOME];
    int Status;
    float Progresso;
    int Prioridade;

} Tarefa;


//DEFININDO A ESTRUTURA DA LISTA DE TAREFAS
typedef struct {
    Tarefa * Dados;
    int Capacidade;
    int Tamanho;
    
} Lista;

Lista * CriarLista(int C);
void DestruirLista(Lista * L);
void AdicionarTarefa(Lista * L, Tarefa T);
void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo);

#endif
