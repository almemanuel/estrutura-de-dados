/**************************************************************
Digite um nome, calcule e retorne quantas letras tem esse nome
**************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char name[10];
    printf("Name: ");
    fgets(name, 10, stdin);
    setbuf(stdin, NULL);

    printf("The name has %i characters\n", (int)strlen(name) - 1);

    return 0;
}