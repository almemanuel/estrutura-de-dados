/********************************************************************************************************************************************/
/* Uma lista é representada pelo tamanho atual da lista (quantidade de nós) e um ponteiro para o primeiro nó (nó-cabeça), que pode ser um   */
/* nó alocado ou um nó vazio. Algumas operações importantes serão                                                                           */
/*      List* createList()                                                                                                                  */
/*      void push(List* list, DataNode data)                                                                                                */
/*      void pop(List* list)                                                                                                                */
/*      void insert(List* list, DataNode data, int index)                                                                                   */
/*      void erase(List* list, int index)                                                                                                   */
/*      bool isEmpty(List* list)                                                                                                            */
/*      int indexOf(List* list, Node* node)                                                                                                 */
/*      Node* atPos(List* list, int index)                                                                                                  */
/*      int min(List* list, int index)                                                                                                      */
/*      void xchgNodes(List* list, Node* nodeaA, Node* nodeB)                                                                               */
/*      void sort(List* list)                                                                                                               */
/*      void printList(List* list)                                                                                                          */
/********************************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/* Definindo a estrutura dos nós dos dados  */
typedef struct dataNode {
    int id;
} DataNode;

/* Definindo a estrutura do nó  */
typedef struct node {
    DataNode data;
    struct node* next; /* recursão que faz apontar para o mesmo tipo dela   */
} Node;

/* Definindo a estrutura da Lista   */
typedef struct List {
    int size;
    Node *head;
} List;


List *createList() {                            /********************************/
    List *list = (List *) malloc(sizeof(List)); /* cria um ponteiro dinamico    */
                                                /*                              */
    list->size = 0;                             /* tamanho da lista             */
    list->head = NULL;                          /* inicio da listas             */
                                                /*                              */
    return list;                                /* Após criar, retorna a lista  */
}                                               /********************************/

int main() {
    List* lista = createList();

    printf("%i", lista->size);
    /* exit: 0  */

    return 0;
}