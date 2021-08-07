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
int remove_lista_inicio(Lista *cabeca);
int remove_lista_final(Lista *cabeca);
int remove_no(Lista *cabeca, int chave);
int consulta_lista_pos(Lista *cabeca, int pos);
int consulta_lista_chave(Lista *cabeca, int chave);

#endif