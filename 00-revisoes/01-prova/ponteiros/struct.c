#include<stdio.h>

typedef struct time {
    int h;
    int min;
    int s;
} time;

int main() {
    time now, *later; // o ponteiro aponta para a estrutura, e seu uso é muito semelhante aos tipos primitivos
    later = &now;

    // para apontar para a propriedade, podemos usar (*pont).prop ou pont->prop, que é o mais adotado
    later->h = 20;
    later->min = 20;
    later->s = 20;

     // os valores foram alterados através do ponteiro
    printf("%.2i:%.2i:%.2i", now.h, now.min, now.s);
    // exit: 20:20:20

    return 0;
}