/* RESUMO */
/* Tipo de lista onde cada elemento aponta para o seu sucessor e para o seu antecessor na lista
Usa um ponteiro especial para o primeiro ponteiro e uma indicação de final de lista, nos dois sentidos
- Cada elemento é tratado como um ponteiro que é alocado dinamicamente, a medida que os dados são inseridos
- Para guardar o primeiro elemento, utilizamos um ponteiro para ponteiro

|ant|chave|prox|
            inicio
              |
   NULL <--| |33| |-->| |23| |-->| |16| |--> NULL
           | |  | |<--| |  | |<--| |  | |

Vantagens:
- melhor utilização dos recursos de memória
- não precisa movimentos os elementos nas operações de inserção e remoção
Desvantagens:
- acesso indireto aos elementos
- necessidade de percorrer a lista para acessar um elemento
Útil:
- sem necessidade de garantis espaço mínimo para execução do aplicativo
- inserção/remocação em lista ordenada são as operações mais frequente
- necessidade de acessar informação de um elemento antecessor
*/

#include<stdio.h>
#include<stdlib.h>

/* STRUCTS */
typedef struct dados {
    int chave;
} Dados;

typedef struct no {
    struct no *ant;
    Dados dados;
    struct no *prox;
} No;

typedef struct no *Lista;

/* PROTÓTIPOS */
Lista *cria_lista();
void libera_lista(Lista *lista);
int tamanho_lista(Lista *lista);
int lista_vazia(Lista *lista);
void insere_lista_inicio(Lista *lista, Dados dados);
void insere_lista_final(Lista *lista, Dados dados);
void insere_lista_ordenada(Lista *lista, Dados dados); /* subtituir esta função por funções de ordenação e adição ordenada */
void remove_lista_inicio(Lista *lista);
void remove_lista_final(Lista *lista);
void remove_lista(Lista *lista, Dados dados);
int consulta_lista_pos(Lista *lista, int pos);
int consulta_lista_chave(Lista *lista, int chave);

/* PROGRAMA PRINCIPAL */
int main() {
    Lista *lista = cria_lista();
    printf("%i ", tamanho_lista(lista));
    Dados teste;
    teste.chave = 1;
    insere_lista_inicio(lista, teste);
    printf("%i ", tamanho_lista(lista));
    teste.chave = 2;
    insere_lista_final(lista, teste);
    printf("%i ", tamanho_lista(lista));
    libera_lista(lista);
    return 0;
}

/* FUNÇÕES E PROCEDIMENTOS */
Lista *cria_lista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if(lista != NULL)
        *lista = NULL;
    return lista;
}


void libera_lista(Lista *lista) {
    if(lista != NULL) {
        No *no;
        while(*lista != NULL) {
            no = *lista;
            *lista = (*lista)->prox;
            free(no);
            no = NULL;
        }
        free(lista);
        lista = NULL;
    }
}


int tamanho_lista(Lista *lista) {
    if(lista == NULL) return -1;
    int cont = 0;
    No *no = *lista;
    while(no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}


int lista_vazia(Lista *lista) {
    if(lista == NULL || *lista == NULL) return 1;
    return 0;
}


void insere_lista_inicio(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return;
    no->dados = dados;
    no->prox = *lista;
    no->ant = NULL;

    if(*lista != NULL)
        (*lista)->ant = no;
    *lista = no;
}


void insere_lista_final(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return;
    no->dados = dados;
    no->prox = NULL;
    if(*lista == NULL) {
        no->ant = NULL;
        *lista = no;
    } else {
        No *aux = *lista;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
        no->ant = aux;
    }
}


void insere_lista_ordenada(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) return;
    no->dados = dados;
    if(lista_vazia(lista)) {
        insere_lista_inicio(lista, dados);
    } else {
        No *ant, *atual = *lista;
        while(atual != NULL && atual->dados.chave < dados.chave) {
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *lista) {
            insere_lista_inicio(lista, dados);
        } else {
            no->prox = ant->prox;
            no->ant = ant;
            ant->prox = no;
        }
    }
}


void remove_lista_inicio(Lista *lista) {
    if(lista_vazia(lista)) return;

    No *no = *lista;
    *lista = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    no = NULL;
}


void remove_lista_final(Lista *lista) {
    if(lista_vazia(lista)) return;
    No *no = *lista;
    while(no->prox != NULL)
        *lista = no->prox;
    if(no->ant == NULL)
        *lista = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    no = NULL;
}


void remove_lista(Lista *lista, Dados dados) {
    if(lista == NULL) return;
    No *no = *lista;
    while(no != NULL && no->dados.chave != dados.chave)
        no = no->prox;
    if(no == NULL)
        return;
    if(no->ant == NULL)
        *lista = no->prox;
    else
        no->ant->prox = no->prox;

    if(no->prox != NULL)
        no->prox->ant = no->ant;

    free(no);
    no = NULL;
}


int consulta_lista_pos(Lista *lista, int pos) {
    if(lista == NULL || pos <= 0) return -1;
    No *no = *lista;
    int i = 1;
    while(no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    if(no == NULL) return -1;
    else {
        return no->dados.chave;
    }
}


int consulta_lista_chave(Lista *lista, int chave) {
    if(lista == NULL) return -1;
    No *no = *lista;
    while(no != NULL && no->dados.chave != chave) {
        no = no->prox;
    }
    if(no == NULL)
        return -1;
    else {
        return no->dados.chave;
    }
}

