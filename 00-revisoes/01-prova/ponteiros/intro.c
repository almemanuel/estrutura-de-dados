#include<stdio.h>

int main() {
    int x;
    x = 10;

    printf("%i ", x); // acessa a variavel x
    printf("%p\n", &x); // acessa o endereco de x - troquei %i por %p devido a warnings

    // criando um ponteiro
    int *ponteiro; // na criacao, ele aponta para NULL
    ponteiro = &x; // o ponteiro aponta para o endereço de x

    printf("%i ", *ponteiro); // *ponteiro usa o conteudo do endereco apontado
    printf("%p\n", ponteiro); // ponteiro usa o seu conteudo (o endereco de memoria para o qual aponta)

    // não há dependencia entre duas variaveis. elas sao alteradas linearmente
    int y = x; // y recebe o valor de x (10)
    x = 20; // x recebe 20

    printf("%i %i\n", x, y);

    // alterar variavel via ponteiro
    *ponteiro = y; // o valor do endereço de memoria do ponteiro recebe o valor de y; ou seja, x=y
    printf("%i %i\n", x, y);

    return 0;
}