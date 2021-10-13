/***********************************************************************************
Complete o algoritmo, implementando o procedimento "ordene", que colocará os números
pa, pb, pc em ordem decrescente.
OBS: você não poderá fazer alterações na Main.
***********************************************************************************/
#include <stdio.h>
void ordene(int *pa, int *pb, int *pc);

int main() {
    int a = 0, b = 0, c = 0 ;
    int *pa = &a, *pb = &b, *pc = &c;
    scanf("%i %i %i", pa, pb, pc);
    ordene(pa, pb, pc);
    printf("PA = %i, ",*pa);
    printf("PB = %i, ",*pb);
    printf("PC = %i",*pc);
    return 0;
}

void ordene(int *pa, int *pb, int *pc) {
    int *vet[] = {pa, pb, pc};
    int i = 0, j, aux;
    do {
        for(j = i + 1; j < 2; j++) {
            if(*vet[i] < *vet[j]) {
                aux = *vet[i];
                *vet[i] = *vet[j];
                *vet[j] = aux;
            }
        }
        i++;
    } while(i < 2);
}