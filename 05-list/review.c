#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
Uma lista ligada corresponde a uma sequencia lógica de entradas (nós)
Geralmente, o topo (primeiro elemento) e eventualmente o fim da lista sejam conhecidos
Cada nó armazena a localização de seu nó sucessor; logo, o armazenamento da lista não requer uma área contígua de memória
Representação de lista ligada:
    topo -> chave
            prox -> chave
            NÓ      prox -> chave
                    NÓ      prox -> chave
                            NÓ      prox -> ...
                                    NÓ

Um nó é uma estrutura com dois campos de interesse:
- chave: conteúdo do nó
- prox: referência para o próximo nó
Ainda podem haver outros campos

O topo deve ser registrado à parte da lista, em um nó descritivo
O último nó geralmente possuirá prox nulo
*/

/*
lista é uma sequência de elementos do mesmo tipo
seus elementos possuem estrutura interna abstraída
sua complexidade é arbitrária e não afeta o seu funcionamento

uma lista pode possui N elementos (N >= 0)
N = 0 -> lista vazia

Aplicaçoes
- cadastro de funcionarios
- estoque

Podemos realizar as seguintes operações basicas em uma listas:
- criação da listas
- inserção de um elemento
- exclusão de um elemento
- acesso a um elementos
- destruição da lista
- etc

As operações dependem do tipo de alocacao de memoria usada

Alocação estática
- espaço alocada na compilação
- exige definição do numero máximo de elementos
- acesso sequencial -> elementos consecutivos na memória
Ex: vetor

Alocação dinâmica
- espaço alocado em tempo de execução
- cresce e diminui conforme os elementos são adicionados ou removidos
- acesso encadeado, pois cada elemento pode estar em uma área diferente da memória
- para acessar um elemento, é preciso percorrer todos os seus antecessores
        topo -> chave
                prox -> chave
                NÓ      prox -> chave
                        NÓ      prox -> chave
                                NÓ      prox -> NULL
                                        NÓ
*/