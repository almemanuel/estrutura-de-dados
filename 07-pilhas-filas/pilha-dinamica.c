#include<stdio.h>
#include<stdlib.h>

/* STRUCT */
typedef struct dados {
    int chave;
} Dados;

typedef struct no {
    Dados dados;
    struct no *prox;
} No;

typedef No *Pilha;

/* PROTÓTIPOS */
Pilha *cria_pilha();
void libera_pilha(Pilha *pilha);
int tamanho_pilha(Pilha *pilha);
int pilha_vazia(Pilha *pilha);
void insere_pilha(Pilha *pilha, Dados dados);
void remove_pilha(Pilha *pilha);
int consulta_pilha(Pilha *pilha);

/* PROGRAMA PRINCIPAL */
int main() {
    Pilha *pilha = cria_pilha();
    Dados teste;
    teste.chave = 1;
    insere_pilha(pilha, teste);
    printf("%i ", teste.chave);
    teste.chave = 2;
    insere_pilha(pilha, teste);
    printf("%i ", teste.chave);
    teste.chave = 3;
    insere_pilha(pilha, teste);
    printf("%i\n", teste.chave);
    printf("%i ", consulta_pilha(pilha));
    remove_pilha(pilha);
    printf("%i ", consulta_pilha(pilha));
    remove_pilha(pilha);
    printf("%i\n", consulta_pilha(pilha));
    remove_pilha(pilha);
    printf("%i", tamanho_pilha(pilha));
    libera_pilha(pilha);
    return 0;
}

/* FUNÇÕES E PROCEDIMENTOS */
Pilha *cria_pilha() {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if(pilha != NULL) *pilha = NULL;
    return pilha;
}


void libera_pilha(Pilha *pilha) {
    if(pilha != NULL) {
        No *no;
        while((*pilha) != NULL) {
            no = *pilha;
            *pilha = (*pilha)->prox;
            free(no);
            no = NULL;
        }
        free(pilha);
        pilha = NULL;
    }
}


int tamanho_pilha(Pilha *pilha) {
    if(pilha == NULL) return -1;
    int cont = 0;
    No *no = *pilha;
    while(no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}


int pilha_vazia(Pilha *pilha) {
    if(pilha == NULL) return -1;
    if(*pilha == NULL) return 1;
    return 0;
}


void insere_pilha(Pilha *pilha, Dados dados) {
    if(pilha == NULL) return;
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL) return;
    aux->dados = dados;
    aux->prox = *pilha;
    *pilha = aux;
}


void remove_pilha(Pilha *pilha) {
    if(pilha == NULL || *pilha == NULL) return;
    No *aux = *pilha;
    *pilha = aux->prox;
    free(aux);
    aux = NULL;
}


int consulta_pilha(Pilha *pilha) {
    if(pilha == NULL || *pilha == NULL) exit(1);
    return (*pilha)->dados.chave;
}
