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


/*void insere_lista_ordenada(Lista *lista, Dados dados) {
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
} */


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
        novo->prox = *lista;
        return;
    } else {
        No *atual = *lista;
        int i = 0;
        do {
            atual = atual->prox;
            i++;
        } while(atual != *lista);
        if(pos <= i) {
            No *ant = *lista;
            for(i = 0; i < pos - 1; i++) {
                ant = ant->prox;
            }
            novo->prox = ant->prox;
            ant->prox = novo;
        } else {
            printf("nao foi possivel adicionar o no\n");
            return;
        }
    }
}


void remove_lista_inicio(Lista *lista) {
    if(lista == NULL) return;
    if(*lista == NULL) return;
    if(*lista == (*lista)->prox) {
        free(*lista);
        *lista = NULL;
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


void remove_chave(Lista *lista, int chave) {
    if(lista == NULL) return;
    if(*lista == NULL) return;
    No *no = *lista;
    if(no->dados.chave == chave) {
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
    while(no != *lista && no->dados.chave != chave) {
        ant = no;
        no = no->prox;
    }
    if(no == *lista) return;
    ant->prox = no->prox;
    free(no);
    no = NULL;
}

/*
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
*/

void remove_pos(Lista *lista, int pos) {
    if(lista == NULL || *lista == NULL || pos <= 0) {
        return;
    }
    No *no = *lista;
    int i = 1;
    while(no->prox != *lista && i < pos) {
        no = no->prox;
        i++;
    }
    int chave;
    if(i != pos) return;
    else {
        chave = no->dados.chave;
    }

    no = *lista;
    if(no->dados.chave == chave) {
        if(no == no->prox) {
            remove_lista_inicio(lista);
        } else {
            No *ult = *lista;
            int j = 1;
            while(ult->prox != *lista && j != i)
                ult = ult->prox;
                j++;
            ult->prox = (*lista)->prox;
            *lista = (*lista)->prox;
            free(no);
            no = *lista;
        }
        return;
    }
    No *ant = no;
    no = no->prox;
    while(no != *lista && no->dados.chave != chave) {
        ant = no;
        no = no->prox;
    }
    if(no == *lista) return;
    ant->prox = no->prox;
    free(no);
    no = NULL;
}

void imprime_lista(Lista *lista) {
    if(lista_vazia(lista)) return;

    No *aux = *lista;
    do {
        printf("%i ", aux->dados.chave);
        aux = aux->prox;
    } while(aux != *lista);
    printf("\n");
}

