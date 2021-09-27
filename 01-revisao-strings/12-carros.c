/****************************************************************************
Faça um programa que preencha um vetor com os modelos de cinco carros
(exemplos de modelos: Fusca, Gol, Vectra, etc.). Preencha outro vetor com o
consumo desses carros, isto é, quantos quilómetros cada um deles faz com um
litro de combustível. Calcule e mostre: (a) O modelo de carro mais econômico;
(b) Quantos litros de combustível cada um dos carros cadastrados consomem
para percorrer uma distancia de 1.000 quilômetros.
****************************************************************************/
#include <stdio.h>

int moreEconomical(float consumption[5]);

int main() {
    char car[5][20];
    float consumption[5];
    int i;
    for(i = 0; i < 5; i++) {
        printf("Car %i: ", i + 1);
        fgets(car[i], 20, stdin);
        setbuf(stdin, NULL);

        do {
            printf("Km per liter: ");
            scanf("%f", &consumption[i]);
            setbuf(stdin, NULL);
            if(consumption[i] < 0) {
                printf("ERROR! Value less than 0\n\tTry again\n");
            }
        } while(consumption[i] < 0);
    }

    printf("\nMore economical: %s", car[moreEconomical(consumption)]);
    for(i = 0; i < 5; i++) {
        printf("%.3f L for 1000 Km on %s", consumption[i] * 1000, car[i]);
    }

    return 0;
}

int moreEconomical(float consumption[5]) {
    int i, index = 0;
    float less = consumption[0];
    for(i = 1; i < 5; i++) {
        if(consumption[i] < less) {
            less = consumption[i];
            index = i;
        }
    }
    return index;
}
