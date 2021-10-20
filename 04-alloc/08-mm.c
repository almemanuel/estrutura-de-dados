/********************************************************************************************************
Escreva uma função mm que receba um ponteiro para um vetor inteiro v[0..n-1], o número de
elementos do vetor (n) e os endereços de duas variáveis inteiras, min e Max. Deposite nessas variáveis o
valor de um elemento mínimo e o valor de um elemento máximo do vetor. Escreva também uma função
main que use a função mm.
********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int mm(int *v, int n, int *max, int *min);

int main() {
    int n;
    printf("Numero de elementos: ");
    scanf("%i", &n);
    int *v = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        printf("%iº elemento: ", i + 1);
        scanf("%i", v + i);
    }
    int max, min;
    if(mm(v, n, &max, &min)) {
        printf("M = %i | m = %i\n", max, min);
    }

    return 0;
}


int mm(int *v, int n, int *max, int *min) {
    if(v == NULL) return 0;

    *max = *v;
    *min = *v;

    for(int i = 1; i < n; i++) {
        if(*(v + i) > *max) {
            *max = *(v + i);
        } else if (*(v + i) < *min) {
            *min = *(v + i);
        }
    }
    return 1;
}