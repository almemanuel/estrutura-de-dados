/***************************************************************************************
Implemente uma função de busca linear, que procura uma pessoa específica em um vetor
de pessoas. A função recebe o nome da pessoa à ser procurada, um vetor de pessoas, e o
tamanho desse vetor. Caso a pessoa seja encontrada, a função deve retornar a posição no
vetor da mesma, caso não seja encontrada a função deve retornar -1. (dica: use strcmp )
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[12];
    int idade;
} Pessoa;

int buscaLinear(const char nome[12], Pessoa vet[], int tam);

int main() {
    Pessoa *x = (Pessoa *) malloc(sizeof(Pessoa) * 4);
    Pessoa *y = (Pessoa *) malloc(sizeof(Pessoa) * 4);
    FILE *fileA = fopen("PessoaA.txt", "r");
    FILE *fileB = fopen("PessoaB.txt", "r");
    int tam = 0;
    while(!feof(fileA)) {
        fscanf(fileA, "%s %i", (x + tam)->nome, &(x + tam)->idade);
        fscanf(fileB, "%s %i", (y + tam)->nome, &(y + tam)->idade);
        tam++;
    }
    int i = 0;
    while(i < tam) {
        printf("Buscando por %s:", (x + i)->nome);
        printf("\t%i\n", buscaLinear((x+i)->nome, y, tam));
        i++;
    }

    fclose(fileA);
    fclose(fileB);

    return 0;
}


int buscaLinear(const char nome[64], Pessoa vet[], int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        if(!strcmp(nome, vet[i].nome)) return i;
    }
    return -1;
}