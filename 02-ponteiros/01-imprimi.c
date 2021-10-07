/**************************************************************************************************
Faça um programa para imprimir o tamanho (em bytes), conteúdo e o endereço de memória das variáveis
conforme declarado a seguir:
void main() {
    int a = 32;
    float b = 10.6;
    char c = ‘w’;
    int *pa = &a;
    float *pb = &b;
    char *pc = &c ;
    .....
    }
**************************************************************************************************/

#include<stdio.h>

int main() {
    int a = 32;
    float b = 10.6;
    char c = 'w';
    int *pa = &a;
    float *pb = &b;
    char *pc = &c;

    printf("TAMANHO DAS VARIAVEIS\na = %lu bytes\nb = %lu  bytes\nc = %lu  bytes", sizeof(*pa), sizeof(*pb), sizeof(*pc));
    printf("\nCONTEUDO\na = %i\nb = %.1f\nc = %c", *pa, *pb, *pc);
    printf("\nENDERECO\na = %p\nb = %p\nc = %p", pa, pb, pc);

    return 0;
}
