#include<stdio.h>

int main() {
    // um vetor é, naturalmente, um ponteiro
    int vetor[3] = {1, 2, 3};
    int *ptr = vetor; // ele utiliza o endereço de memoria inicial como referencia

    printf("%i\n", *ptr);
    // exit: 1

    int *ptr2 = &vetor[2]; // isso força o ponteiro a apontar para um indice especifico do vetor. sua sintaxe seria a tradicional
    printf("%i\n", *ptr2);
    // exit: 3

    return 0;
}