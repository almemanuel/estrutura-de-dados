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
    char nome[64];
    int idade;
} Pessoa;

int buscaLinear(const char nome[64], Pessoa vet[], int tam);

int main() {
    int tam = 0;
    do {
        printf("Informe um tamanho maior que 0: ");
        scanf("%i", &tam);
    } while(tam < 1);
    setbuf(stdin, NULL);

    Pessoa x[tam];
    for(int i = 0; i < tam; i++) {
        printf("Informe o nome: ");
        fgets(x[i].nome, 64, stdin);
        setbuf(stdin, NULL);

        x[i].idade = 0;
        do {
            printf("%sInforme sua idade: ", x[i].nome);
            scanf("%i", &x[i].idade);
        } while(x[i].idade < 1);
        setbuf(stdin, NULL);
    }

    char nome[64];
    printf("Informe o nome que deseja buscar: ");
    fgets(nome, 64, stdin);
    setbuf(stdin, NULL);

    printf("%i\n", buscaLinear(nome, x, tam));

    return 0;
}


int buscaLinear(const char nome[64], Pessoa vet[], int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        if(!strcmp(nome, vet[i].nome)) return i;
    }
    return -1;
}