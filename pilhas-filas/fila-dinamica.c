/*
Cada elemento aponta para o seu sucessor
Trabalho com nó descritor pode facilitar a manipulação
Não precisam estar em espaço contiguo
*/

#include <stdio.h>
#include<stdlib.h>

/* STRUCTS */
typedef struct dados {
    int chave;
} Dados;

typedef struct no {
    Dados dados;
    struct no *prox;
} No;

typedef struct fila {
    No *inicio;
    No *final;
} Fila;

/* PROTÓTIPOS */
Fila *cria_fila();
void libera_fila(Fila *fila);

/* PROGRAMA PRINCIPAL */


/* FUNÇÕES E PROCEDIMENTOS*/
Fila *cria_fila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if(fila != NULL) {
        fila->final = NULL;
        fila->inicio = NULL;
    } return fila;
}


void libera_fila(Fila *fila) {
    if(fila != NULL) {
        No *aux;
        while(fila->inicio != NULL) {
            aux = fila->inicio;
            fila->inicio = fila->inicio->prox;
            free(aux);
            aux = NULL;
        }
        free(fila);
        fila = NULL;
    }
}


