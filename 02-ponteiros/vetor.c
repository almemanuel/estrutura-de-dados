/****************************************************************************************
Faça um programa que declare um vetor v contendo os inteiros 1,2 e 3. Imprima os valores.
****************************************************************************************/

#include<stdio.h>

int main() {
    int v[3] = {1, 2, 3};

    int i = 0;
    for(i = 0; i < sizeof(v) / sizeof(v[0]); i++) {
        printf("x = %i\n", *(v + i));
    }

    return 0;
}