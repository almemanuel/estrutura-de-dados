#include<stdio.h>
#include<stdlib.h>

#define MAX 100

/* STRUCT */
typedef struct dados {
    int chave;
} Dados;

typedef struct pilha {
    int qtd;
    Dados dados[MAX];
} Pilha;

/* PROTÓTIPOS */
Pilha *cria_pilha();
void libera_pilha(Pilha *pilha);
int tamanho_pilha(Pilha *pilha);
int pilha_cheia(Pilha *pilha);
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
    Pilha *pilha;
    pilha = (Pilha *) malloc(sizeof(Pilha));
    if(pilha != NULL) pilha->qtd = 0;
    return pilha;
}


void libera_pilha(Pilha *pilha) {
    free(pilha);
    pilha = NULL;
}


int tamanho_pilha(Pilha *pilha) {
    if(pilha == NULL) return -1;
    return pilha->qtd;
}


int pilha_cheia(Pilha *pilha) {
    if(pilha == NULL) return -1;
    return pilha->qtd == MAX;
}


int pilha_vazia(Pilha *pilha) {
    if(pilha == NULL) return -1;
    return pilha->qtd == 0;
}


void insere_pilha(Pilha *pilha, Dados dados) {
    if(pilha == NULL || pilha_cheia(pilha)) return;
    pilha->dados[pilha->qtd] = dados;
    pilha->qtd++;
}


void remove_pilha(Pilha *pilha) {
    if(pilha == NULL || pilha->qtd == 0) return;
    pilha->qtd--;
}


int consulta_pilha(Pilha *pilha) {
    if(pilha == NULL || pilha->qtd == 0) exit(1);
    return pilha->dados[pilha->qtd - 1].chave;
}
