/**********************************************************************************
Crie um programa que calcula o comprimento de uma string (nao use a função strlen).
**********************************************************************************/

#include<stdio.h>

int main() {
    char string[50];

    printf("Digite qualquer coisa: ");
    fgets(string, 50, stdin);

    int i, cont = 0;
    for(i = 0; string[i] != '\n'; i++) {
        cont++;
    }

    printf("A string digitada eh um vetor com %i posicoes", cont);
    return 0;
}
