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
    Pessoa x[2];
    for(int i = 0; i < 2; i++) {
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

    if(iguais(&x[0], &x[1])) {
        printf("IGUAIS\n");
    } else {
        printf("DIFERENTES\n");
    }

    return 0;
}


bool iguais(Pessoa *a, Pessoa *b) {
    if(!strcmp(a->nome, b->nome) && a->idade == b->idade) {
        return true;
    } return false;
}