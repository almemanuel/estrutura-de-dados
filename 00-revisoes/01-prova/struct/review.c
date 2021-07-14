#include<stdio.h>

typedef struct horario {
    int h;
    int min;
    int s;
} time;

time catTime();
void printTime(time t);

int main() {
    time moments[5];
    int i;
    for(i = 0; i < 5; i++) {
        moments[i] = catTime();
    }

    for(i = 0; i < 5; i++) {
        printTime(moments[i]);
    }

    return 0;
}

time catTime(){
    time t;
    scanf("%i %i %i", &t.h, &t.min, &t.s);

    return t;
}


void printTime(time t){
    printf("%.2i:%.2i:%.2i\n", t.h, t.min, t.s);
}