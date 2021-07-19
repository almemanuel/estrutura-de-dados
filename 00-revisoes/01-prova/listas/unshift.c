#include<stdio.h>
#include<stdlib.h>

typedef struct dataNode {
    int id;
} DataNode;

typedef struct node {
    DataNode data;
    struct node* next;
} Node;

typedef struct List {
    int size;
    Node *head;
} List;


List *createList() {
    List *list = (List *) malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;

    return list;
}

/* cria um nó no começo */
void unshift(List *list, DataNode data) {
    Node *node = (Node *) malloc(sizeof(Node)); /* aloca o espaço para o nó */

    node->data = data;          /* cria um dado para o nó               */
    node->next = list->head;    /* torna o próximo nó o cabeça da lista */
    list->head = node;          /* torna a cabeça da lista em nó        */
    list->size++;               /* incrementa o tamanho da lista        */
}

int main() {
    List* l = createList();

    DataNode data;
    data.id = 5;

    unshift(l, data);

    data.id = 9;
    unshift(l, data);

    data.id = 10;
    unshift(l, data);

    data.id = 2;
    unshift(l, data);
    printList(l);

    return 0;
}