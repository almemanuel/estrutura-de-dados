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


void unshift(List *list, DataNode data) {
    Node *node = (Node *) malloc(sizeof(Node));

    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}

/* imprime a lista  */ /* foi atualizado */
void printList(List *list) {
    Node *pointer = list->head; /* ponteiro que aponta para a cabeça da listas  */

    if(pointer == NULL) {       /* quando o ponteiro nao aponta para endereço algum significa que a lista chegou está vazia */
        printf("Lista vazia");
    }

    while(pointer != NULL) {    /* ou, nesse caso, a posição já nao pertence a lista    */
        printf("%i ", pointer->data.id);
        pointer = pointer->next;
    }
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