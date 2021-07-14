#include<stdio.h>

int main() {
    typedef struct horario {
        int h;
        int min;
        int s;
    } time;

    // os vetores e matrizes funcionam de forma analoga
    time test[5];
    test[0].h = 10;
    test[0].min = 20;
    test[0].s = 30;
    // o vetor tambem pode ser inicializado ja na sua declaracao tambem, como nos tipos primitivos

    printf("%.2i:%.2i:%.2i\n", test[0].h, test[0].min, test[0].s);

    // é possivel utilizar um loop para acessar o vetor
    int i;
    for(i = 1; i < sizeof(test) / sizeof(test[0]); i++) {
        test[i].h = test[i - 1].h + 1;
        test[i].min = test[i - 1].min + 2;
        test[i].s = test[i - 1].s + 3;
        printf("%.2i:%.2i:%.2i\n", test[i].h, test[i].min, test[i].s);
    }

    return 0;
}