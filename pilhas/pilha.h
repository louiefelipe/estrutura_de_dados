#ifndef PILHA_H
#define PILHA_H

typedef struct Item{
    int Chave;
    struct Item * Anterior;
    
} Item;

Item * criarItem(int Chave);

#endif