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
void insere_lista_pos(Lista *lista, Dados dados, int pos);
void remove_lista_inicio(Lista *lista);
void remove_chave(Lista *lista, int chave);
void remove_pos(Lista *lista, int pos);
void imprime_lista(Lista *lista);

/* PROGRAMA PRINCIPAL */
int main() {
    Lista *l = cria_lista();
    Dados d;
    int pos, chave, opc;

    do {
        printf("---------------MENU----------------\n");
        printf("\t1 - Inserir no inicio\n");
        printf("\t2 - Inserir numa posicao especifica\n");
        printf("\t3 - Remover primeira posicao\n");
        printf("\t4 - Remover uma chave especifica\n");
        printf("\t5 - Remover uma posicao especifica\n");
        printf("\t0 - Sair\n");
        printf("Informe uma opcao: ");
        scanf("%i", &opc);

        switch(opc) {
            case 1:
                printf("\nInforme um valor inteiro para ser inserido ao inicio: ");
                scanf("%i", &(d.chave));
                insere_lista_inicio(l, d);
                printf("Exibindo lista atual: ");
                imprime_lista(l);
            break;

            case 2:
                printf("\nInforme um valor inteiro para ser inserido e outro inteiro indicando a posicao: ");
                scanf("%i %i", &(d.chave), &pos);
                insere_lista_pos(l, d, pos);
                printf("Exibindo lista atual: ");
                imprime_lista(l);
            break;

            case 3:
                printf("\nRemovendo primeira valor da lista...\n");
                remove_lista_inicio(l);
                printf("Exibindo lista atual: ");
                imprime_lista(l);
            break;

            case 4:
                printf("\nInforme o valor inteiro que deseja remover as ocorrencias: ");
                scanf("%i", &chave);
                remove_chave(l, chave);
                printf("Exibindo lista atual: ");
                imprime_lista(l);
            break;

            case 5:
                printf("\nInforme a posicao do elemento de deseja remover: ");
                scanf("%i", &pos);
                remove_pos(l, pos);
                printf("Exibindo lista atual: ");
                imprime_lista(l);
            break;

            case 0:
                printf("\nENCERRANDO\n");
            break;

            default:
                printf("\nVALOR INVALIDO\n");
            break;
        }
    } while(opc != 0);
    libera_lista(l);
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


void insere_lista_pos(Lista *lista, Dados dados, int pos) {
    if(lista == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    No *novo = (No *) malloc(sizeof(No));
    if(novo == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    novo->dados = dados;
    if(lista_vazia(lista)) {
        if(pos < 0) {
            printf("nao foi possivel adicionar o no\n");
            return;
        }
        novo->prox = *lista;
        return;
    } else {
        if(pos == 0) {
            insere_lista_inicio(lista, dados);
            return;
        }
        No *ant, *atual = *lista;
        int i = 0;
        while(atual != NULL && i < pos) {
            ant = atual;
            atual = atual->prox;
            i++;
        }
        if(pos == i) {
            novo->prox = ant->prox;
            novo->ant = ant;
            ant->prox = novo;
        } else {
            printf("nao foi possivel adicionar o no\n");
            return;
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


void remove_chave(Lista *lista, int chave) {
    if(lista == NULL) return;
    No *no = *lista;
    while(no != NULL && no->dados.chave != chave)
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
    remove_chave(lista, chave);
}


void remove_pos(Lista *lista, int pos) {
    if(lista == NULL || pos < 0) return;
    if(pos == 0) {
        remove_lista_inicio(lista);
        return;
    }
    No *no = *lista;
    int i = 0;
    while(no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    if(no == NULL && i != pos)
        return;
    if(no->ant == NULL) *lista = no->prox;
    else no->ant->prox = no->prox;

    free(no);
    no = NULL;
}


void imprime_lista(Lista *lista) {
    if(lista == NULL) return;

    No *aux;
    for(aux = *lista; aux != NULL; aux = aux->prox) {
        printf("%i ", aux->dados.chave);
    }
    printf("\n");
}