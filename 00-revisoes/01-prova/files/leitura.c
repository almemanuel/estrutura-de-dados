#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *file;
    file = fopen("num.txt", "r"); /* "r" permite ler um arquivo existente. caso não exista, o problema estará suscetível a erros */

    /* se o ponteiro apontar para NULL, significa que o arquivo não existe */
    if(file == NULL) {
        printf("arquivo inexistente");
    } else {
        int x, y, z;
        fscanf(file, "%i %i %i", &x, &y, &z);   /* fscanf funciona igual o scanf, porém é informado antes a entidade a ser analisada        */
                                                /* o grande problema é que o arquivo precisa estar perfeitamente formatado para funcionar   */
        printf("%i %i %i\n", x, y, z);

        fclose(file);
    }

    return 0;
}