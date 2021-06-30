/*****************************************************************************************************
Escreva um programa que declare um inteiro e um real, e ponteiros para inteiro e real.
Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros.
Imprima os valores das variáveis antes e após a modificação.
*****************************************************************************************************/

#include<stdio.h>

int main() {
    int i;
    printf("Informe um valor inteiro: ");
    scanf("%i", &i);

    float f;
    printf("Informe um valor real: ");
    scanf("%f", &f);

    int *pi = &i;
    printf("Informe um novo valor inteiro: ");
    scanf("%i", pi);

    float *pf = &f;
    printf("Informe um novo valor real: ");
    scanf("%f", pf);

    printf("i = %i\nf = %f", i, f);
    return 0;
}