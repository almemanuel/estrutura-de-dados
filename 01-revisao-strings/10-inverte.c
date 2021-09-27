/************************************************************************
Faça um programa que receba uma palavra e a imprima de trás-para-frente.
************************************************************************/
#include <stdio.h>
#include <string.h>

void reverse_print(char string[50]);

int main() {
    char string[50];

    printf("Type anything: ");
    fgets(string, 50, stdin);
    setbuf(stdin, NULL);

    reverse_print(string);

    return 0;
}

void reverse_print(char string[50]) {
    int i;
    for(i = (int) strlen(string) - 2; i >= 0; i--) {
        printf("%c", string[i]);
    }
    printf("\n");
}