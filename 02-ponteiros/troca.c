/**********************************************************************************
Sejam a e b duas variáveis short int declaradas dentro de um procedimento qualquer.
Implemente o procedimento troca capaz de trocar o valor de a por b e vice-versa.
Defina você mesmo o protótipo do procedimento.
**********************************************************************************/

#include<stdio.h>

void troca(short *a, short *b) {
    short aux = *a;
    *a = *b;
    *b = aux;
    printf("a = %hi\nb = %hi", *a, *b);
}


int main() {
    short a, b;

    printf("Valor de a: ");
    scanf("%hi", &a);
    printf("Valor de b: ");
    scanf("%hi", &b);

    troca(&a, &b);
    return 0;
}
