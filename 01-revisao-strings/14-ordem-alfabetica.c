/****************************************************************************
Escreva um programa que leia duas palavras e diga qual deles vem primeiro na
ordem alfabética. Dica: ‘a’ é menor do que ‘b’.
****************************************************************************/
#include <stdio.h>
#include <ctype.h>

void sort(char word[2][20]);

int main() {
    char word[2][20];
    int i;
    for(i = 0; i < 2; i++) {
        printf("Type anything: ");
        fgets(word[i], 20, stdin);
        setbuf(stdin, NULL);
    }

    sort(word);

    return 0;
}

void sort(char word[2][20]) {
    int i;
    for(i = 0; i < 20 || word[0][i] != '\0' || word[1][i] != '\0'; i++) {
        if(tolower(word[0][i]) < tolower(word[1][i])) {
            printf("%s", word[0]);
            break;
        } else if(tolower(word[1][i]) < tolower(word[0][i])) {
            printf("%s", word[1]);
            break;
        }
    }
}