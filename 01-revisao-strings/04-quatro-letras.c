/*************************************************************************
Faça um programa que leia um nome e imprima as 4 primeiras letras do nome.
*************************************************************************/
#include <stdio.h>

void printfour(char name[10]);

int main() {
    char name[10];
    printf("Type your name: ");
    fgets(name, 10, stdin);
    setbuf(stdin, NULL);

    printfour(name);

    return 0;
}


void printfour(char name[10]) {
    int i;
    for(i = 0; i < 4; i++) {
        if(name[i] == '\n') {
            break;
        }
        printf("%c", name[i]);
    }
    printf("\n");
}