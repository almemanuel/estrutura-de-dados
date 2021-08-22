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

/* PROGRAMA PRINCIPAL */

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
