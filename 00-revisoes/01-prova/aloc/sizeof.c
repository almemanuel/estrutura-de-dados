#include<stdio.h>
#include<stdlib.h>

typedef struct z {
    int a;
    int b;
    int c;
} z;

int main() {
    int x;
    double y;
    z n;
    // sizeof calculo o tamanho (em bytes) de um tipo de dado
    printf("%li\n", sizeof(x)); // exit: 4
    printf("%li\n", sizeof(y)); // exit: 8
    printf("%li\n", sizeof(char)); // exit: 1
    printf("%li\n", sizeof(n)); // exit: 12

    int vet[10];
    printf("%li\n", sizeof(vet)); // exit: 40

    // dividindo o espaço o ocupado pelo vetor pelo espaço ocupado por um unico elemento do vetor, temos o número de indice
    printf("%li\n", sizeof(vet) / sizeof(vet[0])); // exit: 10

    return 0;
}