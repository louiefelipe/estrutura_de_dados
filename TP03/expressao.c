#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "expressao.h"
#define PI 3.14159265358979323846

typedef struct {
    float itens[512];
    int topo;
}topoPilha;

void empilhar(topoPilha * p, float Valor){
    if (p->topo < 511) {
        p->topo++;
        p->itens[p->topo] = Valor;
    }
}

float desempilhar(topoPilha * p){
    if (p->topo >= 0) {
        float valor = p->itens[p->topo];
        p->topo--;
        return valor;
    }
    return 0; // retorna 0 se a pilha estiver vazia
}

typedef struct Node{
    char data[512];
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initStack(Stack *s) {
    s->top = NULL;
}

void push(Stack *s, const char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memoria para novo nó da pilha.\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->data[511] = '\0';
    newNode->next = s->top;
    s->top = newNode;
}
char* pop(Stack *s, char *result) {
    if (s->top == NULL) {
        return NULL; // Pilha vazia
    }
    Node *temp = s->top;
    strcpy(result, temp->data);
    s->top = s->top->next;
    free(temp);
    return result;
}

float getValorPosFixa(char *StrPosFixa){
    topoPilha * pilha = (topoPilha *) malloc (sizeof(topoPilha));
    pilha->topo = -1;
    float a, b;

    char tempStr[512];
    strcpy(tempStr, StrPosFixa);
    tempStr[511] = '\0';

    char * token = strtok(StrPosFixa, " ");

    while(token != NULL){
        if(strcmp(token, "+") == 0){
            float b = desempilhar(pilha);
            float a = desempilhar(pilha);
            float soma = a + b;
            empilhar(pilha, soma);
        }
        else if(strcmp(token, "-") == 0){
            float b = desempilhar(pilha);
            float a = desempilhar(pilha);
            float sub = a - b;
            empilhar(pilha, sub);
        }
        else if(strcmp(token, "*") == 0){
            float b = desempilhar(pilha);
            float a = desempilhar(pilha);
            float multiplicacao = a * b;
            empilhar(pilha, multiplicacao);
        }
        else if(strcmp(token, "/") == 0){
            float b = desempilhar(pilha);
            float a = desempilhar(pilha);
            if (b == 0.0) return NAN;
            empilhar(pilha, a / b);
        }
        else if(strcmp(token, "^") == 0){
            float b = desempilhar(pilha);
            float a = desempilhar(pilha);
            float potencia = pow(a, b);
            empilhar(pilha, potencia);
        }
        else if(strcmp(token, "%") == 0){
            float b = desempilhar(pilha);
            float a = desempilhar(pilha);
            float resto = fmod(a, b);
            empilhar(pilha, resto);
        }
        else if(strcmp(token, "raiz") == 0){
            float a = desempilhar(pilha);
            float raiz = sqrt(a);
            empilhar(pilha, raiz);
        }
        else if(strcmp(token, "log") == 0){
            float a = desempilhar(pilha);
            float logaritmo = log10(a);
            empilhar(pilha, logaritmo);
        }
        else if(strcmp(token, "sen") == 0){
            float a = desempilhar(pilha);
            float angulo = a *(PI / 180.0);
            float seno = sin(angulo);
            empilhar(pilha, seno);
        }
        else if(strcmp(token, "cos") == 0){
            float a = desempilhar(pilha);
            float angulo = a *(PI / 180.0);
            float cosseno = cos(angulo);
            empilhar(pilha, cosseno);
        }
        else if(strcmp(token, "tg") == 0){
            float a = desempilhar(pilha);
            float angulo = a *(PI / 180.0);
            float tangente = tan(angulo);
            empilhar(pilha, tangente);
        }

        else{
            empilhar(pilha, atof(token));
        }
        token = strtok(NULL, " ");
    }

    float resultado = desempilhar(pilha);
    free(pilha);
    return resultado;
}


char getFormaInfixa(char * Str){
    static char resultInfixa[512]; 
    Stack s;
    p.top = -1;

    char * token = strtok(Str, " ");

    while (token != NULL){
        if (strcmp(token))
    }
}


