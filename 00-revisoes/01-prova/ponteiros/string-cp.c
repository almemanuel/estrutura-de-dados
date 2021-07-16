#include <stdio.h>

void stringCopy(char *copy, char *paste) {
    int i;
    // a cópia será feita desconsiderando o caracter '\0'
    for(i = 0; *(copy + i) != '\0'; i++) {
        if(*(copy + i) != '\0') {
            *(paste + i) = *(copy + i);
        }
    }
}


int main() {
    char str1[] = "sex tape";
    char str2[20];

    stringCopy(str1, str2);
    printf("%s\n", str2);
    // exit: sex tape

    return 0;
}