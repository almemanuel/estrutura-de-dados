/**********************************************************************************************
Implemente a mesma função que a questão acima, mas dessa vez passando os dois
parâmetros (pessoa a e pessoa b) por referência (dica: use a setinha ->, e strcmp)
**********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[64];
    int idade;
} Pessoa;

bool iguais(Pessoa *a, Pessoa *b);

int main() {
    Pessoa x, y;
    FILE *fileA = fopen("PessoaA.txt", "r");
    FILE *fileB = fopen("PessoaB.txt", "r");
    while(!feof(fileA)) {
        fscanf(fileA, "%s %i", x.nome, &x.idade);
        fscanf(fileB, "%s %i", y.nome, &y.idade);
        if(iguais(&x, &y)) {
            printf("IGUAIS\n");
        } else {
            printf("DIFERENTES\n");
        }
    }

    fclose(fileA);
    fclose(fileB);

    return 0;
}


bool iguais(Pessoa *a, Pessoa *b) {
    if(!strcmp(a->nome, b->nome) && a->idade == b->idade) {
        return true;
    } return false;
}