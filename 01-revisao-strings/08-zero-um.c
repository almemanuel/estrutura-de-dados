/*************************************************************************
Escreva um programa que substitui as ocorrências de um caractere 0 em uma
string por outro caractere 1.
*************************************************************************/
#include <stdio.h>

int main() {
    char string[50];
    printf("Type anything: ");
    fgets(string, 50, stdin);
    setbuf(stdin, NULL);

    int i;
    for(i = 0; string[i] != '\0'; i++) {
        if(string[i] == '0') {
            string[i] = '1';
        }
    }
    printf("%s", string);

    return 0;
}