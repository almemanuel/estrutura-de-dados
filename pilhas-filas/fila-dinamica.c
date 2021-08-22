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
int tamanho_fila(Fila *fila);
int fila_vazia(Fila *fila);
void insere_fila(Fila *fila, Dados dados);
void remove_fila(Fila *fila);
int consulta_fila(Fila *fila);

/* PROGRAMA PRINCIPAL */
int main() {
    Fila *fila = cria_fila();
    Dados teste;
    teste.chave = 1;
    insere_fila(fila, teste);
    printf("%i ", teste.chave);
    teste.chave = 2;
    insere_fila(fila, teste);
    printf("%i ", teste.chave);
    teste.chave = 3;
    insere_fila(fila, teste);
    printf("%i\n", teste.chave);
    printf("%i ", consulta_fila(fila));
    remove_fila(fila);
    printf("%i ", consulta_fila(fila));
    remove_fila(fila);
    printf("%i\n", consulta_fila(fila));
    remove_fila(fila);
    printf("%i", tamanho_fila(fila));
    libera_fila(fila);
    return 0;
}

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


int tamanho_fila(Fila *fila) {
    if(fila == NULL) return -1;
    int cont = 0;
    No *aux = fila->inicio;
    while(aux != NULL) {
        cont++;
        aux = aux->prox;
    } return cont;
}


int fila_vazia(Fila *fila) {
    if(fila == NULL || fila->inicio == NULL) return 1;
    return 0;
}


void insere_fila(Fila *fila, Dados dados) {
    if(fila == NULL) return;
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL) return;
    aux->dados = dados;
    aux->prox = NULL;
    if(fila->final == NULL) fila->inicio = aux;
    else fila->final->prox = aux;
    fila->final = aux;
}


void remove_fila(Fila *fila) {
    if(fila == NULL || fila->inicio == NULL) return;
    No *aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if(fila->inicio != NULL) fila->final = NULL;
    free(aux);
    aux = NULL;
}


int consulta_fila(Fila *fila) {
    if(fila == NULL || fila->inicio == NULL) return 0;
    return fila->inicio->dados.chave;
}
