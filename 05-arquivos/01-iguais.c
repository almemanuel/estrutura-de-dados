/**********************************************************************************************
Implemente uma função “iguais” que compara duas pessoas e retorna se são iguais - ou
seja, seus campos possuem o mesmo valor. Retorne verdadeiro (ou 1) se iguais, e falso (ou 0)
se diferentes. (Lembre-se da função strcmp da string.h que recebe duas strings e retorna um
número menor que 0 se string1 menor que string2; igual a 0 se string1 igual a string2; e maior
que 0 se string1 maior que string2)
**********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[64];
    int idade;
} Pessoa;

bool iguais(Pessoa a, Pessoa b);

int main() {
    Pessoa x, y;
    FILE *fileA = fopen("PessoaA.txt", "r");
    FILE *fileB = fopen("PessoaB.txt", "r");
    while(!feof(fileA)) {
        fscanf(fileA, "%s %i", x.nome, &x.idade);
        fscanf(fileB, "%s %i", y.nome, &y.idade);
        if(iguais(x, y)) {
            printf("IGUAIS\n");
        } else {
            printf("DIFERENTES\n");
        }
    }

    fclose(fileA);
    fclose(fileB);

    return 0;
}


bool iguais(Pessoa a, Pessoa b) {
    if(!strcmp(a.nome, b.nome) && a.idade == b.idade) {
        return true;
    } return false;
}