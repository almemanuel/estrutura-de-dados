#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

- para remover um elemento do inicio da lista, é necessário deslocar todos os elementos uma posição para trás
- para remover no meio, é necessário encontrar o indice do elemento e deslocar os elementos seguintes uma posição para trás
- qtd deve ser decrementado
- não se pode remover de uma lista vazia

Existem 2 formas de consultar uma lista:
- posição -> acesso direto
- conteúdo -> necessidade de busca
*/


/*
Dada uma lista sequencial estática L1, referente aos alunos matriculados em uma determinada
disciplina, elabore em C funções que resolvam os problemas especificados abaixo.
Cada “célula” da lista deve conter as seguintes informações:
- número de matrícula do aluno (inteiro),
- nome do aluno (char)
- média das notas obtidas pelo aluno (float).
Assuma que o número máximo de alunos matriculados na disciplina é 50.

1. Verificar se L1 está ordenada ou não, considerando o número de matrícula como
critério de ordenação (caso a lista esteja ordenada, especificar se a ordem é
crescente ou decrescente).

2. Fazer uma cópia da lista L1 em outra lista L2.

3. Fazer uma cópia da lista L1 em L2, verificando e eliminando possíveis repetições
de células com o mesmo número de matrícula.
As células com números de matrícula repetidos devem ser armazenadas em uma terceira lista L3
(obs.: a lista L2 não deve possuir nenhuma cópia dos elementos repetidos).

4. Inverter L1 colocando o resultado em L2.

5. Inverter L1 colocando o resultado na própria L1.

6. Intercalar duas listas L1 e L2, gerando uma lista L3.

7. Eliminar de L1 todas as ocorrências de um elemento dado. Para isso, a função deve
receber o número de matrícula do aluno que será retirado da lista dos alunos da
disciplina.

8. Inserir um novo aluno na lista ordenada L1. Os dados do aluno deverão ser
fornecidos pelo usuário. Realizar a inserção de forma a manter a lista ordenada.

9. Calcular a média das notas obtidas por todos os alunos e definir quantos destes
alunos estão acima da média e quantos estão abaixo.
*/
int main() {
        Lista *L1 = cria_lista();

        /* insercao */
        aluno al;
        al.matricula = 12345;
        strcpy(al.nome, "joaozinho");
        al.media = 5.1;
        insere_lista_inicio(L1, al);
        al.matricula = 13210;
        strcpy(al.nome, "aninha");
        al.media = 9;
        insere_lista_inicio(L1, al);
        al.matricula = 12346;
        strcpy(al.nome, "mirto");
        al.media = 2.1;
        insere_lista_crescente(L1, al);
        al.matricula = 12345;
        strcpy(al.nome, "ricardo");
        al.media = 5.1;
        insere_lista_final(L1, al);
        al.matricula = 00001;
        strcpy(al.nome, "maria");
        al.media = 10;
        insere_lista_inicio(L1, al);
        al.matricula = 54321;
        strcpy(al.nome, "dinho");
        al.media = 0.1;
        insere_lista_crescente(L1, al);

        imprime_lista(L1);

        /* parte 1 */
        int ordem = ordem_lista(L1);
        if(ordem == 1) {
                printf("\nordem crescente\n");
        } else if(ordem == -1) {
                printf("\nordem crescente\n");
        } else {
                printf("\nsem ordem definida\n");
        }

        /* parte 2 */
        Lista *L2 = cria_lista();
        copia_lista(L2, L1);
        imprime_lista(L2);

        return 0;
}
