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
    printf("\n");
}


void shift(List *list) {
    if(!isEmpty(list)) {
        Node *pointer = list->head;
        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}


Node *atPos(List *list, int index) {
    if(index >= 0 && index < list->size) {
        Node *node = list->head;

        int i;
        for(i = 0; i < index; i++) {
            node = node->next;
        }

        return node;
    }

    printf("Indice Invalido\n");

    return NULL;
}


int indexOf(List *list, Node *node) {
    if(node != NULL) {
        Node *pointer = list->head;
        int index = 0;

        while(pointer != node && pointer != NULL) {
            pointer = pointer->next;
            index++;
        }
        if(pointer != NULL) {
            return index;
        }
    }

    printf("No nao pertence a lista\n");
    return -1;
}


void erase(List *list, int index) {
    if(index == 0) {
        shift(list);
    } else {
        Node *current = atPos(list, index);
        if(current != NULL) {
            Node *previous = atPos(list, index - 1);
            previous->next = current->next;

            free(current);
            list->size--;
        }
    }
}


void insert(List *list, DataNode data, int index) {
    if(index == 0) {
        unshift(list, data);
    } else {
        Node *current = atPos(list, index);

        if(current != NULL) {
            Node *previous = atPos(list, index - 1);
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->data = data;

            previous->next = newNode;
            newNode->next = current;
            list->size++;
        }
    }
}


/* inverte dois nós */
void xchgNodes(List *list, Node *nodeA, Node *nodeB) {
    
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