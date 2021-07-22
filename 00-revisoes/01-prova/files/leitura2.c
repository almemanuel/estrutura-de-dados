#include <stdio.h>
#include<stdlib.h>

int main() {
    FILE *file;
    file = fopen("str.txt", "r");

    if(file == NULL) {
        printf("nao foi possivel abrir o arquivo");
        exit(0);
    }

    char frase[100];

    /*  com fgets, a leitura precisa ser feita dessa forma, pois, se feita da forma tradicional,
    ele interromperá a leitura na primeira quebra */
    while(fgets(frase, 100, file) != NULL) {
        printf("%s", frase);
    }

    fclose(file);

    return 0;
}