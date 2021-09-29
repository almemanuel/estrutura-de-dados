/**************************************************************************
Faça um programa que, dada uma string, diga se ela e um palíndromo ou não.
Lembrando que um palíndromo e uma palavra que tenha a propriedade de
poder ser lida tanto da direita para a esquerda como da esquerda para a
direita. Exemplo: ovo; arara; Socorram-me, subi no ônibus em Marrocos;
Anotaram a data da maratona;
**************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrome(char string[100]);

int main() {
    char string[100];
    printf("Type anything: ");
    fgets(string, 100, stdin);
    setbuf(stdin, NULL);

    if(palindrome(string)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int palindrome(char string[100]) {
    char onlyalpha[100];
    int i, size = 0;
    for(i = 0; string[i] != '\n'; i++) {
        if( (string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'z') ) {
            onlyalpha[size] = toupper(string[i]);
            size++;
        }
    }

    int middle;
    if(size % 2 == 1) {
        middle = (size - 1) / 2 + 1;
    } else {
        middle = size / 2;
    }
    for(i = 0; i <= middle; i++) {
        if(onlyalpha[i] != onlyalpha[size - i - 1]) {
            return 0;
        }
    }
    return 1;
}
