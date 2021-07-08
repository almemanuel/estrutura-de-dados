/***************************************************************************************************
Faça um programa que simule uma rede social. Leia um inteiro n de usuários e:
    a) Leia um vetor de n usuários, sendo que cada um tem nome (máximo de 15 letras),
quantidade de amigos e lista de amigos.
    b) A lista de amigos é um vetor de strings com nomes dos amigos (máximo de 15 letras cada nome).
    c) Calcule e mostre a popularidade de cada usuário da rede social, sendo que a popularidade é o
número de vezes que aparece na lista de amigos de todos os usuários.
***************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct Users {
    char name[15];
    int follows;
    char friends[][15];
} usr;


void form(usr *code) {
    printf("Digite um nome para o usuario: ");
    fgets(code ->name, 15, stdin);
    setbuf(stdin, NULL);
    code ->follows = 0;
    do {
        printf("Digite o numero de amigos: ");
        scanf("%i", &code ->follows);
        setbuf(stdin, NULL);
    } while(code ->follows < 0);
    int j;
    for(j = 0; j < code ->follows; j++) {
        printf("Nome do amigo: ");
        fgets(code ->friends[j], 15, stdin);
        setbuf(stdin, NULL);
    }
};


int main() {
    int n = 0;

    do {
        printf("Digite a quantidade n de usuarios: ");
        scanf("%i", &n);
        setbuf(stdin, NULL);
    } while(n <= 0);

    usr user_id[n];
    int i = 0;
    for(int i; i < n; i++) {
        form(&user_id[i]);
    }

    return 0;
}