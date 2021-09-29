/**********************************************************************************
O codigo de César é uma das mais simples e conhecidas técnicas de
criptografia. É um tipo de substituição na qual cada letra do texto é substituída
por outra, que se apresenta no alfabeto abaixo dela um numero fixo de vezes.
Por exemplo, com uma troca de três posições, ‘A’ seria substituído por ‘D’, ‘B’ se
tornaria ‘E’, e assim por diante. Implemente um programa que faça uso desse
Código de César (3 posições), entre com uma string e retorne a string codificada.
Ex: a ligeira raposa marrom saltou sobre o cachorro cansado
R: D OLJHLUD UDSRVD PDUURP VDOWRX VREUH R FDFKRUUR FDQVDGR
**********************************************************************************/
#include <stdio.h>

typedef struct {
    char phrase[200];
} str;

str cryptography(str string);

int main() {
    str string;

    printf("Type anything: ");
    fgets(string.phrase, 200, stdin);
    setbuf(stdin, NULL);

    printf("%s", cryptography(string).phrase);

    return 0;
}

str cryptography(str string) {
    int i;
    for(i = 0; string.phrase[i] != '\0'; i++) {
        if( (string.phrase[i] >= 'a' && string.phrase[i] <= 'w') || (string.phrase[i] >= 'A' && string.phrase[i] <= 'W')) {
            string.phrase[i] += 3;
        } else if( (string.phrase[i] >= 'x' && string.phrase[i] <= 'z') || (string.phrase[i] >= 'X' && string.phrase[i] <= 'Z') ) {
            string.phrase[i] -= 23;
        }
    }
    return string;
}
