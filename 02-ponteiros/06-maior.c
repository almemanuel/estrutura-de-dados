/**********************************************************************************************
Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2
valores de entrada e retorne o maior valor entre eles. No programa principal apresente o maior
e também o conteúdo das 2 variáveis na tela
**********************************************************************************************/
#include <stdio.h>

int *maior(int *x, int *y);

int main() {
    int x, y;
    printf("Informe dois valores inteiros: ");
    scanf("%i %i", &x, &y);

    int *max = maior(&x, &y);

    printf("%i %i %i", *max, x, y);

    return 0;
}

int *maior(int *x, int *y) {
    if(*x > *y) {
        return x;
    }
    return y;
}