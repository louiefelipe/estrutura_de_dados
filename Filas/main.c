#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "planner.h"

int main(int argc, char* argv[]){

    Tarefa T1 = {"Entrega do relatório de BD", "Rafael Souza", CONCLUIDO, 1.00, 4};
    Tarefa T2 = {"Revisão do código do sistema", "Carlos Henrique", CONCLUIDO, 1.00, 5};
    Tarefa T3 = {"Criação de mockups para o app", "Juliana Ribeiro", EM_ANDAMENTO, 0.40, 3};
    Tarefa T4 = {"Levantamento de requisitos", "Rafael Souza", A_FAZER, 0.00, 2};
    Tarefa T5 = {"Treinamento da equipe", "Fernanda Lima", EM_ANDAMENTO, 0.60, 4};
    Tarefa T6 = {"Testes automatizados", "Lucas Martins", A_FAZER, 0.00, 5};
    Tarefa T7 = {"Atualização da documentação técnica", "Mariana Alves", A_FAZER, 0.00, 3};
    Tarefa T8 = {"Integração com API externa", "Pedro Rocha", EM_ANDAMENTO, 0.50, 4};
    Tarefa T9 = {"Apresentação para o cliente", "Bianca Torres", CONCLUIDO, 1.00, 5};
    Tarefa T10 = {"Correção de bugs críticos", "João Victor", EM_ANDAMENTO, 0.30, 5};

    Lista * Planner = CriarLista(200);
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
    for(int i = 0; i < Planner->Tamanho; i++){
        printf("%d\t%s\n", i, Planner->Dados[i].Titulo);
    }


}