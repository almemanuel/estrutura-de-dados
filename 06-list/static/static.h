#ifndef STATIC_H
#define STATIC_H

/*
- prototipos das funções
- tipo de dado armazenado na lista
- ponteiro lista
- tamanho do vetor
*/
#define MAX 50 /* tamanho do vetor */

typedef struct {
    int matricula;
    char nome[30];
    float media;
} aluno;

typedef struct lista Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int insere_lista_final(Lista *li, aluno al);
int insere_lista_inicio(Lista *li, aluno al);
int insere_lista_crescente(Lista *li, aluno al);
int remove_lista_final(Lista *li);
int remove_lista_inicio(Lista *li);
int remove_matricula(Lista *li, int mat);
int consulta_lista_pos(Lista *li, int pos, aluno *al);
int consulta_lista_mat(Lista *li, int mat, aluno *al);
void imprime_lista(Lista *li);
int ordem_lista(Lista *li);
void copia_lista(Lista *nova, Lista *li);
void copia_lista_sem_repeticoes(Lista *repeticao, Lista *sem_repeticao, Lista *li);
void copia_invertida(Lista *invertida, Lista *li);
void inverte_lista(Lista *li);
void lista_mesclada_intercalada(Lista *mesclada, Lista *li1, Lista *li);
void ordena_lista(Lista *li);
float media_global(Lista *li);
int total_abaixo(Lista *li);
int total_acima(Lista *li);

#endif