#include<stdio.h>
#include<stdlib.h>

int main() {                                /********************************************************************************************/
    int *p;                                 /* calloc recebe a quantidade de espaços e o tamanho do espaço de memória requisitado ao SO */
    p = (int *) calloc(5, sizeof(int));     /* pode ser muito util para alocar vetores. Além disso, ela inicia o valor do enreço como 0 */
                                            /********************************************************************************************/
    printf("%i", *p);   /* exit: 0  */

    int i;
    for(i = 0; *(p + i) == 0; i++) {        /* malloc sempre retornar um valor que é resultado de uma potencia 2ˆn  */
        *(p + i) = i + 1;
        printf("\n%i", *(p + i));
    }

    return 0;
}