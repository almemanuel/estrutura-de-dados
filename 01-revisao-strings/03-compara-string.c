/**********************************************************************
Crie um programa que compara duas strings (não use a função ao strcmp).
**********************************************************************/

#include<stdio.h>

int string_compare(char str[2][50]);

int main() {
    char string[2][50];

    int i;
    for(i = 0; i < 2; i++) {
        printf("Digite qualquer coisa para a string %i: ", i);
        fgets(string[i], 50, stdin);
    }
    if(string_compare(string)) {
        printf("As strings sao iguais.\n");
    } else {
        printf("As strings sao diferentes.\n");
    }

    return 0;
}

int string_len_compare(char str[2][50]) {
    int i, j, cont[2] = {0, 0};
    for(i = 0; i < 2; i++) {
        for(j = 0; str[i][j] != '\0'; j++) {
            cont[i]++;
        }
    }
    if(cont[0] == cont[1]) return 1;
    else return 0;
}

int string_compare(char str[2][50]) {
    if(!string_len_compare(str)) {
        printf("As strings são diferentes");
        return 0;
    } else {
        int i, fim = 0, verif = 0;
        for(i = 0; verif == 0; i++) {
            if(str[0][i] != str[1][i]) {
                verif++;
            } else if(str[0][i] == '\0') {
                if(str[1][i] != '\0') {
                    verif++;
                }
                break;
            }
        }
        if(verif == 0) return 1;
        else return 0;
    }
}