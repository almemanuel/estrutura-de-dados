#include <stdio.h>
#include<stdlib.h>

int main() {
    FILE *file;
    file = fopen("str.txt", "a"); /* "a" permite adicionar texto ao arquivo existente */

    if(file == NULL) {
        printf("arquivo inexistente");
        exit(0);
    }

    fprintf(file, "primeira linha via codigo\n");

    char frase[] = "segunda linha via codigo\n";
    fputs(frase, file); /* fputs permite escrever uma string a um arquivo */

    char *caractere = "c";   /* para funcionar corretamente, necessita ser ponteiro */
    fputc(*caractere, file); /* faz o mesmo mas para um caractere */

    fclose(file);

    return 0;
}