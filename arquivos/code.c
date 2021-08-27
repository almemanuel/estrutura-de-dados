#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *f = fopen("arquivo.txt", "w");
    if(f == NULL) {
        printf("ERRO NA ABERTURA");
        exit(1);
    }
    char txt[20] = "My program at C";
    int i;

    /* escreverá um caractere a cada iteração */
    for(i = 0; i < strlen(txt); i++)
        fputc(txt[i], f);
        fputc('*', f);
    fclose(f);

    return 0;
}