#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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
}*/

/* Exemplo 1
int main() {
    FILE *f1 = fopen("exemplo1.txt", "r"), *f2 = fopen("resposta1.txt", "w");
    if(f1 == NULL || f2 == NULL) {
        printf("ERRO");
        exit(1);
    }

    char c = fgetc(f1);
    while(c != EOF) {
        fputc(toupper(c), f2);
        c = fgetc(f1);
    }

    fclose(f1);
    fclose(f2);

    return 0;
} */

/* utilizando feof() para verificar se chegou ao fim do arquivo
int main() {
    FILE *f = fopen("arquivo.txt", "r");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char c = fgetc(f);
    while(!feof(f)) {
        printf("%c", c);
        c = fgetc(f);
    }
    fclose(f);
    return 0;
}*/

