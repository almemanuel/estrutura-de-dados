/*
Lista onde cada elemento aponta para o seu sucessor e o último elemento aponta para o primeiro
Logo, não existe final na lista

        inicio
           |
dados     |33| |-->|23| |-->|16| |--¬
       |->|__|_|   |__|_|   |__|_|  |
       |____________________________|

- cada elemento é tratado como um ponteiro alocado dinamicamente a medida que os dados são inseridos
- para o primeiro elemento, é utilizado um ponteiro de ponteiro

Vantagens:
- melhor utilização da memória
- não precisa movimentar os elementos nas operações de inserção e remoção
- possibilidade de percorrer a lista diversas vezes
- não precisa-se considerar casos especiais de inclusão e remoção (primeiro e último)

Desvantagens:
- acesso indireto
- necessidade de percorrer a lista para acessar um elemento
- lista não possui final definido

Usar quando:
- não há necessidade de garantir um espaço mínimo para a execução do aplicativo
- inserção/remoção em lista ordenada são as operações mais frequentes
- quando há necessidade de voltar ao primeiro item da lista depois de percorrê-la
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

typedef No *Lista;

/* PROTÓTIPOS */
Lista *cria_lista();
void libera_lista(Lista *lista);
int tamanho_lista(Lista *lista);
int lista_vazia(Lista *lista);
void insere_lista_inicio(Lista *lista, Dados dados);
void insere_lista_final(Lista *lista, Dados dados);
void insere_lista_ordenada(Lista *lista, Dados dados); /*substituir por funções que ordenem*/
void remove_lista_inicio(Lista *lista);
void remove_lista_final(Lista *lista);
void remove_lista(Lista *lista, Dados dados);
int consulta_lista_pso(Lista *lista, int pos);
int consulta_lista_chave(Lista *lista, int chave);

/* PROGRAMA PRINCIPAL */

/* FUNÇÕES E PROCEDIMENTOS */
Lista *cria_lista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if(lista != NULL) *lista = NULL;
    return lista;
}


void libera_lista(Lista *lista) {
    if(lista != NULL && *lista != NULL) {
        No *aux, *no = *lista;
        while(*lista != no->prox) {
            aux = no;
            no = no->prox;
            free(aux);
            aux = NULL;
        }
        free(no);
        no = NULL;
        free(lista);
        lista = NULL;
    }
}


int tamanho_lista(Lista *lista) {
    if(lista == NULL || *lista == NULL) return -1;
    int cont = 0;
    No *no = *lista;
    do {
        cont++;
        no = no->prox;
    } while(no != *lista);
    return cont;
}


int lista_vazia(Lista *lista) {
    if(lista == NULL && *lista == NULL)
        return 1;
    else
        return 0;
}


void insere_lista_inicio(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return;
    no->dados = dados;
    if(*lista == NULL) {
        *lista = no;
        no->prox = no;
    } else {
        No *aux = *lista;
        while(aux->prox != *lista)
            aux = aux->prox;
        aux->prox = no;
        no->prox = *lista;
        *lista = no;
    }
}


void insere_lista_final(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return;
    no->dados = dados;
    if(*lista == NULL) {
        insere_lista_inicio(lista, dados);
    } else {
        No *aux = *lista;
        while(aux->prox != *lista)
            aux = aux->prox;
        aux->prox = no;
        no->prox = *lista;
    }
}


void insere_lista_ordenada(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL)
        return 0;
    no->dados = dados;
    if(*lista == NULL) insere_lista_inicio(lista, dados);
    else if((*lista)->dados.chave > dados.chave) {
        No *atual = *lista;
        while(atual->prox != *lista) {
            atual = atual->prox;
            no->prox = *lista;
            atual->prox = no;
            *lista = no;
            return;
        }
    }
    No *ant = *lista, *atual = (*lista)->prox;
    while(atual != *lista && atual->dados.chave < dados.chave) {
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = no;
    no->prox = atual;
}


void remove_lista_inicio(Lista *lista) {
    if(lista == NULL) return;
    if(*lista == NULL) return;
    if(*lista == (*lista)->prox) {
        libera_lista(lista);
        return;
    }
    No *atual = *lista;
    while(atual->prox != *lista)
        atual = atual->prox;
    No *no = *lista;
    atual->prox = no->prox;
    *lista = no->prox;
    free(no);
    no = NULL;
}


void remove_lista_final(Lista *lista) {
    if(lista == NULL) return;
    if(*lista == NULL) return;
    if(*lista == (*lista)->prox) {
        libera_lista(lista);
        return;
    }
    No *ant, *no = *lista;
    while(no->prox != *lista) {
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    no = NULL;
}


void remove_lista(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    if(*lista == NULL) return;
    No *no = *lista;
    if(no->dados.chave == dados.chave) {
        if(no == no->prox) {
            remove_lista_inicio(lista);
        } else {
            No *ult = *lista;
            while(ult->prox != *lista)
                ult = ult->prox;
            ult->prox = (*lista)->prox;
            *lista = (*lista)->prox;
            free(no);
            no = NULL;
        }
        return;
    }
    No *ant = no;
    no = no->prox;
    while(no != *lista && no->dados.chave != dados.chave) {
        ant = no;
        no = no->prox;
    }
    if(no == *lista) return;
    ant->prox = no->prox;
    free(no);
    no = NULL;
}


int consulta_lista_pos(Lista *lista, int pos) {
    if(lista == NULL || *lista == NULL || pos <= 0) {
        return -1;
    }
    No *no = *lista;
    int i = 1;
    while(no->prox != *lista && i < pos) {
        no = no->prox;
        i++;
    }
    if(i != pos) return -1;
    else {
        return no->dados.chave;
    }
}


int consulta_lista_chave(Lista *lista, int chave) {
    if(lista == NULL || *lista == NULL) return -1;
    No *no = *lista;
    int i = 0;
    while(no->prox != *lista && no->dados.chave != chave) {
        no = no->prox;
        i++;
    }
    if(no->dados.chave != chave)
        return -1;
    else
        return i;
}

