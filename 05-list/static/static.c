#include <stdio.h>
#include<stdlib.h>
#include "static.h"

/*
- tipo de dados
- implementação das funções
*/

struct lista {
    int qtd; /* qtd diz, além da quantidade de dados, qual é a primeira posição vaga */
    aluno dados[MAX];
};


Lista *cria_lista() {
    Lista *li;
    li = (Lista *) malloc(sizeof(struct lista));

    /* se a alocação funcionar, ele definirá 0 como qtd inicial preenchida
    e apontará para a posição 0, que será a primeira a ser preenchida*/
    if(li != NULL)
        li->qtd = 0;
    return li;
}


void libera_lista(Lista *li) {
    free(li);
    li = NULL;
}


int tamanho_lista(Lista *li) {
    if(li == NULL)
        return -1; /* código de erro */
    else
        return li->qtd; /* retorna o campo qtd de li */
}


int lista_cheia(Lista *li) {
    if(li == NULL)
        return -1;
    return(li->qtd == MAX); /* se quantidade ja é max, então a proxima posição já está fora da lista e retorna o booleano */
}


int lista_vazia(Lista *li) {
    if(li == NULL)
        return -1;
    return (li->qtd == 0); /* se qtd é 0, então a lista está vazia. o retorno será um booleano */
}


int insere_lista_final(Lista *li, aluno al) {
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->dados[li->qtd] = al; /* a posição do vetor dados apontado por quantidade recebe al */
    li->qtd++; /* aumenta a quantidade de elementos na lista */
    return 1; /* código para sucesso */
}


int insere_lista_inicio(Lista *li, aluno al) {
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int i;
    for(i = li->qtd - 1; i>=0; i--) /* desloca cada elemento para a posicão da frente */
        li->dados[i + 1] = li->dados[i];
    li->dados[0] = al; /* atribui valor ao primeiro elemento */
    li->qtd++; /* incrementa a quantidade de dados existentes na lista */
    return 1;
}


int insere_lista_crescente(Lista *li, aluno al) {
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int k, i = 0;
    /* enquanto i for menor que qtd e a matricula da lista for menor que a do novo aluno, ele incrementará */
    /* ele buscará a posição onde o elemento de trás será menor e a da frente maior */
    while(i < li->qtd && li->dados[i].matricula < al.matricula)
        i++; /* parará de incrementar com a posição na qual al deverá ser armazenado para que a matricula fique em ordem crescente */

    /* k recebe a quantidade de itens da lista, e será decrementado até i */
    for(k = li->qtd - 1; k >= i; k--)
        li->dados[k + 1] = li->dados[k]; /* o item de indice k + 1 recebe o indice de k, para que o novo valor possa ser inserido no valor de i */
    li->dados[i] = al; /* inserção do novo valor na posição correta */
    li->qtd++; /* incremento do tamanho da lista */
    return 1;
}


int remove_lista_final(Lista *li) {
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--; /* tornará a posição final vaga */
    return 1;
}


int remove_lista_inicio(Lista *li) {
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k;
    /* tornará o elemento atual no próximo elemento */
    for(k = 0; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--; /* decremento na quantidade de itens da lista */
    return 1;
}


int remove_lista(Lista *li, int mat) {
    if(li == NULL) return 0;
    if(li->qtd == 0) return 0;
    int k, i = 0;
    /* busca o elemento na lista */
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;

    /* i = qtd significa que o elemento não foi encontrado */
    if(i == li->qtd)
        return 0;

    /* desloca os elementos a frente do indice correspondente uma posição para trás */
    for(k = i; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}


/* utiliza um ponteiro que irá receber os dados da posição */
int consulta_lista_pos(Lista *li, int pos, aluno *al) {
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos - 1];
    return 1;
}


int consulta_lista_mat(Lista *li, int mat, aluno *al) {
    if(li == NULL)
        return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;

    *al = li->dados[i];
    return 1;
}


void imprime_lista(Lista *li){
    if(!lista_vazia(li)) {
        int i;
        for(i = 0; i < li->qtd; i++)
            printf("%i ", li->dados[i].matricula);
    }
}


int ordem_lista(Lista *li) {
    if(lista_vazia(li)) return 0;

    int i = 0;

    while(i < li->qtd - 1 && li->dados[i].matricula < li->dados[i + 1].matricula)
        i++;
    if(i == li->qtd - 1) return 1; /* crescente */

    i = 0;
    while(i < li->qtd - 1 && li->dados[i].matricula > li->dados[i + 1].matricula)
        i++;
    if(i == li->qtd - 1) return -1; /* decrescente */

    return 0;
}


void copia_lista(Lista *nova, Lista *li) {
    if(lista_vazia(li)) return;

    int i;
    for(i = 0; i < li->qtd; i++)
        insere_lista_final(nova, li->dados[i]);
}


void copia_lista_sem_repeticoes(Lista *repeticao, Lista *sem_repeticao, Lista *li) {
    if(lista_vazia(li)) return;

    int i, j;
    for(i = 0; i < li->qtd; i++) {
        j = 0;
        while(j < i && li->dados[i].matricula != li->dados[j].matricula)
            j++;
        if(j == i) insere_lista_final(sem_repeticao, li->dados[i]);
        else insere_lista_final(repeticao, li->dados[i]);
    }
}


void copia_invertida(Lista *invertida, Lista *li) {
    if(lista_vazia(li)) return;

    int i;
    for(i = 0; i < li->qtd; i++)
        insere_lista_inicio(invertida, li->dados[i]);
}


void inverte_lista(Lista *li) {
    if(lista_vazia(li)) return;

    aluno aux;
    int i;
    int j = li->qtd - 1;
    for(i = 0; i < (li->qtd - 1) / 2; i++) {
        aux = li->dados[j];
        li->dados[j] = li->dados[i];
        li->dados[i] = aux;
        j--;
    }
}

void lista_mesclada_intercalada(Lista *mesclada, Lista *li1, Lista *li) {
    int aux;
    if(li->qtd > li1->qtd) aux = li->qtd;
    else aux = li1->qtd;
    int i;
    for(i = 0; i < aux; i++) {
        if(li->qtd > i)insere_lista_final(mesclada, li->dados[i]);
        if(li1->qtd > i)insere_lista_final(mesclada, li1->dados[i]);
    }
}