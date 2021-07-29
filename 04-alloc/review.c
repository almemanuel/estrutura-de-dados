#include<stdio.h>
#include<stdlib.h>

int main() {
/*
Quando declaramos variáveis da forma abaixo, o programa aloca espaço na memória para as variáveis antes do
programa ser executado. Esta é a alocação estática
*/
    char c;
    int i;
    int v[10];
/*
A alocação dinâmica permite alocar espaço de acordo com o tamanho necessário.
Ela utiliza a biblioteca stdlib.h e algumas funções famosas são malloc, realloc e free
*/

/*
A função malloc (memory allocation) aloca um bloco de bytes consecutivos da memória RAM e
devolve o endereço deste bloco
sua sintaxe é malloc(size)
*/
    char *ptr;
    ptr = malloc(1); // aloca 1 byte
    scanf("%c", ptr); // le um valor para armazenar no endereço alocado
    printf("%p %c\n", ptr, *ptr); // imprimi o endereço e o conteudo do endereço
/*
o endereço devolvido por malloc é um genérico (void *), que deve ser armazenado em um tipo apropriado
através de um casting. No caso acima, a segunda linha deveria ser ptr = (char *) malloc(1)

Para facilitar, o operador sizeof(data) ajuda a informar o tamanho em malloc
*/
    typedef struct {
        int dia, mes, ano;
    } data;
    data *d; // declaração de ponteiro do tipo definido
    d = (data *) malloc(sizeof(data)); // alocação de um endereço para d
    d->dia = 31; d->mes = 12; d->ano = 2016; // dados de d
    printf("%i/%i/%i", d->dia, d->mes, d->ano);

/*
variáveis estáticas desaparecem assim que a execução termina
variáveis alocadas existem mesmo após a execução
para liberar este espaço, recorremos a função free(ptr)
ela desaloca a porção alocada por malloc, avisando ao sistema que o bloco de bytes ocupado por ptr está disponível
*/

    return 0;
}