#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "expressao.h"
#define PI 3.14159265358979323846

typedef struct {
    float itens[512];
    int topo;
} topoPilha;

typedef struct{
    char itens[512][512];
    int topo;
} stackString;

void empilharString(topoPilha * p, float Valor){
   p->topo++;
    p->itens[p->topo] = Valor;
}

float unstack(topoPilha * p){
    float aux;
    aux = p->itens[p->topo];
    p->topo--;
    return aux;
}

float getValorPosFixa(char * StrPosFixa){
    topoPilha p;
    p.topo = -1;

    char * token = strtok(StrPosFixa, " ");

    while(token != NULL){
        if(strcmp(token, "+") == 0){
            float b = unstack(&p);
            float a = unstack(&p);
            float adicao = a + b;
            empilharString(&p, adicao);
        }

        else if(strcmp(token, "-") == 0){
            float b = unstack(&p);
            float a = unstack(&p);
            float sub = a - b;
            empilharString(&p, sub);
        }

        else if(strcmp(token, "*") == 0){
            float b = unstack(&p);
            float a = unstack(&p);
            float prod = a * b;
            empilharString(&p, prod);
        }

        else if(strcmp(token, "/") == 0){
            float b = unstack(&p);
            float a = unstack(&p);
            float div = a / b;
            empilharString(&p, div);
    }
        else if (strcmp(token, "^") == 0){
            float b = unstack(&p);
            float a = unstack(&p);
            float potencia = pow(a, b);
            empilharString(&p, potencia);
        }
        else if(strcmp(token, "raiz") == 0){
            float a = unstack(&p);
            float raiz = sqrt(a);
            empilharString(&p, raiz);
        }
        else if (strcmp(token, "sen") == 0){
            float a = unstack(&p);
            float seno = sin(a * (PI / 180.0));
            empilharString(&p, seno);
        }
        else if (strcmp(token, "cos") == 0){
            float a = unstack(&p);
            float cosseno = cos(a * (PI / 180.0));
            empilharString(&p, cosseno);
        }
        else if (strcmp(token, "log") == 0){
            float a = unstack(&p);
            float logaritmo = log10(a);
            empilharString(&p, logaritmo);
        }
        else {
            float num = atof(token);
            empilharString(&p, num);
        }
        token = strtok(NULL, " ");
}
    return unstack(&p);
}

void empilharString(stackString *p, char * Strng){
    p->topo++;
    strcpy(p->itens[p->topo], Strng);
}

char * unstackString(stackString *p){
    char * aux = (char *)malloc(512 * sizeof(char));
    strcpy(aux, p->itens[p->topo]);
    p->topo--;
    return aux;
}

char * getFormaInFixa(char * Strng){
    static char Resultado[512];
    stackString p;
    p.topo = -1;

    char * token = strtok(Strng, " ");

    while(token != NULL){
        if(strcmp(token, "+") == 0){
            char * b = unstackString(&p);
            char * a = unstackString(&p);
            char novaExpressao [512];
            sprintf(novaExpressao, "(%s+%s)", a, b);
            empilharString(&p, novaExpressao);
        }
        else if (strcmp(token, "-") == 0){
            char * b = unstackString(&p);
            char * a = unstackString(&p);
            char novaExpressao [512];
            sprintf(novaExpressao, "(%s-%s)", a, b);
            empilharString(&p, novaExpressao);
        }
        else if (strcmp(token, "*") == 0){
            char * b = unstackString(&p);
            char * a = unstackString(&p);
            char novaExpressao[512];
            sprintf(novaExpressao, "(%s*%s)", a, b);
            empilharString(&p, novaExpressao);
        }
        else if (strcmp(token, "/") == 0){
            char * b = unstackString(&p);
            char * a = unstackString(&p);
            char novaExpressao[512];
            sprintf(novaExpressao, "(%s/%s)", a, b);
            empilharString(&p, novaExpressao);
        }
        else if (strcmp(token, "^") == 0){
            char * b = unstackString(&p);
            char * a = unstackString(&p);
            char novaExpressao[512];
            sprintf(novaExpressao, "(%s^%s)", a, b);
            empilharString(&p, novaExpressao);
    }
}
}