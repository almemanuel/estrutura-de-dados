#include<stdio.h>

// é recomendavel, quando há funcoes, definir a struct como global antes de qualquer subprograma
typedef struct horario {
    int h;
    int min;
    int s;
} time;


// a declaracao da funcao e dos parametros ocorre de forma analoga aos tipos primitivos
time newTime(time t);


int main() {
    time now;
    now.h = 10;
    now.min = 46;
    now.s = 12;

    time after = newTime(now);
    // exit 10:46:12

    printf("%.2i:%.2i:%.2i", after.h, after.min, after.s);
    // exit 02:30:00

    return 0;
}

// como a funcao é do tipo time, ela precisa também retornar um valor do tipo time
time newTime(time t) {
    printf("%.2i:%.2i:%.2i\n", t.h, t.min, t.s);
    t.h = 2;
    t.min = 30;
    t.s = 0;

    return t;
}