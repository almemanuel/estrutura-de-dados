#include <stdio.h>
#include<stdlib.h>

void copiarConteudo(FILE *file1, FILE *file2) {
    char aux[200];
    while(fgets(aux, 200, file1) != NULL)
    fputs(aux, file2);
}


int main() {
    FILE *file1 = fopen("str.txt", "r");

    if(file1 == NULL) {
        printf("arquivo inexistente");
        exit(1);
    }

    FILE *file2 = fopen("str2.txt", "w");
    copiarConteudo(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}