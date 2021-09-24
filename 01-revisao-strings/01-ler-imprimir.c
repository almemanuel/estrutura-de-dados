/*****************************************************
Faça um programa que então leia uma string e a imprima
*****************************************************/

#include<stdio.h>

int main() {
    char string[50];

    printf("Digite qualquer coisa: ");
    fgets(string, 50, stdin);

    printf("%s", string);
    return 0;
}
