#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "expressao.h"

#define PI 3.14159265358979323846

typedef struct {
    float dados[512];
    int topo;
} Pilha;

typedef struct {
    char dados[512][512]; 
    int topo;
} PilhaString;


void empilhar(Pilha * p, float Valor){
    if (p->topo < 511) {
        p->topo++;
        p->dados[p->topo] = Valor;
    }
}

float desempilhar(Pilha * p){
    if (p->topo >= 0) {
        float Aux;
        Aux = p->dados[p->topo];
        p->topo--;
        return Aux;
    }
    return 0.0;
}

void empilharString(PilhaString * p, char * String){
    if (p->topo < 511) {
        p->topo++;
        strncpy(p->dados[p->topo], String, 511);
        p->dados[p->topo][511] = '\0';
    }
}

char * desempilharString(PilhaString * p){
    if (p->topo >= 0) {
        char *aux = p->dados[p->topo]; 
        p->topo--; 
        return aux;
    }
    return NULL;
}

int getPrecedencia(const char *token) {
    if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0) return 1;
    if (strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || strcmp(token, "%") == 0) return 2;
    if (strcmp(token, "^") == 0) return 3;
    
    if (strcmp(token, "sen") == 0 || strcmp(token, "cos") == 0 || 
        strcmp(token, "tg") == 0 || strcmp(token, "log") == 0 || 
        strcmp(token, "raiz") == 0) return 4; 
        
    return 0; // para operandos
}

//infixa para posfixa
char * getFormaPosFixa(char * StrInFixa) {
    static char ResultadoPosFixa[512];
    PilhaString pilha;
    pilha.topo = -1;
    
    char tempStr[512];
    strncpy(tempStr, StrInFixa, 511);
    tempStr[511] = '\0';
    
    char *token = strtok(tempStr, " ");
    ResultadoPosFixa[0] = '\0'; 
    
    char top_op[512];
    
    while (token != NULL) {
        
        if (atof(token) != 0.0 || (strcmp(token, "0") == 0)) { 
            strcat(ResultadoPosFixa, token);
            strcat(ResultadoPosFixa, " ");
        } 
        
        else if (strcmp(token, "(") == 0 || getPrecedencia(token) == 4) {
            empilharString(&pilha, token);
        } 
        
        else if (strcmp(token, ")") == 0) {
            // desempilha até encontrar (
            char *op_ptr;
            while (pilha.topo != -1) {
                op_ptr = desempilharString(&pilha);
                strcpy(top_op, op_ptr);
                
                if (strcmp(top_op, "(") == 0) break; 
                
                strcat(ResultadoPosFixa, top_op);
                strcat(ResultadoPosFixa, " ");
            }
        } 
 
        else { 
            int prec_atual = getPrecedencia(token);
            char *op_ptr;
            
            // enquanto a pilha nao estiver vazia e a precedencia(topo) >= precedencia(token):
            while (pilha.topo != -1) {
                op_ptr = desempilharString(&pilha);
                strcpy(top_op, op_ptr);
                int prec_topo = getPrecedencia(top_op);
                
                if (prec_topo >= prec_atual) {
                    strcat(ResultadoPosFixa, top_op);
                    strcat(ResultadoPosFixa, " ");
                } else {
                    // se a precedência do topo for menor
                    empilharString(&pilha, top_op); 
                    break;
                }
            }
            // empilha o operador atual
            empilharString(&pilha, token);
        }

        token = strtok(NULL, " ");
    }
    
    //desempilha o que sobrou
    while (pilha.topo != -1) {
        desempilharString(&pilha);
        strcat(ResultadoPosFixa, top_op);
        strcat(ResultadoPosFixa, " ");
    }
    
    // remove o espaço extra no final
    int len = strlen(ResultadoPosFixa);
    if (len > 0 && ResultadoPosFixa[len - 1] == ' ') {
        ResultadoPosFixa[len - 1] = '\0';
    }

    return ResultadoPosFixa;
}

//função de cálculo da posfixa
float getValorPosFixa(char * StrPosFixa){
    Pilha p;
    p.topo = -1;
    
    float X, Y;
    
    char tempStr[512];
    strncpy(tempStr, StrPosFixa, 511);
    tempStr[511] = '\0';

    char * token = strtok(tempStr, " ");

    while(token != NULL){
        
        if(strcmp(token, "+") == 0){

            Y = desempilhar(&p); 
            X = desempilhar(&p); 
            empilhar(&p, X + Y);

        } else if(strcmp(token, "-") == 0){
            Y = desempilhar(&p);
            X = desempilhar(&p);
            empilhar(&p, X - Y);

        } else if(strcmp(token, "*") == 0){
            Y = desempilhar(&p);
            X = desempilhar(&p);
            empilhar(&p, X * Y);

        } else if(strcmp(token, "/") == 0){
            Y = desempilhar(&p);
            X = desempilhar(&p);

            if (Y == 0) return NAN;
            empilhar(&p, X / Y);

        } else if(strcmp(token, "^") == 0){
            Y = desempilhar(&p);
            X = desempilhar(&p);
            empilhar(&p, pow(X, Y));

        } else if(strcmp(token, "%") == 0){ 
            Y = desempilhar(&p);
            X = desempilhar(&p);
            empilhar(&p, fmod(X, Y));
        } 

        // funções em graus
        else if(strcmp(token, "sen") == 0){
            X = desempilhar(&p);
            float anguloRad = X * (PI / 180.0);
            empilhar(&p, sin(anguloRad));
        } else if(strcmp(token, "cos") == 0){
            X = desempilhar(&p);
            float anguloRad = X * (PI / 180.0);
            empilhar(&p, cos(anguloRad));
        } else if(strcmp(token, "tg") == 0){
            X = desempilhar(&p);
            float anguloRad = X * (PI / 180.0);
            empilhar(&p, tan(anguloRad));
        } else if(strcmp(token, "log") == 0){
            X = desempilhar(&p);
            empilhar(&p, log10(X));
        } else if(strcmp(token, "raiz") == 0){
            X = desempilhar(&p);
            empilhar(&p, sqrt(X));
        } 
        
        else {
            empilhar(&p, atof(token));
        }

        token = strtok(NULL, " ");
    }
    
    if (p.topo == 0) {
        return desempilhar(&p);
    }
    return NAN; 
}


//função de conversão da posfixa para infixa
static char Resultado[512]; 

char * getFormaInFixa(char * String){
    PilhaString p;
    p.topo = -1;

    char tempStr[512];
    strncpy(tempStr, String, 511);
    tempStr[511] = '\0';
    
    char * token = strtok(tempStr, " ");
    
    char X_str[512], Y_str[512], X_formatado[512], Y_formatado[512];
    char novaExpressao[512];

    while(token != NULL){
     
        if(strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
           strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || 
           strcmp(token, "^") == 0 || strcmp(token, "%") == 0){
            
            // desempilha Y e X
            char *Y_ptr = desempilharString(&p);
            char *X_ptr = desempilharString(&p);

            if (Y_ptr == NULL || X_ptr == NULL) return NULL; 

            // copia para buffers locais 
            strcpy(Y_str, Y_ptr);
            strcpy(X_str, X_ptr);
            
            // formatação baseada no operador
            if (strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
               
                if(strchr(X_str, '+') != NULL || strchr(X_str, '-') != NULL) {
                    sprintf(X_formatado, "(%s)", X_str);
                } else {
                    strcpy(X_formatado, X_str);
                }

                if(strchr(Y_str, '+') != NULL || strchr(Y_str, '-') != NULL) {
                    sprintf(Y_formatado, "(%s)", Y_str);
                } else {
                    strcpy(Y_formatado, Y_str);
                }
                
                sprintf(novaExpressao, "%s%s%s", X_formatado, token, Y_formatado);

            } 
            // para +, -, ^, %
            else {
                sprintf(novaExpressao, "(%s%s%s)", X_str, token, Y_str);
            }

            empilharString(&p, novaExpressao);

        } 
        else if(strcmp(token, "sen") == 0 || strcmp(token, "cos") == 0 || 
                strcmp(token, "tg") == 0 || strcmp(token, "log") == 0 || 
                strcmp(token, "raiz") == 0){
            
            char *X_ptr = desempilharString(&p);
            if (X_ptr == NULL) return NULL; 

            strcpy(X_str, X_ptr);
            
            sprintf(novaExpressao, "%s(%s)", token, X_str);
            empilharString(&p, novaExpressao);

        } 
      
        else {
            empilharString(&p, token);
        }

        token = strtok(NULL, " ");
    }

    char *Res = desempilharString(&p);

    if (Res == NULL) return NULL; 

    strcpy(Resultado, Res);

    //remoçao de parenteses desnecessários
    int len = strlen(Resultado);
    if (len > 0 && Resultado[0] == '(' && Resultado[len - 1] == ')') {
        memmove(Resultado, Resultado + 1, len - 2);
        Resultado[len - 2] = '\0';
    }
    
    return Resultado;
}