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

int main() {
    FILE *f = fopen("arquivo.txt", "r");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char c;
    int i;
    for(i = 1; i <= 10; i++) {
        c = fgetc(f);
        printf("%c", c);
    }
    fclose(f);
    return 0;
}