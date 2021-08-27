#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Exemplo escrita de caractere
int main() {
    FILE *f = fopen("arquivo.txt", "w");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char txt[20] = "My program at C";
    int i;

    for(i = 0; i < strlen(txt); i++)
        fputc(txt[i], f);
        fputc('*', f);
    fclose(f);

    return 0;
} */

/* Exemplo leitura de caractere
int main() {
    FILE *f = fopen("arquivo.txt", "r");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char c;
    int i;
    for(i = 1; c <= 10; i++) {
        c = fgetc(f);
        printf("%c", c);
    }
    char d = fgetc(f);
    while(d != EOF) {
        printf("%c", d);
        d = fgetc(f);
    }
    fclose(f);
    return 0;
}/*
