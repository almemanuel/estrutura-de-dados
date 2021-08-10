#include <stdio.h>
#include<stdlib.h>

/* DEFINIÇÃO DAS STRUCTS */
typedef struct {
    int valor;
} Dado;


typedef struct No {
    Dado chave;
    struct No *prox;
} No;

typedef struct No *Lista;


/* PROTÓTIPOS */
int lista_vazia(Lista *cabeca);
Lista *cria_lista();
void libera_lista(Lista *cabeca);
int tamanho_lista(Lista *cabeca);
void insere_lista_inicio(Lista *cabeca, Dado dado);
void insere_lista_final(Lista *cabeca, Dado dado);
/*void insere_lista_ordenada(Lista *cabeca, Dado dado); SUBSTITUIR PELAS FUNCÕES ABAIXO */
void insere_lista_pos(); // consertar
int ordem_lista(); // fazer
void ordena_crescente(); // fazer
void ordena_decrescente(); // fazer
void remove_lista_inicio(Lista *cabeca);
void remove_lista_final(Lista *cabeca);
void remove_chave(Lista *cabeca, int chave); /* checar */
void remove_pos(); // fazer
void exclui_repeticoes(); // fazer
int consulta_lista_pos(Lista *cabeca, int pos);
int consulta_lista_chave(Lista *cabeca, int chave);
void imprime_lista(); // fazer
Lista *copia_lista(); // fazer
void inverte_lista(); // fazer


/* PROGRAMA PRINCIPAL */
int main() {
    Lista *cabeca = cria_lista();
    Dado teste;
    teste.valor = 0;
    insere_lista_inicio(cabeca, teste);
    teste.valor = 1;
    insere_lista_inicio(cabeca, teste);
    teste.valor = 2;
    insere_lista_inicio(cabeca, teste);
    teste.valor = 3;
    insere_lista_inicio(cabeca, teste);

    teste.valor = 4;
    insere_lista_pos(cabeca, teste, 1);
    printf("%i", consulta_lista_pos(cabeca, 1));

    libera_lista(cabeca);

    return 0;
}


/* FUNÇÕES */
int lista_vazia(Lista *cabeca) {
    if(cabeca == NULL || *cabeca == NULL) return 1; /* lista vazia */
    return 0; /* lista preenchida */
}


Lista *cria_lista() {
    Lista *cabeca = (Lista *) malloc(sizeof(Lista)); /* endereço para o primeiro nó */
    if(cabeca != NULL)
        *cabeca = NULL; /* quando criada, a lista é vazia, e, portanto, aponta para NULL */
    return cabeca;
}


void libera_lista(Lista *cabeca) {
    if(cabeca == NULL) return;

    No *no;
    while((*cabeca) != NULL) {
        no = *cabeca; /* nó será auxiliar que recerá o inicio da lista */
        *cabeca = (*cabeca)->prox; /* o inicio da lista receberá o seu proximo elemento */
        free(no); /* no, que guarda o antigo primeiro elemento, é descartado */
        no = NULL;
    }
    free(cabeca); /* por fim, descarta a lista */
    cabeca = NULL;
}


int tamanho_lista(Lista *cabeca) {
    if(cabeca == NULL) return 0; /* Lista vazia */
    int tam = 0;
    No *no = *cabeca; /* nó será um ponteiro auxiliar que percorrerá toda lista */
    while(no != NULL) {
        tam++;
        no = no->prox;
    }
    return tam;
}


void insere_lista_inicio(Lista *cabeca, Dado dado) {
    if(cabeca == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return; /* lista nao existe */
    }
    No *no = (No *) malloc(sizeof(No)); /* cria o nó */
    if(no == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return; /* significa que não foi possível alocar memória */
    }
    no->chave = dado; /* ele recebe como chave o dado informado */
    no->prox = *cabeca; /* o próximo do nó é o endereço armazenado na lista */
    *cabeca = no; /* a cabeça passa a apontar para o nó */
}


void insere_lista_final(Lista *cabeca, Dado dado) {
    if(cabeca == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return; /* lista nao existe */
    }
    No *no = (No *) malloc(sizeof(No)); /* cria o nó */
    if(no == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return; /* significa que não foi possível alocar memória */
    }
    no->chave = dado;
    no->prox = NULL; /* aponta para NULL, marcando o fim da lista */
    if((*cabeca) == NULL)
        *cabeca = no; /* lista vazia -> nó torna-se primeiro elemento */
    else {
        No *aux = *cabeca; /* ponteiro auxiliar equivalendo o inicio da lista */
        while(aux->prox != NULL)
            aux = aux->prox; /* o auxiliar recebera sempre o seguinte até que o proximo seja NULL */
        aux->prox = no;
    }
}


/*void insere_lista_ordenada(Lista *cabeca, Dado dado) {
    if(cabeca == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    No *no = (No *) malloc(sizeof(No));
    if(no == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    no->chave = dado;
    if(lista_vazia(cabeca)) {
        no->prox = *cabeca;
        return;
    } else {
        No *ant, *atual = *cabeca;
        while(atual != NULL && atual->chave.valor < dado.valor) {
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *cabeca) {
            no->prox = *cabeca;
            *cabeca = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
}*/


void insere_lista_pos(Lista *cabeca, Dado dados, int pos) {
    if(cabeca == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    No *novo = (No *) malloc(sizeof(No));
    if(novo == NULL) {
        printf("nao eh possivel adicionar o no\n");
        return;
    }
    novo->chave = dados;
    if(lista_vazia(cabeca)) {
        novo->prox = *cabeca;
        return;
    } else {
        No *atual = *cabeca;
        int i = 0;
        while(atual != NULL) {
            atual = atual->prox;
            i++;
        }
        if(pos < i) {
            No *ant = *cabeca;
            for(i = 0; i < pos; i++) {
                ant = ant->prox;
            }
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
}


void remove_lista_inicio(Lista *cabeca) {
    if(lista_vazia(cabeca)) {
        printf("nao foi possivel remover o no\n");
        return;
    }

    No *no = *cabeca; /* no que armazena o inicio da lista */
    *cabeca = no->prox; /* inicio da lista recebe o valor do segundo no */
    free(no); /* remove o no, que armazena o antigo primeiro elemento */
    no = NULL;
}


void remove_lista_final(Lista *cabeca) {
    if(lista_vazia(cabeca)) {
        printf("nao foi possivel remover o no\n");
        return;
    }
    No *ant, *no = *cabeca;
    while(no->prox != NULL) {
        ant = no; /* no anterior recebe o no */
        no = no->prox; /* no recebe o valor do seu proximo */
    }
    if(no == *cabeca)
        *cabeca = no->prox; /* siginifica que a lista continha só um elemento, que será removido nessa linha */
    else
        ant->prox = no->prox; /* caso contrário, o valor anterior ao no apontará para o proximo de nó */
    free(no);
    no = NULL;
}


void remove_chave(Lista *cabeca, int chave) {
    if(cabeca == NULL) {
        printf("nao foi possivel remover o no\n");
        return;
    }
    No *ant, *no = *cabeca;
    while(no != NULL && no->chave.valor != chave) {
        ant = no; /* valor anterior recebe o no atual */
        no = no->prox; /* no se tornara no seu proximo */
    }
    if(no == NULL) {
        printf("nao foi possivel remover o no\n");
        return; /* elemento não encontrado */
    }

    if(no == *cabeca) /* lista com apenas um elemento */
        *cabeca = no->prox; /* isso levará a apontar NULL */
    else
        ant->prox = no->prox; /* o proximo do anterior se tornara no proximo do atual */
    free(no);
    no = NULL;
}


int consulta_lista_pos(Lista *cabeca, int pos) {
    if(cabeca == NULL || pos <= 0) return -1;
    No *no = *cabeca; /* auxiliar apontando para o inicio */
    int i = 1;
    while(no != NULL && i < pos) {
        no = no->prox; /* auxiliar torna-se no seu proximo valor */
        i++;
    }
    if(no == NULL) /* não existe a posição */
        return -1;
    return no->chave.valor; /* retorna o valor */
}


int consulta_lista_chave(Lista *cabeca, int chave) {
    if(cabeca == NULL) return 0;
    No *no = *cabeca;
    int i = 1;
    while(no != NULL && no->chave.valor != chave)
        no = no->prox; /* no torna-se no proximo */
        i++;
    if(no == NULL)
        return 0; /* chave nao existe */
    return i; /* retorna a posição da chave */
}

