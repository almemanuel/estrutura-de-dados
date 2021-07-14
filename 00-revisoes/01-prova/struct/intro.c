#include<stdio.h>

int main() {
    // struct define um novo tipo
    typedef struct horario {
        int h;
        int min;
        int s;
    } time;

    time now; // a declaração é feita de forma analoga aos primitivos
    now.h = 10; // now.h acessa a propriedade h da struct
    now.min = 46; // ou seja, após o ., é acessado a propriedade daquela variavel de um determinado TAD
    now.s = 12;

    printf("%i:%i:%i", now.h, now.min, now.s);
    // exit: 10:46:12

    return 0;
}