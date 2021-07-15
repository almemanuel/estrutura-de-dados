#include<stdio.h>

void testVar(int x);
void testPtr(int *px);

int main() {
    int test = 1;
    int *ptest = &test;

    printf("%i\n", test);
    // exit: 1

    // como o parametro foi passado por cópia, a implementação não será salva nesta forma, teríamos que ter um return na função, e armazenar
    // em uma variável. Sem isso, as iterações da função estarão disponíveis apenas ao seu escopo
    testVar(test);
    printf("%i\n", test);
    // exit: 1

    // como o parametro é passado por referencia, a implementação alterará diretamente no endereço de memória do parametro. Logo, as iterações
    // serão implementadas no escopo do parametro que foi passado. Isso ocorre quando passamos um endereço de memoria (seja literalmente ou
    // através de ponteiro) para uma função com ponteiro como parametro
    testPtr(ptest);
    printf("%i\n", *ptest);
    // exit: 2

    // como foi alterado via ponteiro, a variável apontada foi alterada
    printf("%i\n", test);
    // exit: 2

    return 0;
}

// parametro por copia: cria uma cópia da variável para as iterações
void testVar(int x) {
    x++;
}

// parametro como referencia: as iterações ocorrem diretamente no endereço de memória
void testPtr(int *px) {
    (*px)++;
}