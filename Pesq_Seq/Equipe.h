#ifndef Equipe_h
#define Equipe_h

#define ERRO -999

typedef struct 
{
    int Posicao;
    int Estado [50];
    int Nome [70];
    int Pontos;
    int Jogos;
    int Vitorias;
    int Empates;
    int Derrotas;
    int Gols_pro;
    int Gols_cont;
    int Saldo_Gols;
    float Aproveitamento;

} Equipe;

Equipe * LerDados (char * NomeArquivo);

int getPontos(Equipe * T, int Posicao);
float getAproveitamento(Equipe * T, char * Nome);

#endif