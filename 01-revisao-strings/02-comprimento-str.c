/**********************************************************************************
Crie um programa que calcula o comprimento de uma string (nao use a função strlen).
**********************************************************************************/

#include<stdio.h>

int string_len(char str[50]);

int main() {
    char string[50];

    printf("Digite qualquer coisa: ");
    fgets(string, 50, stdin);

    int len = string_len(string);

    printf("A string digitada eh um vetor com %i posicoes\n", len);
    return 0;
}

int string_len(char str[50]) {
    int i, cont;
    for(i = 0; str[i] != '\0'; i++) {
        cont++;
    }
    return cont - 1;
}