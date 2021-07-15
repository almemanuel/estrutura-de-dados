#include<stdio.h>

int addVet(int vet[], const int n) {
    int result = 0;
    int *p;
    int *const end = vet + n; // aponta para o ultimo elemento do vetor + 1

    // o ponteiro recebe o primeiro indice, e enquando for menor que o ultimo, irá iterar
    // basicamente, na configuracao do loop ele está utilizando endereços de memória
    for(p = vet; p < end; p++){
        result += *p;
    }

    return result;
}


int main() {
    int v[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

    printf("vector sum = %i\n", addVet(v, 10));
    // exit: vector sum = 50

    return 0;
}