#include<stdio.h>

int main() {
    // um vetor é, naturalmente, um ponteiro
    int vetor[3] = {1, 2, 3};
    int *ptr = vetor; // ele utiliza o endereço de memoria inicial como referencia

    printf("%i\n", *ptr);
    // exit: 1

    ptr++; // isto faz com que o ponteiro vá para o endereço de memória da frente. agora o ponteiro aponta para [1]
    printf("%i\n", *ptr);
    // exit: 2

    *(ptr + 1) = 10; // este tipo de sintaxe também acessa o endereço de memória. neste caso, altera um indice ([2])
    printf("%i\n", *(ptr + 1));
    // exit: 10

    int *ptr2 = &vetor[2]; // isso força o ponteiro a apontar para um indice especifico do vetor. sua sintaxe seria a tradicional
    printf("%i\n", *ptr2);
    // exit: 10

    return 0;
}