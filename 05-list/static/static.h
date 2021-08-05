#ifndef STATIC_H
#define STATIC_H

/*
- prototipos das funções
- tipo de dado armazenado na lista
- ponteiro lista
- tamanho do vetor
*/
#define MAX 100 /* tamanho do vetor */

typedef struct {
    int matricula;
    char nome[30];
    float n1, n2, n3;
} aluno;

typedef struct lista Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int insere_lista_final(Lista *li, aluno al);
int insre_lista_inicio(Lista *li, aluno al);
int insere_lista_crescente(Lista *li, aluno al);

#endif