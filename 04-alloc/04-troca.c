/******************************************************************************************************
Sejam duas variáveis inteiras int a e int b declaradas na função int main(). Apresente um procedimento
em C capaz de trocar o valor de a pelo seu quadrado e o valor de b pelo seu fatorial. Apresente as
suposições que julgar necessário.
******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void quadrado(int *x);
void fatorial(int *x);
void desaloca(int *p);

int main(){
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));

    printf("Informe um valor para a e outro para b: ");
    scanf("%i %i", a, b);

    quadrado(a);
    fatorial(b);

    printf("%i %i\n", *a, *b);

    desaloca(a);
    desaloca(b);

    return 0;
}


void quadrado(int *x) {
    *x *= *x;
}


void fatorial(int *x) {
    int i;
    for(i = *x - 1; i > 1; i--) {
        *x *= i;
    }
}


void desaloca(int *p) {
    free(p);
    p = NULL;
}