/* o sucesso de um elemento ocupa a posição física seguinte do mesmo vetor
| qtd | inicio | final |
|  0  |     0  |   3   |
            |       |-|
            v         v
Dados |   | 33 | 23 | 16 |   |     |
Indice| 0 | 01 | 02 | 03 |...|MAX-1|
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* STRUCTS */
typedef struct dados {
    int chave;
} Dados;

typedef struct fila {
    int inicio, final, qtd;
    Dados dados[MAX];
} Fila;

/* PROTÓTIPOS */
Fila *cria_fila();
void libera_fila(Fila *fila);
int tamanho_fila(Fila *fila);
int fila_cheia(Fila *fila);
int fila_vazia(Fila *fila);
void insere_fila(Fila *fila, Dados dados);
void remove_fila(Fila *fila);
Dados consulta_fila(Fila *fila);

/* PROGRAMA PRINCIPAL */
int main() {
    Fila *fila = cria_fila();
    Dados teste;
    teste = consulta_fila(fila);
    printf("%i\n", teste.chave);
    teste.chave = 1;
    insere_fila(fila, teste);
    printf("%i ", teste.chave);
    teste.chave = 2;
    insere_fila(fila, teste);
    printf("%i ", teste.chave);
    teste.chave = 3;
    insere_fila(fila, teste);
    printf("%i\n", teste.chave);
    teste = consulta_fila(fila);
    printf("%i ", teste.chave);
    remove_fila(fila);
    teste = consulta_fila(fila);
    printf("%i ", teste.chave);
    remove_fila(fila);
    teste = consulta_fila(fila);
    printf("%i\n", teste.chave);
    remove_fila(fila);
    printf("%i", tamanho_fila(fila));
    libera_fila(fila);
    return 0;
}

/* FUNÇÕES E PROCEDIMENTOS */
Fila *cria_fila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if(fila != NULL) {
        fila->inicio = 0;
        fila->final = 0;
        fila->qtd = 0;
    } return fila;
}


void libera_fila(Fila *fila) {
    free(fila);
    fila = NULL;
}


int tamanho_fila(Fila *fila) {
    if(fila == NULL) return -1;
    return fila->qtd;
}


int fila_cheia(Fila *fila) {
    if(fila == NULL) return -1;
    if(fila->qtd == MAX) return 1;
    return 0;
}


int fila_vazia(Fila *fila) {
    if(fila == NULL) return -1;
    if(fila->qtd == 0) return 1;
    return 0;
}


void insere_fila(Fila *fila, Dados dados) {
    if(fila == NULL) return;
    if(fila_cheia(fila)) return;
    fila->dados[fila->final] = dados;
    fila->final = (fila->final + 1) % MAX;
    fila->qtd++;
}


void remove_fila(Fila *fila) {
    if(fila == NULL || fila_vazia(fila)) return;
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->qtd--;
}


Dados consulta_fila(Fila *fila) {
    if(fila == NULL) exit(1);
    return fila->dados[fila->inicio];
}
