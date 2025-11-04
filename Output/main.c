#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

int main(int argc, char* argv[]){


    Item * D = criarItem("Forrest Gump","Frank Ocean", 2012);
    Item * E = criarItem("Breeze!", "Kali Uchis", 2025);
    Item * F = criarItem("Dark Red", "Steve Lacy", 2017);
    Item * G = criarItem("Let me Go", "Daniel Caesar", 2023);
    Item * H = criarItem("High and Dry", "Radiohead", 1995);

    D->Anterior = NULL;
    D->Posterior = E;

    E->Anterior = D;
    E->Posterior = F;

    F->Anterior = E;
    F->Posterior = G;

    G->Anterior = F;
    G->Posterior = H;
    
    H->Anterior = G;
    H->Posterior = NULL;

     /* Item * Atual = E;
    Atual = Atual->Posterior;
    Atual = Atual->Posterior;
    Atual = Atual->Posterior;
    Atual = Atual->Anterior;

    printf("%s\n", Atual->Titulo);*/


    //Criando uma Lista
    Lista * Playlist = (Lista*) malloc(sizeof(Lista));
    if(Playlist == NULL){
        exit(1);
    }

    Playlist->Tamanho = 5;
    Playlist->Inicio = D;
    Playlist->Fim = H;

    exibirInicio(Playlist);
    exibirFim(Playlist);
    exibirMusicas(Playlist, 2012);

}