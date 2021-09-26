/********************************************************************
Faça um programa que conte o numero de 1’s que aparecem em um string.
Exemplo: 0011001->3
********************************************************************/
#include <stdio.h>

int countOne(char string[50]);

int main() {
    char string[50];
    printf("Type anything: ");
    fgets(string, 50, stdin);
    setbuf(stdin, NULL);

    printf("%i\n", countOne(string));

    return 0;
}

int countOne(char string[50]) {
    int i, count = 0;
    for(i = 0; string[i] != '\0'; i++) {
        if(string[i] == '1') {
            count++;
        }
    }
    return count;
}