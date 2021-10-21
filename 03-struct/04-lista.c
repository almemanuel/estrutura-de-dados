/*************************************************************************************************
Implemente uma estrutura de dados que permita o armazenamento de uma lista de até 100 inteiros.
Para isso utilize uma estrutura composta por um vetor estático de tamanho 100, e um inteiro que
representa a quantidade de elementos guardados nele em um dado momento. Em seguida implemente
as seguintes operações (através de funções):
- Adicionar: adiciona um elemento ao vetor. Caso a lista não tenha capacidade para armazenar esse
elemento adicional (ou seja, já esteja guardando 100 inteiros) o programa deve imprimir a mensagem
“ERRO: LISTA CHEIA!”.
- nElementos: retorna a quantidade de elementos guardados na lista.
- Remover: dado um número inteiro, remove o mesmo da lista. Se a lista não contiver este número
inteiro o programa deve imprimir a mensagem “ERRO: ELEMENTO NÃO ENCONTRADO!”.
- Imprimir: Imprime os números guardados.
*************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int lista[100];
    int quantidade;
} Lista;

void adiciona(Lista *lista, int x);
int nElementos(Lista *lista);
void remover(Lista *lista, int x);
void imprime(Lista *lista);

int main() {
    Lista lista;
    lista.quantidade = 0;
    int opc;
    do {
        printf("MENU\n\t1 - Adicionar Elemento\n\t2 - Quantidade de Elementos\n\t3 - Remover um Elemento\n\t4 - Imprimir\n\t0 - Sair\nInforme uma das opções acima: ");
        scanf("%i", &opc);

        switch(opc) {
            case 1:
            {
                int x;
                printf("Informe um numero inteiro para adicionar a lista: ");
                scanf("%i", &x);
                adiciona(&lista, x);
            } break;

            case 2:
                printf("%i\n", nElementos(&lista));
            break;

            case 3:
            {
                int x;
                printf("Informe um numero inteiro para remover da lista: ");
                scanf("%i", &x);
                remover(&lista, x);
            } break;

            case 4:
                imprime(&lista);
            break;

            case 0:
            {
                printf("FIM\n");
            } break;

            default:
                printf("Informe uma opcao valida!\n");
        }
    } while(opc != 0);

    return 0;
}


void adiciona(Lista *lista, int x) {
    if (lista->quantidade < 100) {
        lista->lista[lista->quantidade] = x;
        lista->quantidade++;
        printf("SUCESSO!\n");
        return;
    }
    printf("LISTA CHEIA!\n");
    return;
}


int nElementos(Lista *lista) {
    return lista->quantidade;
}


void remover(Lista *lista, int x) {
    if(lista->lista[lista->quantidade] == x) {
        lista->quantidade--;
    }

    int i;
    for(i = 0; i < lista->quantidade; i++) {
        if(lista->lista[i] == x) {
            while(i < lista->quantidade) {
                lista->lista[i] = lista->lista[i + 1];
                i++;
            }
            lista->quantidade--;
        }
    }
}


void imprime(Lista *lista) {
    if(lista->quantidade == 0) {
        printf("LISTA VAZIA!\n");
        return;
    }
    for(int i = 0; i < lista->quantidade; i++) {
        printf("%i ", lista->lista[i]);
    }
    printf("\n");
}

