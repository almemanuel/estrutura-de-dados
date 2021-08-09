#include <stdio.h>
#include<stdlib.h>

/* tamanho máximo da lista */
#define MAX 50

/* estrutura de cada nó da lista
cada nó armazenará um tamanho inteiro */
typedef struct no {
    int chave;
} No;


/* estrutura que define a lista
- quantidade armazena o número de elementos e, consequentemente, a primeira posição vaga
    Ex: qtd=10 -> de 0 a 9 (10 nós) existe algum valor armazenado para o respectivo indice em dados
    sendo que, o espaço que receberá o próximo valor será dados[qtd]
- dados[max] é um vetor que armazena o conteúdo de cada nó, sendo possível armazenar até o indice MAX-1 */
typedef struct lista {
    int qtd;
    No dados[MAX];
} Lista;


/* Função que cria e retorna uma lista vazia
ela definirá o valor de lista->qtd = 0, pois, como foi recém criada,
ainda está vazia, e, após isso, retornará a lista para o programa principal */
Lista *cria_lista() {
    Lista *lista;
    lista = (Lista *) malloc(sizeof(Lista));

    if(lista != NULL)
        lista->qtd = 0;
    return lista;
}


/* função que libera uma lista */
void libera_lista(Lista *lista) {
    free(lista);
    lista = NULL;
}


/* função que retorna o tamanho de uma lista
-1 -> lista nula */
int tamanho_lista(Lista *lista) {
    if(lista == NULL)
        return -1;
    else
        return lista->qtd;
}


/* função que diz se a lista está cheia ou não
-1 -> lista nula
0 -> listá não está cheia
1 -> lista cheia */
int lista_cheia(Lista *lista) {
    if(lista == NULL)
        return -1;
    return(lista->qtd == MAX);
}


/* função que diz se a lista está vazia ou não
-1 -> lista nula
0 -> listá não está vazia
1 -> lista vazia */
int lista_vazia(Lista *lista) {
    if(lista == NULL)
        return -1;
    return (lista->qtd == 0);
}


/* procedimento que insere um novo nó ao fim da lista caso esta não seja nula nao esteja cheia
e, consequentemente, incrementa a quantidade de nós na lista */
void insere_lista_final(Lista *lista, No no) {
    if(lista == NULL) printf("nao eh possivel adicionar um no a uma lista nula\n");
    if(lista_cheia(lista)) printf("nao eh possivel adicionar um no a uma lista cheia\n");

    lista->dados[lista->qtd] = no;
    lista->qtd++;
}


/* procedimento que insere um novo nó ao inicio da lista caso esta não seja nula nao esteja cheia
e, consequentemente, incrementa a quantidade de nós na lista
o procedimento desloca todos os dados para o indice a sua frente e, então, adiciona o nó no inicio */
void insere_lista_inicio(Lista *lista, No no) {
    if(lista == NULL) printf("nao eh possivel adicionar um no a uma lista nula\n");
    if(lista_cheia(lista)) printf("nao eh possivel adicionar um no a uma lista cheia\n");

    int i;
    for(i = lista->qtd - 1; i>=0; i--)
        lista->dados[i + 1] = lista->dados[i];
    lista->dados[0] = no;
    lista->qtd++;
}



/* retorna o tipo de ordenação da lista
0 -> lista nula ou sem tipo de ordem especifica
-1 -> decrescente
1 -> crescente */
int ordem_lista(Lista *lista) {
    if(lista_vazia(lista)) return 0;

    int i = 0;
    while(i < lista->qtd - 1 && lista->dados[i].chave < lista->dados[i + 1].chave)
        i++;
    if(i == lista->qtd - 1) return 1;

    i = 1;
    while(i < lista->qtd - 1 && lista->dados[i].chave > lista->dados[i + 1].chave)
        i++;
    if(i == lista->qtd - 1) return -1;

    return 0;
}


void ordena_crescente(Lista *lista) {
    if(lista_vazia(lista)) return;
    if(ordem_lista(lista) != 1) {
        int j, i = 0;
        No aux;

        for(i = 0; i < lista->qtd - 1; i++) {
            for(j = 0; j < lista->qtd - 1; j++) {
                if(lista->dados[j].chave > lista->dados[j + 1].chave) {
                    aux = lista->dados[j];
                    lista->dados[j] = lista->dados[j + 1];
                    lista->dados[j + 1] = aux;
                }
            }
        }
    }
}


void ordena_decrescente(Lista *lista) {
    if(lista_vazia(lista)) return;
    if(ordem_lista(lista) != -1) {
        int j, i = 0;
        No aux;

        for(i = 0; i < lista->qtd - 1; i++) {
            for(j = 0; j < lista->qtd - 1; j++) {
                if(lista->dados[j].chave < lista->dados[j + 1].chave) {
                    aux = lista->dados[j];
                    lista->dados[j] = lista->dados[j + 1];
                    lista->dados[j + 1] = aux;
                }
            }
        }
    }
}


void insere_lista_crescente(Lista *lista, No no) {
    if(lista == NULL) printf("nao eh possivel adicionar um no a uma lista nula\n");
    if(lista_cheia(lista)) printf("nao eh possivel adicionar um no a uma lista cheia\n");
    ordena_crescente(lista);
    insere_lista_final(lista, no);
}


void insere_lista_decrescente(Lista *lista, No no) {
    if(lista == NULL) printf("nao eh possivel adicionar um no a uma lista nula\n");
    if(lista_cheia(lista)) printf("nao eh possivel adicionar um no a uma lista cheia\n");
    ordena_decrescente(lista);
    insere_lista_inicio(lista, no);
}


/* procedimento que remove o ultimo elemento da lista e decrementa qtd */
void remove_lista_final(Lista *lista) {
    if(lista == NULL) printf("nao eh possivel remover um no a uma lista nula\n");
    if(lista->qtd == 0) printf("nao eh possivel remover de uma lista vazia\n");

    lista->qtd--; /* tornará a posição final vaga */
}


/* procedimento que remove o primeiro elemento da lista, desloca todos os nós
uma posição para trás e decrementa qtd */
void remove_lista_inicio(Lista *lista) {
    if(lista == NULL) printf("nao eh possivel remover um no a uma lista nula\n");
    if(lista->qtd == 0) printf("nao eh possivel remover de uma lista vazia\n");

    int i;
    for(i = 0; i < lista->qtd - 1; i++)
        lista->dados[i] = lista->dados[i + 1];
    lista->qtd--;
}


/* procedimento que remove um nó de acordo com sua chave, desloca todos os nós a frente
do que possui a chave correspondente uma posição para trás e decrementa qtd */
void remove_chave(Lista *lista, int chave) {
    if(lista == NULL) printf("nao eh possivel remover um no a uma lista nula\n");
    if(lista->qtd == 0) printf("nao eh possivel remover de uma lista vazia\n");

    int k, i = 0;
    for(i = 0; i < lista->qtd; i++) {
        if(lista->dados[i].chave == chave) {
            for(k = i; k < lista->qtd; k++) {
                lista->dados[k] = lista->dados[k + 1];
                lista->qtd--;
            }
        }
    }
}


void remove_pos(Lista *lista, int pos) {
    if(lista == NULL) printf("nao eh possivel remover um no a uma lista nula\n");
    if(lista->qtd == 0) printf("nao eh possivel remover de uma lista vazia\n");

    int i = 0;
    for(i = pos; i < lista->qtd; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->qtd--;
}


void exclui_repeticoes(Lista *lista) {
    if(lista_vazia(lista)) return;

    int i, j;
    No aux;
    for(i = 0; i < lista->qtd; i++) {
        j = 0;
        for(j = i + 1; j < lista->qtd; j++) {
            if(lista->dados[i].chave == lista->dados[j].chave) {
                remove_pos(lista, j);
                j--;
            }
        }
    }
}


/* função que retorna o elemento de uma posição */
No consulta_lista_pos(Lista *lista, int pos) {
    if(lista == NULL || pos <= 0 || pos > lista->qtd) exit(-1);
    return lista->dados[pos - 1];
}


/* função que retorna a posição de uma determinada chave
-1 -> chave não encontrada */
int consulta_lista_chave(Lista *lista, int chave) {
    if(lista == NULL) return -1;

    int k, i = 0;
    while(i < lista->qtd && lista->dados[i].chave != chave)
        i++;

    if(i == lista->qtd) return -1;
    return i;
}


/* procedimento que imprime uma lista */
void imprime_lista(Lista *lista){
    if(!lista_vazia(lista)) {
        int i;
        for(i = 0; i < lista->qtd; i++)
            printf("%i ", lista->dados[i].chave);
    }
}


/* função que copia uma lista */
Lista *copia_lista(Lista *lista) {
    if(lista_vazia(lista)) exit(-1);

    Lista *nova = cria_lista();

    int i;
    for(i = 0; i < lista->qtd; i++) {
        insere_lista_final(nova, lista->dados[i]);
    }
    return nova;
}


/* procedimento que inverte os elementos da lista
para isso, foi usado a aritmética de que seria necessário movimentar apenas até metade da lista
dentro, foi utilizado um nó auxiliar, e outras duas variáveis de controles: uma decrescendo do ultimo indice
preenchido e outra crescendo de 0 */
void inverte_lista(Lista *lista) {
    if(lista_vazia(lista)) return;

    No aux;
    int i;
    int j = lista->qtd - 1;
    for(i = 0; i < (lista->qtd - 1) / 2; i++) {
        aux = lista->dados[j];
        lista->dados[j] = lista->dados[i];
        lista->dados[i] = aux;
        j--;
    }
}


/* Teste essenciais */
int main() {
    Lista *lista1 = cria_lista();
    Lista *lista2 = cria_lista();
    No testando;
    testando.chave = 0;
    insere_lista_final(lista1, testando);
    testando.chave = 1;
    insere_lista_inicio(lista1, testando);
    testando.chave = 2;
    insere_lista_final(lista1, testando);
    testando.chave = 3;
    insere_lista_inicio(lista1, testando);
    testando.chave = 4;
    insere_lista_inicio(lista1, testando);
    testando.chave = 5;
    insere_lista_final(lista1, testando);
    imprime_lista(lista1);
    printf("\n");

    testando.chave = 6;
    insere_lista_crescente(lista1, testando);
    imprime_lista(lista1);
    printf("\n");

    testando.chave = 7;
    insere_lista_decrescente(lista1, testando);
    imprime_lista(lista1);
    printf("\n");

    remove_chave(lista1, 0);
    imprime_lista(lista1);
    printf("\n");

    remove_pos(lista1, 1);
    imprime_lista(lista1);
    printf("\n");

    testando.chave = 7;
    insere_lista_final(lista1, testando);
    testando.chave = 10;
    insere_lista_final(lista1, testando);
    testando.chave = 10;
    insere_lista_final(lista1, testando);
    testando.chave = 10;
    insere_lista_final(lista1, testando);
    imprime_lista(lista1);
    printf("\n");

    exclui_repeticoes(lista1);
    imprime_lista(lista1);
    printf("\n");

    libera_lista(lista1);
}

