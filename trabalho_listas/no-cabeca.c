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
int lista_vazia(Lista *lista);
void libera_lista(Lista *lista);
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
    if(lista != NULL) {
        lista->inicio = NULL;
        lista->final = NULL;
        lista->qtd = 0;
    }
    return lista;
}


int lista_vazia(Lista *lista) {
    if(lista == NULL || lista->qtd == 0) return 1;
    return 0;
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
        if(pos > 0) {
            printf("nao foi possivel adicionar o no\n");
            return;
        }
        novo->prox = lista->inicio;
        lista->qtd++;
        return;
    } else {
        No *atual = lista->inicio;
        int i = 0;
        while(atual != NULL) {
            atual = atual->prox;
            i++;
        }
        if(pos <= i) {
            No *ant = lista->inicio;
            for(i = 0; i < pos - 1; i++) {
                ant = ant->prox;
            }
            novo->prox = ant->prox;
            ant->prox = novo;
            lista->qtd++;
        } else {
            printf("nao foi possivel adicionar o no\n");
            return;
        }
    }
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


void remove_chave(Lista *lista, int chave) {
    if(lista == NULL) {
        return;
    }
    No *ant, *no = lista->inicio;
    int i = 0;
    while(i < lista->qtd && no->dados.chave != chave) {
        ant = no;
        no = no->prox;
        i++;
    }
    if(i == lista->qtd) {
        return;
    }

    if(no == lista->inicio)
        lista->inicio = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    no = NULL;
    lista->qtd--;
    remove_chave(lista, chave);
}


void remove_pos(Lista *lista, int pos) {
    if(lista == NULL || pos < 0) return;
    if(pos == 0) {
        remove_lista_inicio(lista);
        return;
    }
    No *no = lista->inicio;
    int i = 0;
    while(no != NULL && i <= pos - 1) {
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return;
    int j = 0;
    no = lista->inicio;
    No *ant = (No *) malloc(sizeof(No));
    while(j != i) {
        ant = no;
        no = no->prox;
        j++;
    }

    ant->prox = no->prox;

    free(no);
    no = NULL;
    lista->qtd--;
}


void imprime_lista(Lista *lista) {
    if(lista == NULL) return;

    No *aux;
    int i;
    for(aux = lista->inicio, i = 0; i < lista->qtd; aux = aux->prox, i++) {
        printf("%i ", aux->dados.chave);
    }
    printf("\n");
}
