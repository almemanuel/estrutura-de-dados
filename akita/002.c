#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node *previous; /* aponta ao nó anterior */
};


struct Node* createNode(int value, struct Node *previous) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->value = value;
    if(previous) {
        node->previous = previous;
    }
    return node;
}


int main() {
    struct Node *first = createNode(2020, NULL);
    struct Node *second = createNode(2021, first);
    struct Node *third = createNode(2022, second);

    struct Node *iterator = third;
    while(iterator) {
        printf("%i, ", iterator->value);
        iterator = iterator->previous;
    }

    return 0;
}

/*
um node ligado a outro node cria uma lista ligada
ela permite fazer várias tarefas com menor custo
*/