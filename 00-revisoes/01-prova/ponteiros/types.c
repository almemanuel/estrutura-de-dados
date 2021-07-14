#include<stdio.h>

int main() {
    int x = 10;
    double y = 20.50;
    char z = 'a';

    // ponteiro devem ter o mesmo tipo das variaveis para a qual apontará
    int *px;
    px = &x;
    double *py;
    py = &y;
    char *pz;
    pz = &z;

    printf("Endereco x = %p - Valor x = %i\n", px, *px);
    printf("Endereco x = %p - Valor x = %f\n", py, *py);
    printf("Endereco x = %p - Valor x = %c\n", pz, *pz);

    // operacao matematica com ponteiros
    double soma = *px + *py; // soma recebe o valor apontado por px + o valor apontado por py
    printf("%f", soma);

    return 0;
}