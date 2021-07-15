#include<stdio.h>

int addVet(int vet[], const int n) {
    int result = 0;
    int *p;
    int *const end = vet + n; // aponta para o ultimo elemento do vetor + 1

    // o ponteiro recebe o primeiro indice, e enquando for menor que o ultimo, irá iterar basicamente, na configuracao do loop ele está 
    // utilizando endereços de memória
    for(p = vet; p < end; p++){
        result += *p;
    }

    return result;
}

// o endereço do primeiro indice do vetor é passado como parametro, bem como seu tamanho sendo assim, o loop andará de endereço a endereço 
// enquanto o numero de iterações for menor que o tamanho do vetor
int multVet(int *start, int n) {
    int prod = 1, i;

    for(i = 0; i < n; i++) {
        prod *= *(start + 0);
    }

    return prod;
}


int main() {
    int v[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

    printf("vector sum = %i\n", addVet(v, 10));
    // exit: vector sum = 50

    // é passado como parametro o endereço do vetor (indice 0), e o tamanho total, definido pelo tamanho total de v sobre o tamanho de um 
    // elemento em v
    printf("vector mult = %i\n", multVet(v, sizeof(v) / sizeof(v[0])));
    // exit: vector mult = 9765625

    return 0;
}