#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

struct No {
    Dado chave;
    struct No *prox;
};
typedef struct No No;


int lista_vazia(Lista *cabeca) {
    if(cabeca == NULL || *cabeca == NULL) return 1; /* lista vazia */
    return 0; /* lista preenchida */
}


Lista *cria_lista() {
    Lista *cabeca = (Lista *) malloc(sizeof(Lista)); /* endereço para o primeiro nó */
    if(cabeca != NULL)
        *cabeca = NULL; /* quando criada, a lista é vazia, e, portanto, aponta para NULL */
    return cabeca;
}


void libera_lista(Lista *cabeca) {
    if(cabeca == NULL) return;

    No *no;
    while((*cabeca) != NULL) {
        no = *cabeca; /* nó será auxiliar que recerá o inicio da lista */
        *cabeca = (*cabeca)->prox; /* o inicio da lista receberá o seu proximo elemento */
        free(no); /* no, que guarda o antigo primeiro elemento, é descartado */
        no = NULL;
    }
    free(cabeca); /* por fim, descarta a lista */
    cabeca = NULL;
}


int tamanho_lista(Lista *cabeca) {
    if(cabeca == NULL) return 0; /* Lista vazia */
    int tam = 0;
    No *no = *cabeca; /* nó será um ponteiro auxiliar que percorrerá toda lista */
    while(no != NULL) {
        tam++;
        no = no->prox;
    }
    return tam;
}


int insere_lista_inicio(Lista *cabeca, Dado dado) {
    if(cabeca == NULL) return 0; /* lista nao existe */
    No *no = (No *) malloc(sizeof(No)); /* cria o nó */
    if(no == NULL) return 0; /* significa que não foi possível alocar memória */
    no->chave = dado; /* ele recebe como chave o dado informado */
    no->prox = *cabeca; /* o próximo do nó é o endereço armazenado na lista */
    *cabeca = no; /* a cabeça passa a apontar para o nó */
    return 1;
}


int insere_lista_final(Lista *cabeca, Dado dado) {
    if(cabeca == NULL) return 0; /* lista nao existe */
    No *no = (No *) malloc(sizeof(No)); /* cria o nó */
    if(no == NULL) return 0; /* significa que não foi possível alocar memória */
    no->chave = dado;
    no->prox = NULL; /* aponta para NULL, marcando o fim da lista */
    if((*cabeca) == NULL)
        *cabeca = no; /* lista vazia -> nó torna-se primeiro elemento */
    else {
        No *aux = *cabeca; /* ponteiro auxiliar equivalendo o inicio da lista */
        while(aux->prox != NULL)
            aux = aux->prox; /* o auxiliar recebera sempre o seguinte até que o proximo seja NULL */
        aux->prox = no;
    }
    return 1;
}


int insere_lista_ordenada(Lista *cabeca, Dado dado) {
    if(cabeca == NULL) return 0;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return 0;
    no->chave = dado;
    if(lista_vazia(cabeca)) {
        no->prox = *cabeca;
        return 1;
    } else {
        No *ant, *atual = *cabeca;
        while(atual != NULL && atual->chave.valor < dados.valor) {
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *cabeca) {
            no->prox = *cabeca;
            *cabeca = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
}