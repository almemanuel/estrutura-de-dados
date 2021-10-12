/**********************************************************************************
Complete o algoritmo, implementando o procedimento "criptografia" utilizando a
criptografia de césar.
OBS: não pode conter alteração na Main
**********************************************************************************/
#include <stdio.h>

void cryptography(char *string);

int main() {
    char string[30];

    printf("Type anything: ");
    fgets(string, 30, stdin);
    setbuf(stdin, NULL);
    cryptography(string);

    printf("%s", string);

    return 0;
}

void cryptography(char *string) {
    int i;
    for(i = 0; *(string + i) != '\0'; i++) {
        if( (*(string + i) >= 'a' && *(string + i) <= 'w') || (*(string + i) >= 'A' && *(string + i) <= 'W')) {
            *(string + i) += 3;
        } else if( (*(string + i) >= 'x' && *(string + i) <= 'z') || (*(string + i) >= 'X' && *(string + i) <= 'Z') ) {
            *(string + i) -= 23;
        }
    }
}
