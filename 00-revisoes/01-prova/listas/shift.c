#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


/* retorna se a lista está vazia ou não */
bool isEmpty(List *list) {
    return (list->size == 0);
}


void printList(List *list) {
    if(isEmpty(list)) {
        printf("Lista vazia\n");
        return;
    }

    Node *pointer = list->head;

    while(pointer != NULL) {
        printf("%i ", pointer->data.id);
        pointer = pointer->next;
    }
}

/* remove o primeiro item   */
void shift(List *list) {
    if(!isEmpty(list)) {
        Node *pointer = list->head;
        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}


int main() {
    List* l = createList();

    DataNode data;
    data.id = 5;

    unshift(l, data);

    data.id = 9;
    unshift(l, data);

    printList(l);

    shift(l);
    printList(l);

    return 0;
}