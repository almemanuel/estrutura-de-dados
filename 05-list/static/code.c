#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"static.h"

/*
O sucessor de um elemento ocupa a posição física do mesmo (uso de array)

qtd = 4 ----------------
                        |
                        v
chave:   33 | 23 | 16 |   |   |     |
pos:      0 | 1  |  2 | 3 |   |max-1|

Vantagens:
- acesso rápido e direto via índice
- tempo constante para acessar um elemento
- facilidade em modificar informações

Desvantagens:
- definição prévia do tamanho
- dificuldade para inserir e remover um elemento entre outros dois
        é necessário deslocar os elementos
Ex: inserir 12 após o 33 e depois excluir:
inicio:
chave:  | 33 | 23 | 16 |    |   |     |
indice: | 00 | 01 | 02 | 03 |...|max-1|

inserir: desloca 23 e 16 para os indices 02 e 03 e adiciona 12 ao segundo indice 01
chave:  | 33 | 12 | 23 | 16 |   |     |
indice: | 00 | 01 | 02 | 03 |...|max-1|
Logo, movimenta todos os itens adiante para uma posição, para que o espaço desejado possa ser ocupado sem perder dados

remover: aloca 23 e 16 para os indices 01 e 02 e torna o indice 03 nulo
chave:  | 33 | 12 | 23 | 16 |   |     |
indice: | 00 | 01 | 02 | 03 |...|max-1|
Logo, movimenta-se todos os itens de indice superior ao excluído uma posição para trás

Util:
- listas pequenas
- inserção e remoção apenas ao final
        Existem 3 tipos de inserção
                - no início (inserção em lista vazia é sempre no inicio)
                - no meio
                - no final
- tamanho maximo bem definido
- busca sendo a operação mais frequente
*/

int main() {
        Lista *li = cria_lista();
        printf("%p ", li);

        int x = tamanho_lista(li);
        printf("%i ", x);

        x = lista_cheia(li);
        printf("%i ", x);

        x = lista_vazia(li);
        printf("%i ", x);

        libera_lista(li);

        return 0;
}
