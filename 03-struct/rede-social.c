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
#include<string.h>


typedef struct Users {
    char name[15];
    int follows;
    int pop;
    char friends[][15];
} usr;


void form(usr *code) {
    /* preenchimento dos dados */
    setbuf(stdin, NULL);
    printf("Digite um nome para o usuario: ");
    fgets(code ->name, 15, stdin);
    setbuf(stdin, NULL);

    code ->follows = 0;
    do {
        printf("Digite o numero de amigos: ");
        scanf("%i", &code ->follows);
        setbuf(stdin, NULL);
    } while(code ->follows < 0);

    int i;
    for(i = 0; i < code ->follows; i++) {
        printf("Nome do amigo: ");
        fgets(code ->friends[i], 15, stdin);
        setbuf(stdin, NULL);
    }
};


void popmesure(usr *code, int n) {
    /*
    Busca pelos usuarios nos amigos dos outros usuarios
    *code aponta para os usuarios
    n é o numero de usuarios
    i é uma variavel que controla o usuario pelo qual buscamos nas listas
    j é uma variável que controla o usuário a qual a lista pertence
    a busca pelo usuario i só ocorrerá na lista do amigo j se eles forem diferentes
    k é uma variavel que controla cada amigo na lista do amigo j
    k = i -> i é amigo de j, e a popularidade de i é incrementado
    */
    int i, result = 0;
    char *user_result;
    for(i = 0; i < n; i++) {
        (code + i)->pop = 0;
        int j;
        for(j = 0; j < n; j++) {
            if(i != j) {
                int k;
                for(k = 0; k < (code + j) ->follows; k++) {
                    if(strncmp((code + i) -> name, (code + j)-> friends[k], 15) == 0) {
                        (code + i) ->pop++;
                    }
                }
            }
        }
    }
}


int main() {
    int n_users = 0;

    do {
        printf("Digite a quantidade n de usuarios: ");
        scanf("%i", &n_users);
        setbuf(stdin, NULL);
    } while(n_users <= 0);

    usr user_id[n_users];
    int i;
    for(i = 0; i < n_users; i++) {
        form(&user_id[i]);
    }

    popmesure(&user_id[0], n_users);

    int j;
    for(j = 0; j < n_users; j++) {
        printf("%i -> %s", user_id[j].pop, (user_id + j) ->name);
    }

    return 0;
}
