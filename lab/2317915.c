/*
Emanuel de Almeida Souza
2317915
1a reavaliacao
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char nome[20];
    char link[30];
    int acessos;
} Sites;

void listainicial(FILE *arq, Sites *v) {
    if(arq == NULL) {
        printf("ERRO\n");
        exit(1);
    }
    int i, j;
    for(i = 0; i < 6; i++) {
        fscanf(arq, "%s %s %i", (v + i)->nome, (v + i)->link, &(v + i)->acessos);
    }
}

void inserir(char *nome, char *link, int acessos, Sites *v, int tam) {
    int i = 0;
    while(v + i == NULL) {
        i++;
    }
    if(i == tam) {
        printf("\nTamanho maximo atingido");
        return;
    }
    nome[strcspn(nome, "\n")] = 0;
    strcpy((v + i)->nome, nome);
    link[strcspn(link, "\n")] = 0;
    strcpy((v + i)->link, link);
    (v + i)->acessos = acessos;
}

void exibir(Sites *v, int pos) {
    printf("\t\n%s : %s\n", (v + pos)->nome, (v + pos)->link);
}

void busca(char *nome, Sites *v, int tam) {
    nome[strcspn(nome, "\n")] = 0;
    int i = 0;
    while(!(strcmp((v + i)->nome, nome)) || i < tam) {
        if(strcmp((v + i)->nome, nome) == 0) {
            exibir(v, i);
            break;
        }
        i++;
    }
    if(strcmp((v + i)->nome, nome) == 1) {
        printf("\nNao encontrado");
        return;
    }

    Sites aux = *(v + i);
    *(v + i) = *(v + 0);
    *(v + 0) = aux;
    // devido a ter chegado tarde nessa parte, apenas inverti o inicial com o correspondente
}

void removesite(char *nome, Sites *v, int tam){
    nome[strcspn(nome, "\n")] = 0;
    int i = 0;
    while(!(strcmp((v + i)->nome, nome)) || i < tam) {
        if(strcmp((v + i)->nome, nome) == 0) {
            break;
        }
        i++;
    }
    if(strcmp((v + i)->nome, nome) == 1) {
        printf("\nNao encontrado");
        return;
    }

    while((v + i) != NULL) {
        *(v + i) = *(v + i + 1);
        i++;
    }
    free(v + i);
}

int main() {
    int tam;
    printf("Infome a quantidade de sites que voce deseja registrar: ");
    scanf("%i", &tam);
    Sites *v = (Sites *) malloc(sizeof(Sites) * (tam + 6));
    FILE *arq = fopen("sites.txt", "rb");
    listainicial(arq, v);
    fclose(arq);
    int op;
    do {
        printf("\n\t1 - INSERIR SITE\n\t2 - BUSCAR SITE\n\t3 - REMOVER SITE\n\t4 - IMPRIMIR TOP-10\n\t5 - SAIR\nInforme uma opcao: ");
        scanf("%i", &op);
        switch(op) {
            case 1:{
                setbuf(stdin, NULL);
                char auxnome[20], auxlink[30];
                int auxacess;
                printf("\nNome: ");
                fgets(auxnome, 20, stdin);
                setbuf(stdin, NULL);
                printf("\nLink: ");
                fgets(auxlink, 30, stdin);
                setbuf(stdin, NULL);
                printf("\nAcessos: ");
                scanf("%i", &auxacess);
                inserir(auxnome, auxlink, auxacess, v, tam);

            } break;

            case 2: {
                setbuf(stdin, NULL);
                char auxnome[20];
                printf("\nNome do site: ");
                fgets(auxnome, 20, stdin);
                setbuf(stdin, NULL);
                busca(auxnome, v, tam);
            }

            break;

            case 3: {
                setbuf(stdin, NULL);
                char auxnome[20];
                printf("\nNome do site: ");
                fgets(auxnome, 20, stdin);
                setbuf(stdin, NULL);
                removesite(auxnome, v, tam);
            }
            break;

            case 4:

            break;

            case 5:

            break;

            default:
                printf("ERRO! Informe uma opcao valida\n");
        }

    } while(op != 5);
    return 0;
}