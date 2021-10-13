/***********************************************************************************
Crie um programa que contenha um procedimento que permita passar por parâmetro dois
números reais A e B. A função deverá calcular a soma entre estes dois números e
armazenar o resultado na variável A. Este procedimento deverá modificar o valor do
primeiro parâmetro. Imprima os valores de A e B na função principal.
***********************************************************************************/
#include <stdio.h>

void soma(float *A, float *B);

int main() {
    float A, B;
    printf("Informe dois valores reais: ");
    scanf("%f %f", &A, &B);

    soma(&A, &B);

    printf("%.2f %.2f", A, B);

    return 0;
}

void soma(float *A, float *B) {
    *A += *B;
}