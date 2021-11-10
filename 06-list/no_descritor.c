/*
Variação da lista dinâmica
Pode ser usado em lista simples, duplamente encadeada ou circular
Usa-se um nó especial chamado de nó cabeça ou nó descritar, que armazena diversas informações sobre a lista
Exemplo: ponteiro para o inicio, para o final e a quantidade de nós no nó cabeça

O nó descritor substitui o ponteiro para ponteiro que indica o inicio da lista
*/

#include<stdio.h>
#include<stdlib.h>

/* STRUCTS */
typedef struct dados {
    int chave;
} Dados;

typedef struct no {
    Dados dados;
    struct no *prox;
} No;

typedef struct descritor {
    No *inicio;
    No *final;
    int qtd;
} Cabeca;

typedef struct descritor Lista;

/* PROTÓTIPOS */
Lista *cria_lista();
void libera_lista(Lista *lista);
int tamanho_lista(Lista *lista);
void insere_lista_inicio(Lista *lista, Dados dados);
void insere_lista_final(Lista *lista, Dados dados);
void remove_lista_inicio(Lista *lista);
void remove_lista_final(Lista *lista);

/* PROGRAMA PRINCIPAL */


/* FUNÇÕES E PROCEDIMENTOS */
Lista *cria_lista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if(lista != NULL) {
        lista->inicio = NULL;
        lista->final = NULL;
        lista->qtd = 0;
    }
    return lista;
}


void libera_lista(Lista *lista) {
    if(lista != NULL) {
        No *no;
        while(lista->inicio != NULL) {
            no = lista->inicio;
            lista->inicio = lista->inicio->prox;
            lista->qtd--;
            free(no);
            no = NULL;
        }
        free(lista);
        lista = NULL;
    }
}


int tamanho_lista(Lista *lista) {
    if(lista == NULL) return -1;
    return lista->qtd;
}


void insere_lista_inicio(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return;
    no->dados = dados;
    no->prox = lista->inicio;
    if(lista->inicio == NULL)
        lista->final = no;
    lista->inicio = no;
    lista->qtd++;
}


void insere_lista_final(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return;
    no->dados = dados;
    no->prox = NULL;
    if(lista->inicio == NULL)
        lista->inicio = no;
    else
        lista->final->prox = no;
    lista->final = no;
    lista->qtd++;
}


void remove_lista_inicio(Lista *lista) {
    if(lista == NULL) return;
    if(lista->inicio == NULL) return;
    No *no = lista->inicio;
    lista->inicio = no->prox;
    free(no);
    no = NULL;
    if(lista->inicio == NULL) lista->final = NULL;
    lista->qtd--;
}


void remove_lista_final(Lista *lista) {
    if(lista == NULL || lista->inicio == NULL) return;
    No *ant, *no = lista->inicio;
    while(no->prox != NULL) {
        ant = no;
        no = no->prox;
    }
    if(no == lista->inicio) {
        lista->inicio = NULL;
        lista->final = NULL;
    } else {
        ant->prox = no->prox;
        lista->final = ant;
    }
    free(no);
    no = NULL;
    lista->qtd--;
}


