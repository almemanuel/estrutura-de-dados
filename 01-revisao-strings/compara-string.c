/**********************************************************************
Crie um programa que compara duas strings (não use a função ao strcmp).
**********************************************************************/

#include<stdio.h>

int main() {
    char string[2][50];

    int i;
    for(i = 0; i < 2; i++) {
        printf("Digite qualquer coisa para a string %i: ", i);
        fgets(string[i], 50, stdin);
    }

    int j, cont[2] = {0, 0};
    for(i = 0; i < 2; i++) {
        for(j = 0; string[i][j] != '\0'; j++) {
            cont[i]++;
        }
    }

    if(cont[0] != cont[1]) {
        printf("As strings são diferentes");
    } else {
        int fim = 0, verif = 0;
        for(j = 0; verif == 0; j++) {
            if(string[0][j] != string[1][j]) {
                verif++;
            } else if(string[0][j] == '\0') {
                if(string[1][j] != '\0') {
                    verif++;
                }
                break;
            }
        }
        if(verif == 0) {
            printf("As strings são iguais");
        } else {
            printf("As strings são diferentes");
        }
    }
    return 0;
}