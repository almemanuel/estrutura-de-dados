/**************************************************************************
Entre com um nome e imprima o nome somente se a primeira letra do nome for
“a” (maiúscula ou minúscula).
**************************************************************************/
#include <stdio.h>
#include <string.h>

int aVerification(char first);

int main() {
    char name[10];
    printf("Name: ");
    fgets(name, 10, stdin);
    setbuf(stdin, NULL);

    name[(int)strlen(name) - 1] = '\0';

    if(aVerification(name[0])) {
        printf("%s\n", name);
    }

    return 0;
}

int aVerification(char first) {
    if(first == 'A' || first == 'a') return 1;
    return 0;
}
