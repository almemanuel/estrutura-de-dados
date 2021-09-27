/********************************************************************************
Faça um programa que receba uma palavra e calcule quantas vogais (a, e, i, o, u)
possui essa palavra. Entre com um caractere (vogal ou consoante) e substitua
todas as vogais da palavra dada por esse caractere.
********************************************************************************/
#include <stdio.h>
#include <ctype.h>

typedef struct {
    char word[50];
} string;

int vogals(char word[50]);
string change(string word, char character);

int main() {
    string word;

    printf("Type anything: ");
    fgets(word.word, 50, stdin);
    printf("%i vogals\n", vogals(word.word));

    char character;
    printf("Any character: ");
    character = getc(stdin);
    word = change(word, character);

    printf("%s", word.word);

    return 0;
}

int vogals(char word[50]) {
    int i, count = 0;
    for(i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
        if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            count++;
        }
    }
    return count;
}

string change(string word, char character) {
    int i;
    for(i = 0; word.word[i] != '\0'; i++) {
        if(word.word[i] == 'a' || word.word[i] == 'e' || word.word[i] == 'i' || word.word[i] == 'o' || word.word[i] == 'u') {
            word.word[i] = character;
        }
        if(toupper(word.word[i]) == 'A' || toupper(word.word[i]) == 'E' || toupper(word.word[i]) == 'I' || toupper(word.word[i]) == 'O' || toupper(word.word[i]) == 'U') {
            word.word[i] = character;
        }
    }
    return word;
}