#include<stdio.h>

int main() {
    typedef struct horario {
        int h;
        int min;
        int s;
    } time;

    time now;
    now.h = 10;
    now.min = 46;
    now.s = 12;

    printf("%.2i:%.2i:%.2i\n", now.h, now.min, now.s);

    // trabalhar com structs é praticamente o mesmo que trabalhar com tipos primitivos
    time after;
    after.h = now.h + 10;
    after.min = now.min;
    after.s = 0;

    printf("%.2i:%.2i:%.2i", after.h, after.min, after.s);

    return 0;
}