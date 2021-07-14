#include<stdio.h>

int main() {
    // as variaveis podem ser inicializadas junto com a struct após o fechamento do bloco, bem como os valores de cada propriedade
    struct time{
        int h;
        int min;
        int s;
    } now = {10, 20, 30};

    printf("%.2i:%.2i:%.2i\n", now.h, now.min, now.s);
    // exit: 10:20:30

    // da mesma forma que após a struct, todas as propriedades podem ser inicializadas juntamente com a variavel
    // onde nao há valor, é atribuído nulo
    struct time after = {};
    printf("%.2i:%.2i:%.2i\n", after.h, after.min, after.s);
    // exit: 00:00:00

    // também é possível atribuir fora de ordem, utilizando as propriedades da struct
    struct time before = {.s = 2, .min = 59};
    printf("%.2i:%.2i:%.2i\n", before.h, before.min, before.s);
    // exit: 00:59:02

    return 0;
}