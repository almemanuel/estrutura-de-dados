#ifndef LINKED_H
#define LINKED_H

typedef struct {
    int valor;
} Dado;

typedef struct No *Lista;

int lista_vazia(Lista *cabeca);
Lista *cria_lista();
void libera_lista(Lista *cabeca);
int tamanho_lista(Lista *cabeca);
int insere_lista_inicio(Lista *cabeca, Dado dado);
int insere_lista_final(Lista *cabeca, Dado dado);
int insere_lista_ordenada(Lista *cabeca, Dado dado);

#endif