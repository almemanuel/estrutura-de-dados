#include <stdio.h>
#include<stdlib.h>

/* TAMANHO MAXIMO */
#define MAX 50


/* DEFINIÇÃO DAS STRUCTS DA LISTA */
typedef struct no {
    int chave;
} No;


typedef struct lista {
    int qtd;
    No dados[MAX];
} Lista;


/* PROTÓTIPOS */
Lista *cria_lista();
void libera_lista(Lista *lista);
int tamanho_lista(Lista *lista);
int lista_cheia(Lista *lista);
int lista_vazia(Lista *lista);
void insere_lista_final(Lista *lista, No no);
void insere_lista_inicio(Lista *lista, No no);
void insere_lista_pos(Lista *lista, No no, int pos);
int ordem_lista(Lista *lista);
void ordena_crescente(Lista *lista);
void ordena_decrescente(Lista *lista);
void remove_lista_final(Lista *lista);
void remove_lista_inicio(Lista *lista);
void remove_chave(Lista *lista, int chave);
void remove_pos(Lista *lista, int pos);
void exclui_repeticoes(Lista *lista);
No consulta_lista_pos(Lista *lista, int pos);
void imprime_lista(Lista *lista);
Lista *copia_lista(Lista *lista);
void inverte_lista(Lista *lista);


/* PROGRAMA PRINCIPAL */
int main() {
    Lista *lista1 = cria_lista();
    Lista *lista2 = cria_lista();
    No testando;
    testando.chave = 0;
    insere_lista_final(lista1, testando);
    testando.chave = 1;
    insere_lista_inicio(lista1, testando);
    testando.chave = 2;
    insere_lista_final(lista1, testando);
    testando.chave = 3;
    insere_lista_inicio(lista1, testando);
    testando.chave = 4;
    insere_lista_inicio(lista1, testando);
    testando.chave = 5;
    insere_lista_final(lista1, testando);
    imprime_lista(lista1);
    printf("\n");

    testando.chave = 6;
    insere_lista_crescente(lista1, testando);
    imprime_lista(lista1);
    printf("\n");

    testando.chave = 7;
    insere_lista_decrescente(lista1, testando);
    imprime_lista(lista1);
    printf("\n");

    remove_chave(lista1, 0);
    imprime_lista(lista1);
    printf("\n");

    remove_pos(lista1, 1);
    imprime_lista(lista1);
    printf("\n");

    testando.chave = 7;
    insere_lista_final(lista1, testando);
    testando.chave = 10;
    insere_lista_final(lista1, testando);
    testando.chave = 10;
    insere_lista_final(lista1, testando);
    testando.chave = 10;
    insere_lista_final(lista1, testando);
    imprime_lista(lista1);
    printf("\n");

    testando.chave = 100;
    insere_lista_pos(lista1, testando, 2);
    imprime_lista(lista1);
    printf("\n");

    exclui_repeticoes(lista1);
    imprime_lista(lista1);
    printf("\n");

    libera_lista(lista1);
}


/* FUNÇÕES */
Lista *cria_lista() {
    Lista *lista;
    lista = (Lista *) malloc(sizeof(Lista));

    if(lista != NULL)
        lista->qtd = 0;
    return lista;
}


void libera_lista(Lista *lista) {
    free(lista);
    lista = NULL;
}


int tamanho_lista(Lista *lista) {
    if(lista == NULL)
        return -1;
    else
        return lista->qtd;
}


int lista_cheia(Lista *lista) {
    if(lista == NULL)
        return -1;
    return(lista->qtd == MAX);
}


int lista_vazia(Lista *lista) {
    if(lista == NULL)
        return -1;
    return (lista->qtd == 0);
}


void insere_lista_final(Lista *lista, No no) {
    if(lista == NULL) {
        printf("nao eh possivel adicionar um no a uma lista nula\n");
        return;
    }
    if(lista_cheia(lista)) {
        printf("nao eh possivel adicionar um no a uma lista cheia\n");
        return;
    }

    lista->dados[lista->qtd] = no;
    lista->qtd++;
}


void insere_lista_inicio(Lista *lista, No no) {
    if(lista == NULL) {
        printf("nao eh possivel adicionar um no a uma lista nula\n");
        return;
    }
    if(lista_cheia(lista)) {
        printf("nao eh possivel adicionar um no a uma lista cheia\n");
        return;
    }

    int i;
    for(i = lista->qtd - 1; i>=0; i--)
        lista->dados[i + 1] = lista->dados[i];
    lista->dados[0] = no;
    lista->qtd++;
}


void insere_lista_pos(Lista *lista, No no, int pos) {
    if(lista == NULL) {
        printf("nao eh possivel adicionar um no a uma lista nula\n");
        return;
    }
    if(lista_cheia(lista)) {
        printf("nao eh possivel adicionar um no a uma lista cheia\n");
        return;
    }
    if(pos < 0 || pos > lista->qtd) {
        printf("posicao invalida! informe uma valor pertencente ao conjunto natural e menor que o tamanho da lista\n");
        return;
    }

    int i;
    for(i = pos; i < lista->qtd; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->dados[pos] = no;
    lista->qtd++;
}


int ordem_lista(Lista *lista) {
    if(lista_vazia(lista)) return 0;

    int i = 0;
    while(i < lista->qtd - 1 && lista->dados[i].chave < lista->dados[i + 1].chave)
        i++;
    if(i == lista->qtd - 1) return 1;

    i = 1;
    while(i < lista->qtd - 1 && lista->dados[i].chave > lista->dados[i + 1].chave)
        i++;
    if(i == lista->qtd - 1) return -1;

    return 0;
}


void ordena_crescente(Lista *lista) {
    if(lista_vazia(lista)) return;
    if(ordem_lista(lista) != 1) {
        int j, i = 0;
        No aux;

        for(i = 0; i < lista->qtd - 1; i++) {
            for(j = 0; j < lista->qtd - 1; j++) {
                if(lista->dados[j].chave > lista->dados[j + 1].chave) {
                    aux = lista->dados[j];
                    lista->dados[j] = lista->dados[j + 1];
                    lista->dados[j + 1] = aux;
                }
            }
        }
    }
}


void ordena_decrescente(Lista *lista) {
    if(lista_vazia(lista)) return;
    if(ordem_lista(lista) != -1) {
        int j, i = 0;
        No aux;

        for(i = 0; i < lista->qtd - 1; i++) {
            for(j = 0; j < lista->qtd - 1; j++) {
                if(lista->dados[j].chave < lista->dados[j + 1].chave) {
                    aux = lista->dados[j];
                    lista->dados[j] = lista->dados[j + 1];
                    lista->dados[j + 1] = aux;
                }
            }
        }
    }
}


void remove_lista_final(Lista *lista) {
    if(lista == NULL) {
        printf("nao eh possivel remover um no a uma lista nula\n");
        return;
    }
    if(lista->qtd == 0) {
        printf("nao eh possivel remover de uma lista vazia\n");
        return;
    }
    lista->qtd--;
}


void remove_lista_inicio(Lista *lista) {
    if(lista == NULL) {
        printf("nao eh possivel remover um no a uma lista nula\n");
        return;
    }
    if(lista->qtd == 0) {
        printf("nao eh possivel remover de uma lista vazia\n");
        return;
    }

    int i;
    for(i = 0; i < lista->qtd - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->qtd--;
}


void remove_chave(Lista *lista, int chave) {
    if(lista == NULL) {
        printf("nao eh possivel remover um no a uma lista nula\n");
        return;
    }
    if(lista->qtd == 0) {
        printf("nao eh possivel remover de uma lista vazia\n");
        return;
    }

    int k, i = 0;
    for(i = 0; i < lista->qtd; i++) {
        if(lista->dados[i].chave == chave) {
            for(k = i; k < lista->qtd; k++) {
                lista->dados[k] = lista->dados[k + 1];
                lista->qtd--;
            }
        }
    }
}


void remove_pos(Lista *lista, int pos) {
    if(lista == NULL) {
        printf("nao eh possivel remover um no a uma lista nula\n");
        return;
    }
    if(lista->qtd == 0) {
        printf("nao eh possivel remover de uma lista vazia\n");
        return;
    }

    int i = 0;
    for(i = pos; i < lista->qtd; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->qtd--;
}


void exclui_repeticoes(Lista *lista) {
    if(lista_vazia(lista)) return;

    int i, j;
    No aux;
    for(i = 0; i < lista->qtd; i++) {
        j = 0;
        for(j = i + 1; j < lista->qtd; j++) {
            if(lista->dados[i].chave == lista->dados[j].chave) {
                remove_pos(lista, j);
                j--;
            }
        }
    }
}


No consulta_lista_pos(Lista *lista, int pos) {
    if(lista == NULL || pos <= 0 || pos > lista->qtd) exit(-1);
    return lista->dados[pos - 1];
}


int consulta_lista_chave(Lista *lista, int chave) {
    if(lista == NULL) return -1;

    int k, i = 0;
    while(i < lista->qtd && lista->dados[i].chave != chave)
        i++;

    if(i == lista->qtd) return -1;
    return i;
}


void imprime_lista(Lista *lista){
    if(!lista_vazia(lista)) {
        int i;
        for(i = 0; i < lista->qtd; i++)
            printf("%i ", lista->dados[i].chave);
    }
}


Lista *copia_lista(Lista *lista) {
    if(lista_vazia(lista)) exit(-1);

    Lista *nova = cria_lista();

    int i;
    for(i = 0; i < lista->qtd; i++) {
        insere_lista_final(nova, lista->dados[i]);
    }
    return nova;
}


void inverte_lista(Lista *lista) {
    if(lista_vazia(lista)) return;

    No aux;
    int i;
    int j = lista->qtd - 1;
    for(i = 0; i < (lista->qtd - 1) / 2; i++) {
        aux = lista->dados[j];
        lista->dados[j] = lista->dados[i];
        lista->dados[i] = aux;
        j--;
    }
}