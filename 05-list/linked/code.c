#include<stdio.h>
#include<stdlib.h>
#include "linked.h"
/*
Lista Dinâmica Encadeada:
tipo de lista onde cada elemento aponta para o seu sucessor
        topo -> chave
                prox -> chave
                NÓ      prox -> chave
                        NÓ      prox -> chave
                                NÓ      prox -> NULL
                                        NÓ

usa um ponteiro especial para o primeiro elemento da lista e uma indicacao para o final
cada elemento contém uma chave e o campo proximo
cada elemento é tratado como ponteiro que é alocado dinamicamento
        Para guardar o primeiro elemento, utilizamos ponteiro para ponteiros; o restante dos nós
        serão ponteiros simples
                um ponteiro para ponteiro pode guardar o endereço de um ponteiro. no caso, guarda o valor do primeiro 
                elemento

Vantagens:
- melhor utilização de memória
- não precisa movimento os elementos nas operações de inserção e remoção

Desvantagens:
- acesso direto aos elementos
- necessidade de percorrer a lista para acessar um elemento

Utilidade:
- não há necessidade de garantir um espaço mínimo para a execução
- inserção/remoção em lista ordenada são as operações mais frequentes

Inserções:
- no início
- no meio
- no final

O nó-cabeça é o primeiro nó, usado para várias operações e verificações, e marca o inicio da lista
*/

int main() {
        Lista *lista; // como Lista é ponteiro, *lista é ponteiro para ponteiro
        lista = cria_lista();
        printf("%p %i", lista, lista_vazia(lista));
        libera_lista(lista);
}