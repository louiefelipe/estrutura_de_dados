#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Nome[150]; // Gasta 150 + 1 ("\0") = 151 caracteres
    char Telefone[14]; // 15 caracteres
    char Endereco[200]; //201 caracteres

}Pessoa;

int main(int argc, char* argv[]){
    Pessoa X;
    
    strcpy(X.Nome, "Maria Alves");
    strcpy(X.Telefone, "(61) 12345-6789");
    strcpy(X.Endereco, "(SHIS 12 25 13");

    printf("%s\t\n\t\n%s\n%s", X.Nome, X.Telefone, X.Endereco);
return 0;
}
