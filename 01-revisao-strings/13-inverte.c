/**********************************************************************
Faça um programa que receba duas frases distintas e imprima de maneira
invertida, trocando as letras A por *
**********************************************************************/
#include <stdio.h>
#include <string.h>

typedef struct {
    char string[50];
} str;

str change(str sentence);
void inverted_print(char string[50]);

int main() {
    str sentence[2];
    for(int i = 0; i < 2; i++) {
        printf("Type anything: ");
        fgets(sentence[i].string, 50, stdin);
        setbuf(stdin, NULL);
        sentence[i] = change(sentence[i]);
    }

    for(int i = 0; i < 2; i++) {
        inverted_print(sentence[i].string);
    }

    return 0;
}

str change(str sentence) {
    int i;
    for(i = 0; sentence.string[i] != '\0'; i++) {
        if(sentence.string[i] == 'A' || sentence.string[i] == 'a') {
            sentence.string[i] = '*';
        }
    }
    return sentence;
}

void inverted_print(char string[50]) {
    int i;
    for(i = (int)strlen(string) - 2; i != 0; i--) {
        printf("%c", string[i]);
    }
    printf("\n");
}