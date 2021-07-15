#include<stdio.h>

typedef struct time{
    int *ph;
    int *pmin;
    int *ps;
} time;

int main() {
    time today; // está variavel contem ponteiros como propriedade
    int h = 12, min = 34, s = 56;

    // a passagem do endereço para o ponteiro é feito da mesma forma
    today.ph = &h;
    today.pmin = &min;
    today.ps = &s;

    // a variavel do tipo struct, mesmo sendo declarada normalmente, possui ponteiros como propriedades
    // por isso, para acessar os dados, utilizamos uma sintaxe de ponteiro, *var.prop
    printf("%.2i:%.2i:%.2i\n", *today.ph, *today.pmin, *today.ps);
    // exit: 12:34:56

    *today.ps = 0;
    printf("%.2i:%.2i:%.2i\n", *today.ph, *today.pmin, *today.ps);
    // exit: 12:34:00

    return 0;
}