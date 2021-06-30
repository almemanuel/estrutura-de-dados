/*****************************************************************************
Escreva um programa que contenha duas variáveis inteiras.
Armazene a soma em uma terceira variável usando um ponteiro para ela.
Em seguida, apresente a soma e o endereço da variável que contem o resultado.
*****************************************************************************/

#include<stdio.h>

int main() {
    int a, b, *pa = &a, *pb = &b, soma = *pa + *pb;

    printf("Soma vale %i e esta no endereco de memoria %p", soma, &soma);

    return 0;
}