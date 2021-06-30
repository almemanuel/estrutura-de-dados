/*************************************************************************************
Escreva um programa que contenha duas variáveis inteiras.
Compare seus conteúdos e exiba os endereços das variáveis do maior para o menor valor.
*************************************************************************************/

#include<stdio.h>

int main() {
    int a, b;
    int *pa;
    int *pb;

    pa = &a, pb = &b;

    if(pa > pb) {
        printf("Endereco de a = %p\nEndereco de b = %p", pa, pb);
    } else {
        printf("Endereco de b = %p\nEndereco de a = %p", pb, pa);
    }

    return 0;
}