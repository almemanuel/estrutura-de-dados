#include<stdio.h>
#include<stdlib.h>

int main() {
    int *p = (int *) malloc(sizeof(int));
    *p = 1000;
    printf("%i", *p);   /* exit: 1000   */

    free(p);    /* a função free desaloca o espaço, mas mantém os dados */

    return 0;
}