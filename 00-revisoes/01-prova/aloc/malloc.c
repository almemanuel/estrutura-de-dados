#include<stdio.h>
#include<stdlib.h>

int main() {
    /****************************************************************************************************************************************/
    /* o sistema operacional aloca automaticamente o espaço necessário para armazenar as variáveis, mas exitem meios que nos permitem       */
    /* alocar um bloco em um determinado tamanho. um deles é a função malloc, onde informamos o espaço que desejamos que o ponteiro aponte. */
    /* PS: Sempre usar o cast antes do mallo, pois, sem ele, será retornado o tipo de dado void, que pode trazer problemas                  */
    /****************************************************************************************************************************************/
    int *p = (int *) malloc(sizeof(int));       /* aloca a quantidade de bytes necessária para um determinado tipo de dado                  */
    int *pv = (int *) malloc(4 * sizeof(int));  /* aloca a quantidade de bytes necessário para um vetor de n elementos de um tipo de dado   */

    if(p == NULL ) {                /********************************************************************************************************/
        printf("ERROR");            /* antes de utilizar o espaço, é importante verificar se ele realmente foi alocado. quando isso ocorre, */
    } else {                        /* a função malloc retornará NULL, que significa que o espaço solicitado não estava disponível na RAM   */
        *p = 1000;                  /* caso tenha espaço, quando o endereço for acessado, o ponteiro apontará diretamente a ele             */
        printf("%i", *p);           /* exit: 1000                                                                                           */
    }                               /********************************************************************************************************/

    return 0;
}