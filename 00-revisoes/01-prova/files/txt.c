#include <stdio.h>

int main() {
    FILE *file;                     /* FILE é um tipo de variável */
    file = fopen("test.txt", "w");  /* fopen() faz que o ponteiro aponte para um arquivo dito no endereço, considerando o local atual como  */
                                    /* referência, e alguns atributos podem ser dados; nesse caso, "w" sobescreve                           */
    fprintf(file, "C is suck");     /* fprintf() é uma função semelhante ao printf, que escreve no arquivo a mensagem inserida              */
    fclose(file);                   /*  sala o arquivo                                                                                      */

    return 0;
}