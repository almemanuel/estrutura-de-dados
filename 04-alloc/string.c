/*
Escreva uma função que receba um byte c (que pode representar um caractere ASCII, por exemplo) e
transforme-o em uma string, ou seja, devolva uma string de comprimento 1 tendo c como único elemento.
*/

#include<stdio.h>
#include<stdlib.h>

void f1(char x) {
    char *c = (char *) malloc(sizeof(char));
    *c = x;
    printf("%p %c", c, *c);
}


int main() {
    f1('c');
}