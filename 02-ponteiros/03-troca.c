/*********************************************************************************************
Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2
variáveis e troque o seu conteúdo, ou seja, esta função é chamada passando duas variáveis A e
B por exemplo e, após a execução da função, A conterá o valor de B e B terá o valor de A.
Entrada 1 : 6 8
SAIDA 1 : PA = 8, PB = 6
*********************************************************************************************/
#include <stdio.h>

void troca(int *A, int *B);

int main() {
    int A, B;
    printf("Informe o valor de A e B: ");
    scanf("%i %i", &A, &B);
    troca(&A, &B);
    printf("PA = %i, PB = %i", A, B);
    return 0;
}

void troca(int *A, int *B) {
    int aux = *A;
    *A = *B;
    *B = aux;
}